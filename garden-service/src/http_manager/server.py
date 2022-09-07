from flask import Flask, request
import sys
import os
import inspect
currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)
from manifest.garden_manifest import Manifest
from garden_status.status import *

app = Flask(__name__)

@app.route('/data', methods=['POST'])
def getData():
   temperature = request.json["temperature"]
   manifest.setTemperature(temperature)
   luminosity = request.json["luminosity"]
   manifest.setLuminosity(luminosity)
   #print("Temperature: " + temperature + " Luminosity: " + luminosity)
   return manifest.getGardenStatus().toString()

@app.route('/dashboard/<path:path>')
def get_dashboard_files(path):
    return send_from_directory('C:/Users/Gustavo/Documents/Uni/IOT/Assignement/assignement_03/garden-dashboard', path)

if __name__ == '__main__':
   app.run('0.0.0.0', port=5000)
   manifest = Manifest()
   