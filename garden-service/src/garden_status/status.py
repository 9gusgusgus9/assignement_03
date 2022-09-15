from enum import Enum

class GardenStatus(Enum):
    MANUAL = "MANUAL"
    AUTO = "AUTO"
    ALARM = "ALARM"

    @staticmethod
    def fromString(status):
        if status == "MANUAL":
            return GardenStatus.MANUAL
        elif status == "AUTO":
            return GardenStatus.AUTO
        elif status == "ALARM":
            return GardenStatus.ALARM

    def toString(self):
        return self.value


class IrrigatorStatus(Enum):
    PAUSED = "PAUSED"
    OPEN = "OPEN"
    CLOSED = "CLOSED"

    @staticmethod
    def fromString(status):
        if status == "PAUSED":
            return IrrigatorStatus.PAUSED
        elif status == "OPEN":
            return IrrigatorStatus.OPEN
        elif status == "CLOSED":
            return IrrigatorStatus.CLOSED
    
    def toString(self):
        return self.value

class IrrigationIntensityStatus(Enum):
    INT1 = 1
    INT2 = 2
    INT3 = 3
    INT4 = 4
    INT5 = 5

    @staticmethod
    def fromInt(intensity):
        if intensity == 1:
            return IrrigationIntensityStatus.INT1
        elif intensity == 2:
            return IrrigationIntensityStatus.INT2
        elif intensity == 3:
            return IrrigationIntensityStatus.INT3
        elif intensity == 4:
            return IrrigationIntensityStatus.INT4
        elif intensity == 5:
            return IrrigationIntensityStatus.INT5
    
    def toInt(self):
        return self.value

class LedStatus(Enum):
    ON = "ON"
    OFF = "OFF"

    @staticmethod
    def fromString(status):
        if status == "ON":
            return LedStatus.ON
        elif status == "OFF":
            return LedStatus.OFF

    def toString(self):
        return self.value

class LedWithIntensityStatus(Enum):
    INT1 = "1"
    INT2 = "2"
    INT3 = "3"
    INT4 = "4"
    INT0 = "0"
    OFF = "OFF"

    @staticmethod
    def fromValue(status):
        if status == 1:
            return LedWithIntensityStatus.INT1
        elif status == 2:
            return LedWithIntensityStatus.INT2
        elif status == 3:
            return LedWithIntensityStatus.INT3
        elif status == 4:
            return LedWithIntensityStatus.INT4
        elif status == 0:
            return LedWithIntensityStatus.INT0
        elif status == "OFF":
            return LedWithIntensityStatus.OFF
        else:
            return LedWithIntensityStatus.OFF
            
    @staticmethod
    def fromString(status):
        if status == "1":
            return LedWithIntensityStatus.INT1
        elif status == "2":
            return LedWithIntensityStatus.INT2
        elif status == "3":
            return LedWithIntensityStatus.INT3
        elif status == "4":
            return LedWithIntensityStatus.INT4
        elif status == "0":
            return LedWithIntensityStatus.INT0
        else:
            return LedWithIntensityStatus.OFF

    def toString(self):
        if self.value == "OFF" or self.value == "0":
            return self.value
        else:
            return "ON"
    
    def toInt(self):
        if self.value == "OFF":
            return 0
        else:
            return self.value