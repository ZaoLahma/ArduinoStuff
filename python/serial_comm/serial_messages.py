from enum import Enum
from serial_utils import SerialUtils

class MessageBase:
    def encode(self):
        raise NotImplementedError

class HandshakeMessage(MessageBase):
    def __init__(self):
        self.msg_id = SerialMessages.HANDSHAKE

    def encode(self):
        return None

class SerialMessageFactory:
    @staticmethod
    def create_message(msg_id):
        if SerialMessages.HANDSHAKE == msg_id:
            return HandshakeMessage()
        return None

class SerialMessageCommunicator:
    @staticmethod
    def receive_message(port):
        msg_type = SerialMessages(SerialUtils.receive_int8(port))
        return SerialMessageFactory.create_message(msg_type)

    @staticmethod
    def send_message(port, message):
        SerialUtils.write_int8(port, message.msg_id)
        payload = message.encode()
        if None != payload:
            raise NotImplementedError

class SerialMessages(Enum):
    HANDSHAKE = 0