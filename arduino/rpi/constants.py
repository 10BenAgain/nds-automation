import json


with open("settings.json") as s:
    settings = json.load(s)
    start = settings["start"]
    end = settings["end"]
    max_storage = settings["max_storage"]
    reboot_time = settings["reboot_time"]
    port = settings["port"]
    rate = settings["rate"]


instruct_modes = {
    "RLG RNG": 0,
    "RSE RNG": 1,
    "ACE Seed Checker": 2,
    "Custom Seed Checker": 3
}

button_map = {
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

audio_mode = {
    "Mono": 0,
    "Stereo": 1
}

shoulder_mode = {
    "L=A": 0,
    "HELP": 1,
    "LR": 2
}
