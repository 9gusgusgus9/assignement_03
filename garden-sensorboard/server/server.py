from flask import Flask, request
app = Flask(__name__)

"""@app.route('/temperature', methods=['POST'])
def getTemperature():
   return getData()

@app.route('/light', methods=['POST'])
def getLight():
   return getData()

def getData():
   data = request.json["value"]
   return data
"""

@app.route('/data', methods=['POST'])
def getData():
   temperature = request.json["temperature"]
   luminosity = request.json["luminosity"]
   print("Temperature: " + temperature + " Luminosity: " + luminosity)
   status = "AUTO"
   return status

if __name__ == '__main__':
   app.run('0.0.0.0', port=5000)
   