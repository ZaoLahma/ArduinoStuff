import serial
from serial_messages import SerialMessageCommunicator
from serial_messages import HandshakeMessage
from serial_messages import SerialMessages

class SerialRunner:
    def __init__(self, serial_port):
        self.serial_port = serial_port
        self.port = serial.Serial(port=serial_port, baudrate=115200, timeout=100, writeTimeout=100)

    def run(self):
        while True:
            msg = SerialMessageCommunicator.receive_message(self.port)
            if None != msg:
                if msg.msg_id == SerialMessages.HANDSHAKE:
                    print("Handshake received")
                    SerialMessageCommunicator.send_message(self.port, msg)
                if msg.msg_id == SerialMessages.LOG:
                    print("ARDUINO LOG: " + msg.payload)
                if msg.msg_id == SerialMessages.HEARTBEAT:
                    SerialMessageCommunicator.send_message(self.port, msg)
