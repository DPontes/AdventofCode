#!/usr/bin/python

inputfile = 'input.txt'

f = open(inputfile)
sum = 0
for line in f:
    if line[0] == '+': sum +=int(line[1:])
    else: sum -= int(line[1:])

print(sum)
