from ..message import Message
from .messages import Messages
import struct

class LogMessage(Message):
    def __init__(self):
        self.payload = ""

    def get_msg_type(self):
        return Messages.LOG

    def encode(self):
        return None

    def decode(self, data):
        self.payload = data.decode("utf-8")