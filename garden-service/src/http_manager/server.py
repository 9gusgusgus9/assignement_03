from flask import Flask, request, send_from_directory, Response
import sys
import os
import inspect
import json
import redis
import time
currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)
from manifest.garden_manifest import Manifest
from garden_status.status import *
from serial_comunicator.serial_comunicator import SerialComunicator
from threading import Thread

app = Flask(__name__)
db = redis.Redis("redis")
manifest = Manifest()
serial = SerialComunicator("COM7", 9600)

@app.route('/gardenStatus', methods=['GET'])
def getGardenStatus():
   return Response(
        json.dumps({
            "status": manifest.getGardenStatus().toString(),
            "temperature": manifest.getTemperature(),
            "light": manifest.getLuminosity(),
            "led1": manifest.getControllerLed1().toString(),
            "led2": manifest.getControllerLed2().toString(),
            "led3": manifest.getControllerLed3().toInt(),
            "led4": manifest.getControllerLed4().toInt(),
            "irrigator_status": manifest.getIrrigatorStatus().toString(),
            "irrigator_speed": manifest.getIrrigatorIntensity().toInt()
        }),
        mimetype='application/json',
        status=200
    )


@app.route('/')
def serve_dashboard():
    return send_from_directory('../../../garden-dashboard', 'index.html')

@app.route('/data', methods=['POST'])
def getData():
   temperature = request.json["temperature"]
   manifest.setTemperature(temperature)
   luminosity = request.json["luminosity"]
   manifest.setLuminosity(luminosity)
   compute()
   return manifest.getSensorboardLed().toString()

@app.route('/dashboard/<path:path>')
def get_dashboard_files(path):
    return send_from_directory('../../../garden-dashboard', path)

@app.route("/status")
def getStatus():
   return manifest.getGardenStatus().toString()

def compute():
   if manifest.getGardenStatus() == GardenStatus.AUTO:
      manifest.setSensorboardLed(LedStatus.ON)
      #Luminosity controls
      luminosity = manifest.getLuminosity()
      checkLuminosity(luminosity)
      if luminosity < 2 :
         if manifest.getIrrigatorStatus() == IrrigatorStatus.CLOSED:
            manifest.setIrrigatorStatus(IrrigatorStatus.OPEN)
      else:
         manifest.setIrrigatorStatus(IrrigatorStatus.CLOSED)
      manifest.setIrrigatorIntensity(manifest.getTemperature())
      #Temperature controls
      if manifest.getTemperature() == 5 and manifest.getIrrigatorStatus() == IrrigatorStatus.CLOSED:
         print("Temperature is too high")
         manifest.setGardenStatus(GardenStatus.ALARM)
   
   if manifest.getGardenStatus() == GardenStatus.ALARM:
      manifest.setSensorboardLed(LedStatus.OFF)
      manifest.setIrrigatorStatus(IrrigatorStatus.CLOSED)
      checkLuminosity(manifest.getLuminosity())
   try:
      lastStamp == 0
   except:
      lastStamp = 0
   if time.time()*1000 - lastStamp > 1000:
      serial.comunicate(manifest)
      lastStamp = time.time()*1000

def checkLuminosity(luminosity):
   if luminosity < 5:
      if luminosity == 4:
         manifest.setControllerLed1(LedStatus.ON)
         manifest.setControllerLed2(LedStatus.ON)
         manifest.setControllerLed3(LedWithIntensityStatus.OFF)
         manifest.setControllerLed4(LedWithIntensityStatus.OFF)
      else:
         manifest.setControllerLedOn(4 - luminosity)
   else:
      manifest.setControllerLedOff()

def loadMessage(message):
   if ":" in message:
      params = message.split(":")
      print("Parametri: ")
      print(params)
      manifest.setGardenStatus(GardenStatus.fromString(params[0]))
      manifest.setControllerLed1(LedStatus.fromString(params[1]))
      manifest.setControllerLed2(LedStatus.fromString(params[2]))
      manifest.setControllerLed3(LedWithIntensityStatus.fromString(params[5]))
      manifest.setControllerLed4(LedWithIntensityStatus.fromString(params[6]))
      manifest.setIrrigatorStatus(IrrigatorStatus.fromString(params[7]))
      manifest.setIrrigatorIntensity(int(params[8]))

def serialLoop():
   print("START SERIAL LOOP")
   while(True):
      msg = serial.read().decode().replace("\r", "").replace("\n", "")
      loadMessage(msg)
   
if __name__ == '__main__':
   lastStamp = 0
   Thread(target=serialLoop).start()
   app.run('0.0.0.0', port=5000)