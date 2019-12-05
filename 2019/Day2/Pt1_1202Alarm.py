#!/usr/bin/python3
import csv


def readValues():
    with open('input.txt', 'r') as csv_file:
        reader = csv.reader(csv_file)
        value_list = list(reader)
    return list(map(int, value_list[0]))


def intCode(value_list):
    for element in range(0, len(value_list), 4):

        value_pos0 = value_list[element]
        if value_pos0 == 99:
            break

        value_pos1 = value_list[element + 1]
        value_pos2 = value_list[element + 2]
        value_pos3 = value_list[element + 3]

        if value_pos0 == 1:
            result = value_list[value_pos1] + value_list[value_pos2]

        elif value_pos0 == 2:
            result = value_list[value_pos1] * value_list[value_pos2]

        value_list[value_pos3] = result

    return value_list


if __name__ == '__main__':
    print('Result:', intCode(readValues())[0])
