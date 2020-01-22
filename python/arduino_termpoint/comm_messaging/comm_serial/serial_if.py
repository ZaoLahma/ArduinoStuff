from serial import Serial

class SerialIf:
    def __init__(self, port):
        self.connection = Serial(port=port, baudrate=115200, timeout=100, writeTimeout=100)

    def read(self, num_bytes):
        return self.connection.read(num_bytes)

    def write(self, value):
        return self.connection.write(value)