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
        #Bisogna importare la velocita dell'irrigatore
    
    def getSensorboardLed(self):
        return self.sensorboardLed

    def setSensorboardLed(self, status):
        self.sensorboardLed = status

    def setControllerLedOn(self, value):
        self.controllerLed1 = LedStatus.ON
        self.controllerLed2 = LedStatus.ON
        self.controllerLed3 = LedWithIntensityStatus.fromValue(int(value))
        self.controllerLed4 = LedWithIntensityStatus.fromValue(int(value))
        #bisogna impostare i valori di led 3 e 4

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

    def getIrrigatorSpeed(self):
        return 0
        #Bisogna importare la velocita dell'irrigatore
    