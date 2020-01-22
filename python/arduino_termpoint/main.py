from comm_core.comm_endpoint import CommEndpoint
from comm_app.comm_state import CommState
from comm_app.logger import Logger
from comm_messaging.comm_serial.serial_if import SerialIf
from comm_messaging.comm_serial.serial_protocol import SerialProtocol
from comm_messaging.comm_serial.messages import Messages

class Main:
    @staticmethod
    def run():
        print("Arduino End Point starting...")
        comm_if = SerialIf("/dev/ttyACM0")
        protocol = SerialProtocol()
        comm_end_point = CommEndpoint(comm_if, protocol)
        comm_end_point.register_msg_receiver(CommState(comm_end_point, Messages))
        comm_end_point.register_msg_receiver(Logger(Messages))
        comm_end_point.run()

if __name__ == "__main__":
    Main.run()