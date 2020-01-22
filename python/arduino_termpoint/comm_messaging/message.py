class Message:
    def get_msg_type(self):
        raise NotImplementedError

    def encode(self):
        raise NotImplementedError

    def decode(self, data):
        raise NotImplementedError