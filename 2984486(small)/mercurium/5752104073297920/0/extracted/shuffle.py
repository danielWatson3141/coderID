import string

file_name = "C-small-attempt1.in"

shuffleInput = open(file_name, 'r')
data = string.split(shuffleInput.read().strip(), '\n')
numCases = int(data[0])

index = 1
good = 0
for case in range(1, numCases+1):
    SIZE = int(data[index])
    perm = [int(x) for x in string.split(data[index+1], " ")]
    index +=2

    values = dict()  # (value, position)
    for i in range(SIZE):
        values[perm[i]] = i


    diff = 0
    for i in range(SIZE):
        if values[i] != i:
            values[values[i]] = values[i]
            values[i] = i
            diff +=1

    if diff < 636:
        print "Case #" + str(case)  + ": GOOD"
        good +=1
    else:
        print "Case #" + str(case)  + ": BAD"
#print good
