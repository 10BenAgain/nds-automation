import os
import time
import serial
import logging
import instructor
import constants


def init_logs(log_dir="logs", base_file="logs") -> logging.Logger:
    if not os.path.exists(log_dir):
        os.makedirs(log_dir)

    log_stamp = time.strftime("%Y%m%d-%H%M%S")
    log_name = f"{base_file}_{log_stamp}"
    log_path = os.path.join(log_dir, log_name)

    logger = logging.getLogger(log_path)
    logger.setLevel(logging.DEBUG)

    file_handler = logging.FileHandler(log_path)
    file_handler.setLevel(logging.DEBUG)

    formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
    file_handler.setFormatter(formatter)

    logger.addHandler(file_handler)

    return logger


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


def perform_seed_loop(ins: instructor.SeedCheckerBuilder, increment=None, storage=None) -> None:
    logger = init_logs()
    data = ins.return_instructions()
    if storage is None:
        storage = constants.max_storage
    logger.info(f"Storage set to {storage} seeds")

    if increment is None:
        increment = 8
    logger.info(f"Incrementing intro timer by {increment}")

    if check_send_data(data):
        logger.critical(f"Error in seed data! Default value found")
        return

    logger.info("Beginning seed collection loop...")
    while storage > 0:
        intro = data[2]
        logger.info(f"Current intro timer: {intro}")
        write_to_device(data)
        sec = (intro + constants.reboot_time) / 1000
        logger.info(f"Waiting for seed write: {sec} seconds")
        time.sleep(sec)
        ins.increment_timer(increment)
        storage -= 1


def main() -> None:
    ins = instructor.SeedCheckerBuilder(timer=35000, button=13)
    perform_seed_loop(ins)


if __name__ == "__main__":
    main()
