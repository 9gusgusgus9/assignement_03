import serial
import sys
import os
import inspect
currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)
from manifest.garden_manifest import Manifest

class SerialComunicator:
    def __init__(self, port, baudrate):
        self.port = port
        self.baudrate = baudrate
        self.ser = serial.Serial(port=self.port, baudrate=self.baudrate)

    def write(self, data):
        self.ser.write(data.encode())

    def read(self):
        return self.ser.readline()

    def close(self):
        self.ser.close()
    
    def comunicate(self, manifest):
        manifest.getTemperature()
        msg = manifest.getGardenStatus().toString() + ":" + manifest.getControllerLed1().toString() + ":" + manifest.getControllerLed2().toString() + ":" + manifest.getControllerLed3().toString() + ":" + manifest.getControllerLed4().toString() + ":" + str(manifest.getControllerLed3().toInt()) + ":" + str(manifest.getControllerLed4().toInt()) + ":" + manifest.getIrrigatorStatus().toString() + ":" + str(manifest.getIrrigatorIntensity().toInt()) +"\n"
        print(msg)
        self.write(msg)