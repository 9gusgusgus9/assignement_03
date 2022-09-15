import sys
import os
import inspect
currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)
from garden_status.status import *

class Manifest:

    def __init__(self):

        # Garden Status
        self.gardenStatus = GardenStatus.AUTO

        # SensorBoard status
        self.sensorboardLed = LedStatus.ON
        self.temperature = 0
        self.luminosity = 0

        # Controller Status
        self.irrigatorStatus = IrrigatorStatus.CLOSED
        self.irrigationIntensity = IrrigationIntensityStatus.INT1
        self.controllerLed1 = LedStatus.OFF
        self.controllerLed2 = LedStatus.OFF
        self.controllerLed3 = LedWithIntensityStatus.OFF
        self.controllerLed4 = LedWithIntensityStatus.OFF

    def getGardenStatus(self):
        return self.gardenStatus

    def setGardenStatus(self, status):
        self.gardenStatus = status

    def getIrrigatorStatus(self):
        return self.irrigatorStatus

    def setIrrigatorStatus(self, status):
        self.irrigatorStatus = status
    
    def setIrrigatorIntensity(self, intensity):
        self.irrigationIntensity = IrrigationIntensityStatus.fromInt(int(intensity))

    def getSensorboardLed(self):
        return self.sensorboardLed

    def setSensorboardLed(self, status):
        self.sensorboardLed = status

    def setControllerLed1(self, status):
        self.controllerLed1 = status

    def setControllerLed2(self, status):
        self.controllerLed2 = status
    
    def setControllerLed3(self, status):
        self.controllerLed3 = status
    
    def setControllerLed4(self, status):
        self.controllerLed4 = status

    def setControllerLedOn(self, value):
        self.controllerLed1 = LedStatus.ON
        self.controllerLed2 = LedStatus.ON
        self.controllerLed3 = LedWithIntensityStatus.fromValue(int(value))
        self.controllerLed4 = LedWithIntensityStatus.fromValue(int(value))

    def setControllerLedOff(self):
        self.controllerLed1 = LedStatus.OFF
        self.controllerLed2 = LedStatus.OFF
        self.controllerLed3 = LedWithIntensityStatus.OFF
        self.controllerLed4 = LedWithIntensityStatus.OFF

    def getTemperature(self):
        return self.temperature

    def getLuminosity(self):
        return self.luminosity

    def setTemperature(self, temperature):
        self.temperature = int(float(temperature))

    def setLuminosity(self, luminosity):
        self.luminosity = int(float(luminosity))

    def getControllerLed1(self):
        return self.controllerLed1

    def getControllerLed2(self):
        return self.controllerLed2

    def getControllerLed3(self):
        return self.controllerLed3
    
    def getControllerLed4(self):
        return self.controllerLed4

    def getIrrigatorIntensity(self):
        return self.irrigationIntensity
        #Bisogna importare la velocita dell'irrigatore
    