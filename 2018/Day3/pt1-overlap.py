#!/usr/bin/python

f = open('example-input.txt').readlines()

def extractCoordinates(line):
    coord = line.split(' ')[2].split(',')
    coord[1] = coord[1][:-1]  # Removes the ':' at the end
    return coord

def extractDimensions(line):
    return line.split(' ')[3].split('x')

def defineArea(coords, dimens, rectArea):
    pass

if __name__ == '__main__':
    rectArea = []
    for line in f:
        coords = extractCoordinates(line)
        dimens = extractDimensions(line)
        defineArea(coords, dimens, rectArea)
