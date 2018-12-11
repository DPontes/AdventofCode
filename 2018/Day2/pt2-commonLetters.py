#!/usr/bin/python

def getUniqueChars(str1, str2):
    # Returns a list of unique chars of the input strings
    return list(set(str1)^set(str2))

def loopThrough():
    str1 = open('example-input.txt').readline()
    print(str1)

if __name__ == '__main__':
    loopThrough()
