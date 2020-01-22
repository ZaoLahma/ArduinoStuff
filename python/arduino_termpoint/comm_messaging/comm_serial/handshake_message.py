from ..message import Message
from .messages import Messages
import struct

class HandshakeMessage(Message):
    offset = 0
    def __init__(self):
        self.payload = 0

    def get_msg_type(self):
        return Messages.HANDSHAKE

    def encode(self):
        HandshakeMessage.offset += 1
        if HandshakeMessage.offset > 10000:
            HandshakeMessage.offset = 0
        to_send = self.payload + HandshakeMessage.offset
        return struct.pack('<h', to_send)

    def decode(self, data):
        self.payload = struct.unpack('<h', data)[0]
