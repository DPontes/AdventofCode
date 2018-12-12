#!/usr/bin/python

def removeUniqueChars(unique, str1, str2):
    for letter in unique:
        if letter in str1:
            return str1.replace(letter, '')

def getUniqueChars(str1, str2):
    # Returns a list of unique chars of the input strings
    # TODO (diogo): This technique doesn work when the differenting
    # char appears somewhere else in the string
    return list(set(str1)^set(str2))

def loopThrough():
    f = open('input.txt').readlines()
    for str1 in f:
        for str2 in f:
            unique = getUniqueChars(str1, str2)
            if len(unique) < 3 and len(unique) > 0:
                print(str1,str2)
                return removeUniqueChars(unique, str1, str2)
    return "Done"

if __name__ == '__main__':
    print(loopThrough())
