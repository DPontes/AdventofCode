#!/usr/bin/python3
import math


def calculateFuel(fuel):
        return math.floor(int(fuel) / 3) - 2


if __name__ == '__main__':
    f = open('input.txt')
    sum = 0
    for line in f:
        sum += calculateFuel(line)
    print(sum)
