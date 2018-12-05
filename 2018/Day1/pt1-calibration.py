#!/usr/bin/python


def getTheTotal():
    # Returns the sum of the input
    f = open('input.txt')
    sum = 0
    for line in f:
        sum += int(line)
    return sum


if __name__ == '__main__':
    print(getTheTotal())
