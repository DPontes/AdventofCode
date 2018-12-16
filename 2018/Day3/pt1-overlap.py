#!/usr/bin/python

def extractCoordinates(line):
    x, y = line.split(' ')[2].split(',')
    y = y[:-1]  # Removes the ':' at the end
    return int(x), int(y)


def extractDimensions(line):
    # Splits the received line into a list of elements
    # separated by a space, and then applies the same
    # to the 3rd element by spliting it into a list of
    # dimensions with 'width' and 'length'
    width, length = line.split(' ')[3].split('x')
    return int(width), int(length)


def defineArea(x, y, width, length, availableArea, usedArea):
    for w in range(width):
        for l in range(length):
            if[x+w, y+l] not in availableArea:
                availableArea.append([x+w, y+l])
            else:
                if [x+w, y+l] not in usedArea:
                    usedArea.append([x+w, y+l])
    return availableArea, usedArea


if __name__ == '__main__':
    f = open('input.txt').readlines()
    availableArea = []
    usedArea = []
    for line in f:
        print(line)
        x, y = extractCoordinates(line)
        width, length = extractDimensions(line)
        availableArea, usedArea = defineArea(x, y, width, length, availableArea,usedArea)
    print(usedArea)
    print(len(usedArea))    
