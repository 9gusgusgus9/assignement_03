import serial
class SerialComunicator:
    def __init__(self, port, baudrate):
        self.port = port
        self.baudrate = baudrate
        self.ser = serial.Serial(self.port, self.baudrate, timeout=self.timeout)

    def write(self, data):
        self.ser.write(data.encode())

    def read(self):
        return self.ser.readline()

    def close(self):
        self.ser.close()
    
    def comunicate(manifest):
        write("sto comunicando")