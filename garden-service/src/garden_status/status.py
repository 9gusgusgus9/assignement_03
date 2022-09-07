from enum import Enum

class GardenStatus(Enum):
    MANUAL = "MANUAL"
    AUTO = "AUTO"
    ALARM = "ALARM"

    switcher = {
        "MANUAL": Status.MANUAL,
        "AUTO": Status.AUTO,
        "ALARM": Status.ALARM
    }

    @staticmethod
    def fromString(status):
        return switcher[status]

    def toString(self):
        return self.value


class IrrigatorStatus(Enum):
    READY = "READY"
    OPEN = "OPEN"
    CLOSED = "CLOSED"

    switcher = {
        "READY": IrrigatorStatus.READY,
        "OPEN": IrrigatorStatus.OPEN,
        "CLOSED": IrrigatorStatus.CLOSED
    }

    @staticmethod
    def fromString(status):
        return switcher[status]
    
    def toString(self):
        return self.value


class LedStatus(Enum):
    ON = "ON"
    OFF = "OFF"

    switcher = {
        "ON": LedStatus.ON,
        "OFF": LedStatus.OFF
    }

    @staticmethod
    def fromString(status):
        return switcher[status]

    def toString(self):
        return self.value