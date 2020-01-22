from ..protocol import Protocol
from .messages import Messages
from .handshake_message import HandshakeMessage
from .heartbeat_message import HeartbeatMessage
import struct

class SerialProtocol(Protocol):
    def encode(self, message):
        data = struct.pack('<B', message.get_msg_type())
        payload = message.encode()

        if None != payload:
            data += payload

        return data

    def decode(self, data):
        msg_type = struct.unpack('<B', data[0:1])[0]
        msg = None
        if Messages.HANDSHAKE == msg_type:
            msg = HandshakeMessage()
        elif Messages.LOG == msg_type:
            print("Log received but not handled")
        elif Messages.HEARTBEAT == msg_type:
            msg = HeartbeatMessage()

        if None != msg:
            msg.decode(data[1:])

        return msg