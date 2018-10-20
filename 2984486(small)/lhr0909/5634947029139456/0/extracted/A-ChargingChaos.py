from itertools import *

def flip(outlet, switch):
    outlet_list = list(outlet)
    for index in switch:
        if outlet_list[index] == '0':
            outlet_list[index] = '1'
        else:
            outlet_list[index] = '0'
    return ''.join(outlet_list)

def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    T = int(fin.readline())
    for case in xrange(T):
        answer = ""
        #data read
        N, L = map(int, fin.readline().strip().split(" "))
        #print N, L
        outlets = fin.readline().strip().split(" ")
        devices = fin.readline().strip().split(" ")
        print outlets, devices
        if (frozenset(outlets) == frozenset(devices)):
            answer = 0
        else:
            for i in xrange(L):
                for indices in combinations(range(L), i):
                    new_outlets = map(lambda x: flip(x, indices), outlets)
                    #print indices, new_outlets, devices
                    if (frozenset(new_outlets) == frozenset(devices)):
                        answer = i
                        break
                if answer != "":
                    break
        if answer == "":
            answer = "NOT POSSIBLE"
        print answer
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')

    fin.close()
    fout.close()

if __name__ == "__main__":
    solve("A-small-attempt2")