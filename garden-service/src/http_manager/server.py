from flask import Flask, request, send_from_directory
import sys
import os
import inspect
currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)
from manifest.garden_manifest import Manifest
from garden_status.status import *

app = Flask(__name__)

manifest = Manifest()

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
         manifest.setControllerLedOn()
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
      manifest.setControllerLedOn()
      """
      if manifest.getTemperature() < 5:
         manifest.setGardenStatus(GardenStatus.AUTO)
      """

if __name__ == '__main__':
   app.run('0.0.0.0', port=5000)
   