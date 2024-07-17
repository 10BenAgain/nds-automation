"""Script that pulls data from Save file at a given offset"""

SAVE_PATH = "FIRE RED SEED COLLECTION SAVE.sav"
RESULTS_PATH = "results.txt"
OFFSET = 0x0001e006
LENGTH = 4000


def extract_seed_data(path: str, offset: hex, length: int) -> list[str]:
    """ Opens save file, starts at offset, reads data into
        groups of 4 char strings until specified length """
    with open(path, 'rb') as file:
        file.seek(offset)
        data = file.read(length)
        hex_dat = data.hex()
        return [hex_dat[i:i + 4] for i in range(0, len(hex_dat), 4)]


def sort_by_word(data: list[str]) -> list[str]:
    """Sorts the list of groups by word (instead of by byte)"""
    return [word[2:] + word[:2] for word in data]


def write_lines_to_file(path: str, data: list[str]) -> None:
    """Writes the results into a text file"""
    with open(path, 'w', encoding='utf-8') as file:
        for line in data:
            file.write(f"{line}\n")


def main() -> None:
    """Reads and writes seed data stored from special save file"""
    data = extract_seed_data(SAVE_PATH, OFFSET, LENGTH)
    words = sort_by_word(data)
    write_lines_to_file(RESULTS_PATH, words)


if __name__ == "__main__":
    main()
