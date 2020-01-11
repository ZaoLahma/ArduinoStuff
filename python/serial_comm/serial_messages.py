from enum import IntEnum
from serial_utils import SerialUtils
import struct

class MessageBase:
    def encode(self):
        raise NotImplementedError

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
        print("To send: " + str(to_send))
        print("Encoded: " + str(struct.pack('<h', to_send)))
        return struct.pack('<h', to_send)

    def decode(self, data):
        self.payload = struct.unpack('<h', data)[0]

class SerialMessageFactory:
    @staticmethod
    def create_message(msg_id, data):
        if SerialMessages.HANDSHAKE == msg_id:
            msg = HandshakeMessage()
            msg.decode(data)
            return msg
        return None

class SerialMessageCommunicator:
    MSG_OFFSET = 0
    @staticmethod
    def receive_message(port):
        msg_type = SerialMessages(SerialUtils.receive_uint8(port))
        data_size = SerialUtils.receive_uint16(port)
        data = SerialUtils.receive(port, data_size)
        print("Data size: " + str(data_size) + " data " + str(data))
        return SerialMessageFactory.create_message(msg_type, data)

    @staticmethod
    def send_message(port, message):
        print("Send message")
        SerialUtils.send_uint8(port, message.msg_id)
        payload = message.encode()
        if None != payload:
            SerialUtils.send_uint16(port, len(payload))
            SerialUtils.send(port, payload)

class SerialMessages(IntEnum):
    HANDSHAKE = 45