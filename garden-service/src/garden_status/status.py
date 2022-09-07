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