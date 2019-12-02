#!/usr/bin/python3
import math


def calculateMass():
    f = open('input.txt')
    sum = 0
    for line in f:
        sum += math.floor(int(line) / 3) - 2
    return sum


if __name__ == '__main__':
    print(calculateMass())
