import time
import serial
import insructor
import constants


def write_to_device(instructions: list[int]) -> None:
    try:
        with serial.Serial(bytesize=8,
                           baudrate=constants.rate,
                           port=constants.port) as ser:
            time.sleep(2)
            for i in instructions:
                ins = f"{i}+"
                ser.write(ins.encode(encoding='ascii'))
            ser.write("?".encode(encoding='ascii'))
            ser.flush()
    except serial.SerialException as e:
        print("Serial port already in use!")
        raise e


def print_instructions(instructions: list[int]) -> None:
    for i in instructions:
        print(i)


def check_send_data(data: list[int]) -> bool:
    # Check if the last value of the seed checker instruction is
    # Set to default value of 1
    if data[len(data) - 1]:
        return True


def perform_seed_loop(ins: insructor.SeedCheckerBuilder, increment=None, storage=None) -> None:
    data = ins.return_instructions()
    if storage is None:
        storage = constants.max_storage

    if increment is None:
        increment = 8

    if check_send_data(data):
        return

    while storage > 0:
        intro = data[2]
        write_to_device(data)
        sec = (intro + constants.reboot_time) / 1000
        print(f"Waiting for: {sec} seconds\n")
        time.sleep(sec)
        ins.increment_timer(increment)
        storage -= 1


def main() -> None:
    ins = insructor.SeedCheckerBuilder(timer=35000, button=13)
    perform_seed_loop(ins)


if __name__ == "__main__":
    main()
