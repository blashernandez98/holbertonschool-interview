#!/usr/bin/python3
""" Task 0 module """


def minOperations(n):
    """
    n a text file, there is a single character H.
    Only executing two operations: Copy All and Paste.
    Given a number n, calculates the fewest number of operations
    needed to result in exactly n H characters in the file.
    """
    if type(n) is not int or n <= 0:
        return 0

    if n == 1:
        return 0

    Hs = 1
    operations = 0

    while Hs != n:
        if n % Hs == 0:
            copy = Hs
            operations += 1

        Hs += copy
        operations += 1

    return operations
