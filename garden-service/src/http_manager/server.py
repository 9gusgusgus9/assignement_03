from flask import Flask, request, send_from_directory, Response
import sys
import os
import inspect
import json
import redis
currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)
from manifest.garden_manifest import Manifest
from garden_status.status import *

app = Flask(__name__)
db = redis.Redis("redis")
manifest = Manifest()


@app.route('/gardenStatus', methods=['GET'])
def getGardenStatus():
   return Response(
        json.dumps({
            "status": manifest.getGardenStatus().toString(),
            "temperature": manifest.getTemperature(),
            "light": manifest.getLuminosity(),
            "led1": manifest.getControllerLed1().toString(),
            "led2": manifest.getControllerLed2().toString(),
            "led3": manifest.getControllerLed3().toString(),
            "led4": manifest.getControllerLed4().toString(),
            "irrigator_status": manifest.getIrrigatorStatus().toString(),
            "irrigator_speed": manifest.getIrrigatorSpeed()
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

def compute():
   if manifest.getGardenStatus() == GardenStatus.AUTO:
      manifest.setSensorboardLed(LedStatus.ON)
      #Luminosity controls
      if manifest.getLuminosity() < 5:
         manifest.setControllerLedOn(5 - manifest.getLuminosity())
         if manifest.getLuminosity() < 2 :
            if manifest.getIrrigatorStatus() == IrrigatorStatus.CLOSED:
               manifest.setIrrigatorStatus(IrrigatorStatus.OPEN)
         else:
            manifest.setIrrigatorStatus(IrrigatorStatus.CLOSED)
      else:
         manifest.setControllerLedOff()

      #Temperature controls
      if manifest.getTemperature() == 5 and manifest.getIrrigatorStatus() == IrrigatorStatus.CLOSED:
         print("Temperature is too high")
         manifest.setGardenStatus(GardenStatus.ALARM)
   
   if manifest.getGardenStatus() == GardenStatus.ALARM:
      manifest.setSensorboardLed(LedStatus.OFF)
      manifest.setIrrigatorStatus(IrrigatorStatus.CLOSED)
      manifest.setControllerLedOn(5 - manifest.getLuminosity())
      

if __name__ == '__main__':
   app.run('0.0.0.0', port=5000)
   