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
    
    def comunicate(manifest):
        manifest.getTemperature()
        write("sto comunicando")