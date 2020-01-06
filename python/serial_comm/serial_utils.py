import struct

class SerialUtils:
    @staticmethod
    def receive_int8(port):
        byte = port.read(1)
        print(byte)
        return struct.unpack('<b', bytearray(port.read(1)))[0]

    @staticmethod
    def write_int8(port, value):
        port.write(struct.pack('<b', value))