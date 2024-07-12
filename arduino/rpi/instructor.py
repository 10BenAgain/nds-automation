import constants


class SeedCheckerBuilder:
    def __init__(self, timer, button, audio=None, shoulder=None):
        self.__mode = 3
        self.__minimum_timer = constants.start
        self.__maximum_timer = constants.end
        self.__current_settings = [0, 0]
        self.__button_options = [
            constants.button_map["A"],
            constants.button_map["L"],
            constants.button_map["Start"]
        ]
        self.__instruct = [self.__mode, 0, timer, audio, shoulder, button, 0]
        if audio is None:
            self.__instruct[3] = 0
        if shoulder is None:
            self.__instruct[4] = 0

    def _check_values(self) -> bool:
        if not (self.__minimum_timer <= self.__instruct[2] <= self.__maximum_timer):
            return False

        if not (constants.audio_mode["Mono"] <= self.__instruct[3] <= constants.audio_mode["Stereo"]):
            return False

        if not (constants.shoulder_mode["L=A"] <= self.__instruct[4] <= constants.shoulder_mode["LR"]):
            return False

        if self.__instruct[5] not in self.__button_options:
            return False

        return True

    def change_intro_instruct(self, timer: int) -> None:
        if self._check_values():
            self.__instruct[2] = timer

    def change_audio_setting(self, setting: int) -> None:
        if self._check_values():
            self.__instruct[3] = setting
            self.__current_settings[0] = setting

    def change_shoulder_setting(self, setting: int) -> None:
        if self._check_values():
            self.__instruct[4] = setting
            self.__current_settings[1] = setting

    def change_button_setting(self, button: int) -> None:
        if not self._check_values():
            return

        # If settings arent L=A then pressing L doesnt work
        elif button == constants.button_map["L"]:
            if self.__current_settings[1] != 0:
                return
        else:
            self.__instruct[5] = button

    def increment_timer(self, timer: int) -> None:
        if timer < 0:
            return

        tmp = self.__instruct[2]
        total = timer + tmp

        if total > self.__maximum_timer:
            return
        else:
            self.__instruct[2] = total

    def return_instructions(self) -> list[int]:
        if self._check_values():
            return self.__instruct
        else:
            # Default values with 1 at the end
            # Last digit should be checked to see if there was an error
            return [3, 0, 35000, 0, 0, 2, 1]
