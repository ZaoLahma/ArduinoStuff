from .message_receiver import MessageReceiver

class Logger(MessageReceiver):
    def __init__(self, messages):
        print("Logger instantiated")
        self.messages = messages

    def receive_msg(self, message):
        if self.messages.LOG == message.get_msg_type():
            print("ARDUINO LOG: " + message.payload)