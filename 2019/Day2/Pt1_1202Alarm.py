#!/usr/bin/python3
import csv


def readValues():
    with open('input.txt', 'r') as csv_file:
        reader = csv.reader(csv_file)
        value_list = list(reader)
    return value_list[0]


def intCode(value_list):
    return
