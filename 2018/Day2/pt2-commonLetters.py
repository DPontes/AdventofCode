#!/usr/bin/python


def getCommonChars(str1, str2):
    # Returns a string of unique chars of the input strings
    uniqueList = []
    for elem1, elem2 in zip(str1, str2):
        if elem1 == elem2:
            uniqueList.append(elem1)
    if len(uniqueList) == (len(str1) - 1):
        return ''.join(uniqueList)
    else:
        return 0


def loopThrough():
    f = open('input.txt').readlines()
    # TODO(diogo): This double loop can be expressed in a better way
    for str1 in f:
        for str2 in f:
            uniqueString = getCommonChars(str1, str2)
            if uniqueString:
                return uniqueString

    return "No result"


if __name__ == '__main__':
    print(loopThrough())
