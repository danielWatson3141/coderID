import sys
from pprint import pprint

def write(st):
    sys.stdout.write(st)
def writecase(i):
    if i == 0:
        print 'i is 0!!!!!!!!!!!!!!!!!'
    write("Case #%d: " % i)

f = open(sys.argv[1])
T = int(f.readline())

def test(inputs, outputs):
    s = sorted(inputs)
    t = sorted(outputs)
    for i in range(len(s)):
        if s[i] != t[i]:
            return False

    return True

for t in range(1, T+1):
    line = f.readline()
    parts = line.split()
    N = int(parts[0])
    L = int(parts[1])

    line = f.readline()
    inputs = line.split()
    for i in range(N):
        inputs[i] = int(inputs[i], 2)
    line = f.readline()
    outputs = line.split()
    for i in range(N):
        outputs[i] = int(outputs[i], 2)

    found = False
    writecase(t)
    for i in range(2**L):
        flipped = [x^i for x in inputs]
        if test(flipped, outputs):
            binstr = "{0:b}".format(i)
#            print binstr
            write('%d\n' % binstr.count('1'))
            found = True
            break
    if not found:
        write('NOT POSSIBLE\n')

f.close()