"""Series of commonly used constants that correspond to Arduino values"""
import json

with open("settings.json", encoding='utf-8') as s:
    settings = json.load(s)
    start = settings["start"]
    end = settings["end"]
    max_storage = settings["max_storage"]
    reboot_time = settings["reboot_time"]
    port = settings["port"]
    rate = settings["rate"]
    mode = settings["mode"]
    increment = settings["increment"]

instruct_modes: dict[str, int] = {
    "RLG RNG": 0,
    "RSE RNG": 1,
    "ACE Seed Checker": 2,
    "Custom Seed Checker": 3
}

button_map: dict[str, int] = {
    "A": 2,
    "B": 3,
    "X": 4,
    "Y": 5,
    "Left": 6,
    "Right": 7,
    "Up": 8,
    "Down": 9,
    "L": 10,
    "R": 11,
    "Select": 12,
    "Start": 13,
    "Power": 14
}

audio_mode: dict[str, int] = {
    "Mono": 0,
    "Stereo": 1
}

shoulder_mode: dict[str, int] = {
    "L=A": 0,
    "HELP": 1,
    "LR": 2
}
