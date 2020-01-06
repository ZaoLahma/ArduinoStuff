from enum import IntEnum
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
    MSG_OFFSET = 0
    @staticmethod
    def receive_message(port):
        msg_type = SerialMessages(SerialUtils.receive_int8(port))
        data_size = SerialUtils.receive_int8(port)
        data = SerialUtils.receive_int8(port)
        print("Data size: " + str(data_size) + " data " + str(data))
        return SerialMessageFactory.create_message(msg_type)

    @staticmethod
    def send_message(port, message):
        print("Send message")
        SerialUtils.send_int8(port, message.msg_id + SerialMessageCommunicator.MSG_OFFSET)
        SerialMessageCommunicator.MSG_OFFSET += 1
        if SerialMessageCommunicator.MSG_OFFSET > 127:
            SerialMessageCommunicator.MSG_OFFSET = 0
        payload = message.encode()
        if None != payload:
            raise NotImplementedError

class SerialMessages(IntEnum):
    HANDSHAKE = 0