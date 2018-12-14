#!/usr/bin/python3
import numpy as np


def extractCoordinates(line):
    x, y = line.split(' ')[2].split(',')
    y = y[:-1]  # Removes the ':' at the end
    return int(x), int(y)


def extractDimensions(line):
    width, length = line.split(' ')[3].split('x')
    return int(width), int(length)


def defineArea(x, y, width, length, rectArea):
    pass


if __name__ == '__main__':
    f = open('example-input.txt').readlines()
    rectArea = np.zeros(64)
    rectArea = rectArea.reshape((8,8))
    print(rectArea)
    for line in f:
        x, y = extractCoordinates(line)
        width, length = extractDimensions(line)
