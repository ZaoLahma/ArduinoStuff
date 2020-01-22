from ..message import Message
from .messages import Messages

class HeartbeatMessage(Message):
    def __init__(self):
        self.payload = None

    def get_msg_type(self):
        return Messages.HEARTBEAT

    def encode(self):
        return self.payload

    def decode(self, data):
        self.payload = None