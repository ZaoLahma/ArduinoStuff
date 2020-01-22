from .comm_send_if import CommSendIf
import struct

class CommEndpoint(CommSendIf):
    def __init__(self, interface, protocol):
        self.interface = interface
        self.protocol = protocol
        self.running = False
        self.msg_receivers = []
        self.to_send = []

    def send_msg(self, message):
        self.to_send.append(message)

    def register_msg_receiver(self, receiver):
        self.msg_receivers.append(receiver)

    def run(self):
        self.running = True
        while self.running:
            self.receive_messages()
            self.send_messages()

    def receive_messages(self):
        message_size = struct.unpack('<H', self.interface.read(2))[0]
        data = bytearray(self.interface.read(message_size))
        message = self.protocol.decode(data)

        if None != message:
            for receiver in self.msg_receivers:
                receiver.receive_msg(message)

    def send_messages(self):
        for message in self.to_send:
            payload = self.protocol.encode(message)
            if None != payload:
                self.interface.write(struct.pack('<H', len(payload)))
                self.interface.write(payload)
            else:
                self.interface.write(struct.pack('<H', 0))
        self.to_send = []