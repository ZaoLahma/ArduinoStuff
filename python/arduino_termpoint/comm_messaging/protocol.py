class Protocol:
    def decode(self, data):
        raise NotImplementedError

    def encode(self, Message):
        raise NotImplementedError