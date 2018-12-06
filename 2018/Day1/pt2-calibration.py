#!/usr/bin/python3


def firstDoubleFreq():
    # Returns the first frequency that repeats it self
    f = open('input.txt')
    latestFreq = 0
    freqs = []

    while True:
        line = f.readline()
        if line == '':  # if reaching the end of the file
            f.seek(0)   # returns to the top
        else:
            latestFreq += int(line)
            if latestFreq in freqs:
                break
            else:
                freqs.append(latestFreq)

    return latestFreq


if __name__ == '__main__':
    print(firstDoubleFreq())
