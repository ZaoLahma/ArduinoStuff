from serial_runner import SerialRunner

class Main:
    @staticmethod
    def run():
        print("Running...")
        serial_runner = SerialRunner("/dev/ttyACM0")
        serial_runner.run()

if __name__ == "__main__":
    Main.run()