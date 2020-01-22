from .message_receiver import MessageReceiver

class CommState(MessageReceiver):
    def __init__(self, send_if, messages):
        print("CommState instantiated")
        self.send_if = send_if
        self.messages = messages

    def receive_msg(self, message):
        if self.messages.HANDSHAKE == message.get_msg_type():
            self.send_if.send_msg(message)
        elif self.messages.HEARTBEAT == message.get_msg_type():
            self.send_if.send_msg(message)