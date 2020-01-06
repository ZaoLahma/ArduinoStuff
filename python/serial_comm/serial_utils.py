import struct

class SerialUtils:
    @staticmethod
    def receive_int8(port):
        return struct.unpack('<b', bytearray(port.read(1)))[0]

    @staticmethod
    def receive_int16(f):
        return struct.unpack('<h', bytearray(f.read(2)))[0]

    @staticmethod
    def send_int8(port, value):
        port.write(struct.pack('<b', value))

    @staticmethod
    def send_int16(f, value):
        f.write(struct.pack('<h', value))