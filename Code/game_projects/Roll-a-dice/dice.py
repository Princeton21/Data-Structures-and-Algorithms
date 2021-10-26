import random
from math import ceil, sqrt

import colored
from colored import stylize

_MAG_BOLD = colored.fg("magenta") + colored.attr("bold")
_YELLOW_BOLD = colored.fg("yellow_4b") + colored.attr("bold")
_GREEN_BOLD = colored.fg("green") + colored.attr("bold")


class Die:
    def __init__(self, faces_count, eyes="o ", corner="+"):
        """Compute statistics about places of eyes on a die face"""

        if len(eyes) != 2:
            raise ValueError("Excpected two choices for eyes parameter")

        self.eyes = eyes
        width = int(sqrt(faces_count))
        height = ceil(faces_count / width)

        # Fix lengthes for nearly square ascii-art
        while height > width + 1:
            width += 1
            height = ceil(faces_count / width)

        # Account for python 2 ceil returning float
        height = int(height)
        if not height % 2:
            # Fix height to have a middle point
            height += 1

        # Values to generate a specific face
        self.limit = width * height
        self.faces = faces_count

        # Template of the face
        pattern = " ".join("{}" for _ in range(width))
        pattern = "| {} |".format(pattern)
        top = corner + ("-" * (2 * width + 1)) + corner
        middle = " ".join("{}" for _ in range(width // 2))
        middle = "| " + middle + " " * (width % 2)
        self.pattern = "\n".join(
            [top] + [pattern for _ in range(height // 2)] + [middle]
        )

        # Size of the ascii-art
        self.width = len(top)
        self.height = self.pattern.count("\n") * 2 + 1

    def face(self, roll):
        """Return the full face of the roll for this die.

        roll is accounted in a 0-base fashion.
        """

        if not (0 <= roll < self.faces):
            raise ValueError("Roll is higher than die size or negative")

        eye_full, eye_empty = self.eyes

        # Fill the pattern with correct eye for current roll
        upper_face = self.pattern.format(
            *(eye_empty if roll < i else eye_full for i in range(1, self.limit, 2))
        )

        # Return mirrored pattern string with changing middle to get a full face
        return upper_face + self.eyes[roll & 1] + upper_face[::-1]


def print_dice_rolls(faces_count, rolls, zero_based=False, max_width=72, eyes="o "):
    """Pretty print all rolls using faces_count-sided di(c)e."""

    # Set up some default values
    die = Die(faces_count, eyes)
    face_width = die.width

    # Will try to collate output of multiple dice rolls into lines
    # of up to max_width length
    output_buffer = ["" for _ in range(die.height)]

    # Output the dice rolls using output_buffer
    # Make sure to use 0-based rolls
    for roll in (r + zero_based - 1 for r in rolls):

        # Flush buffer if too wide
        if len(output_buffer[0]) + face_width >= max_width:
            for idx, line in enumerate(output_buffer):
                pp(line, _YELLOW_BOLD)
                output_buffer[idx] = ""

        # Build a proper face according to faces_count and roll
        current_face = die.face(roll)

        # Append die to output_buffer
        for idx, line in enumerate(current_face.split("\n")):
            output_buffer[idx] += line + "  "

    # Print remaining dice in output_buffer
    if output_buffer[0]:
        for line in output_buffer:
            pp(line, _YELLOW_BOLD)


def pp(text, style=_MAG_BOLD):
    """ Pretty-print with style """
    print(stylize(text, style))


def Rolldice(rolls):
    rolles = [random.randint(1, 6) for x in range(0, rolls)]
    print("\n\n")
    print_dice_rolls(6, rolles)
    print("\n\n")
    main()


def main():

    pp("1. Roll a dice")  # roll for one dice
    pp("2. Roll multiple dice")  # roll for multiple dice
    pp("3. Exit from Game\n\n")  # exit() function to exit from game.

    choice = int(input(stylize("Enter choice: ", _GREEN_BOLD)))

    if choice == 1:
        Rolldice(1)
    if choice == 2:
        rolls = int(input(stylize("Enter no. of rolls: ", _GREEN_BOLD)))
        Rolldice(rolls)  # call for multiple rolls
    if choice == 3:
        print("Out of the Game")
        exit()


if __name__ == "__main__":
    pp("\n\n---====Roll A Dice!====---\n\n", _GREEN_BOLD)
    main()
