"""
Program to create an hour_glass pattern.
"""


def row_check(rows):
    if rows < 0:
        raise ValueError("Rows are less tha 0.")


def hourglass(rows):
    """
    Function to create an hourglass pattern
    Tests:
    >>> hourglass(2)
    ***
     *
    ***
    >>> hourglass(5)
    *********
     *******
      *****
       ***
        *
       ***
      *****
     *******
    *********
    """
    row_check(rows)
    column = (rows * 2) - 1
    pattern = []

    for x in range(1, rows + 1):
        length = x * 2 - 1
        string = "*" * length
        pattern.append(string.center(column))

    pattern = pattern[::-1] + pattern[1::]
    pattern = "\n".join(pattern)
    return pattern


if __name__ == "__main__":
    print(hourglass(10))
    print(hourglass(20))
