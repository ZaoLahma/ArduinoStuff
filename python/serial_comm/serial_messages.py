from enum import IntEnum
from serial_utils import SerialUtils
import struct

class MessageBase:
    def encode(self):
        raise NotImplementedError

class LogMessage(MessageBase):
    def __init__(self):
        self.payload = ""
        self.msg_id = SerialMessages.LOG

    def encode(self):
        return NotImplementedError

    def decode(self, data):
        self.payload = data.decode("utf-8")

class HandshakeMessage(MessageBase):
    offset = 0
    def __init__(self):
        self.payload = 0
        self.msg_id = SerialMessages.HANDSHAKE

    def encode(self):
        HandshakeMessage.offset += 1
        if HandshakeMessage.offset > 10000:
            HandshakeMessage.offset = 0
        to_send = self.payload + HandshakeMessage.offset
        return struct.pack('<h', to_send)

    def decode(self, data):
        self.payload = struct.unpack('<h', data)[0]

class HeartbeatMessage(MessageBase):
    def __init__(self):
        self.payload = None
        self.msg_id = SerialMessages.HEARTBEAT

    def encode(self):
        return self.payload

    def decode(self, data):
        self.payload = None

class SerialMessageFactory:
    @staticmethod
    def create_message(msg_id, data):
        msg = None
        if SerialMessages.HANDSHAKE == msg_id:
            msg = HandshakeMessage()
            msg.decode(data)
        elif SerialMessages.LOG == msg_id:
            msg = LogMessage()
            msg.decode(data)
        elif SerialMessages.HEARTBEAT == msg_id:
            msg = HeartbeatMessage()
            msg.decode(data)
        return msg

class SerialMessageCommunicator:
    MSG_OFFSET = 0
    @staticmethod
    def receive_message(port):
        msg_type = SerialMessages(SerialUtils.receive_uint8(port))
        data_size = SerialUtils.receive_uint16(port)
        data = None
        if 0 != data_size:
            data = SerialUtils.receive(port, data_size)
        return SerialMessageFactory.create_message(msg_type, data)

    @staticmethod
    def send_message(port, message):
        SerialUtils.send_uint8(port, message.msg_id)
        payload = message.encode()
        if None != payload:
            SerialUtils.send_uint16(port, len(payload))
            SerialUtils.send(port, payload)
        else:
            SerialUtils.send_uint16(port, 0)

class SerialMessages(IntEnum):
    HANDSHAKE = 0
    LOG = 1
    HEARTBEAT = 2