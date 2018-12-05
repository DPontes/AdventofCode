#!/usr/bin/python


def lineValue(line):
    # Returns the value of the line as an int
    return int(line[1:])


def sumOrSub(line):
    # Returns the first char in the line as +1 or -1
    if line[0] == '+':
        return 1
    else:
        return -1


def getTheTotal():
    # Returns the sum of the input
    f = open('input.txt')
    sum = 0
    for line in f:
        sum += sumOrSub(line) * lineValue(line)
    return sum


if __name__ == '__main__':
    print(getTheTotal())
