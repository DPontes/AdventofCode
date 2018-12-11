#!/usr/bin/python
from collections import Counter


def getLineOccurences(line):
    total = Counter(list(Counter(line).values()))
    # these two lines below are very ugly, should be refactored
    two = 0 if total.get(2) is None else 1
    three = 0 if total.get(3) is None else 1
    return two, three


def getCheckSum():
    f = open('input.txt')
    check = [0, 0]
    for line in f:
        two, three = getLineOccurences(line)
        check[0] += two
        check[1] += three
    return check[0] * check[1]


if __name__ == '__main__':
    print(getCheckSum())
