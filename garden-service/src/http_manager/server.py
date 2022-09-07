from flask import Flask, request
from garden_manifest import Manifest
from status import GardenStatus, IrrigatorStatus
import sys

sys.path.insert(0, './../manifest')

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
    return send_from_directory('garden-dashboard', path)

if __name__ == '__main__':
   app.run('0.0.0.0', port=5000)
   manifest = Manifest()
   