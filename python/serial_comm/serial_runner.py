import serial
from serial_messages import SerialMessageCommunicator
from serial_messages import HandshakeMessage

class SerialRunner:
    def __init__(self, serial_port):
        self.serial_port = serial_port
        self.port = serial.Serial(port=serial_port, baudrate=115200, timeout=500, writeTimeout=500)
        self.curr_state = self.handle_init

    def run(self):
        while True:
            self.curr_state()

    def handle_init(self):
        print("Init...")
        msg = SerialMessageCommunicator.receive_message(self.port)
        if None != msg:
           print("Received message in init")
           print(msg.payload)
           msg = HandshakeMessage()
           SerialMessageCommunicator.send_message(self.port, msg)
           self.curr_state = self.handle_connected

    def handle_connected(self):
        msg = SerialMessageCommunicator.receive_message(self.port)
        if None != msg:
           print(msg.payload)
