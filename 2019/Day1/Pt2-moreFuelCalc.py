#!/usr/bin/python3
import math


def calculateTotalFuel(inputFuel):
    fuel = 0
    fuel += math.floor(inputFuel / 3) - 2
    if fuel > 0:
        fuel += calculateTotalFuel(fuel)
        return fuel
    return 0


if __name__ == '__main__':
    f = open('input.txt')
    totalFuel = 0
    for line in f:
        totalFuel += calculateTotalFuel(int(line))
    print(totalFuel)
