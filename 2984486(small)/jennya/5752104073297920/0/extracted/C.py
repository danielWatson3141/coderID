import random
import sys
f = open(sys.argv[1])

line = f.readline()
T = int(line)

case_counter = 1
while 1:
    if case_counter > T: break

    # input stage
    N = int(f.readline())
    permutation = f.readline().split()

    r = random.randrange(0,2)
    if r==0: output = "GOOD"
    else: output = "BAD"

    # output stage
    print("Case #%d: %s" % (case_counter, output) )

    case_counter += 1

