""" Script to automatically send incremented data to Arduino for farming seeds in FRLG"""

import os
import time
import json
import logging

import serial
import instructor
import constants


def init_logs(log_dir="logs", base_file="logs") -> logging.Logger:
    """Setup a logger that logs both to files in a 'logs' directory and to the terminal"""
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

    console_handler = logging.StreamHandler()
    console_handler.setLevel(logging.DEBUG)
    console_handler.setFormatter(formatter)

    logger.addHandler(console_handler)
    logger.addHandler(console_handler)

    return logger


def get_timer_button_settings() -> list[int]:
    """Gets the start point timer and button from config"""
    with open("settings.json", encoding='utf-8') as s:
        settings = json.load(s)
        return [settings["start_point"], settings["button"]]


def write_to_device(instructions: list[int]) -> None:
    """Tries to write the required data to the serial port"""
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


def check_send_data(data: list[int]) -> bool:
    """Checks if the Instructor object returns with default values"""
    # Check if the last value of the seed checker instruction is
    # Set to default value of 1
    if data[len(data) - 1]:
        return True
    return False


def perform_seed_loop(ins: instructor.SeedCheckerBuilder, increment=None, storage=None) -> None:
    """
    Creates logger object then checks params for function and sets defaults
    While the special save still has storage, send the data from instructor
    Object to the arduino then increment the intro timer by the desired amount.
    While we wait for the loop to complete, time.sleep() is called to time the
    Sequence correctly. The sleep time is incremented accordingly
    """
    logger = init_logs()
    data = ins.return_instructions()
    if storage is None:
        storage = constants.max_storage
    logger.info("Storage set to %d seeds", storage)

    if increment is None:
        increment = 8
    logger.info("Incrementing intro timer by %d", increment)

    if check_send_data(data):
        logger.critical("Error in seed data! Default value found")
        return

    logger.info("Beginning seed collection loop...")
    count = 0
    while storage:
        count += 1
        logger.info("Record count: %d", count)
        intro = data[2]
        logger.info("Current intro timer: %d", intro)
        sec = (intro + constants.reboot_time) / 1000
        if intro > ins.get_maximum_timer():
            logger.critical("Timer exceeded maximum wait time... ending loop")
            break

        write_to_device(data)
        logger.info("Waiting for seed write: %f seconds", sec)
        time.sleep(sec)
        ins.increment_timer(increment)
        storage -= 1


def main() -> None:
    """Gets the settings, creates a new instructor object and starts the loop"""
    settings = get_timer_button_settings()
    ins = instructor.SeedCheckerBuilder(timer=settings[0], button=settings[1])
    perform_seed_loop(ins)


if __name__ == "__main__":
    main()
