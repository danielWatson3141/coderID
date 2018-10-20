import os
import itertools
import sets

def find(s):
    return [i for i, ltr in enumerate(s) if ltr == '1']

def flip(s, pos):
    out = list(s)
    for i in pos:
        if out[i] == '0':
            out[i] = '1'
        else:
            out[i] = '0'
    return ''.join(out)

def kbits(n, k):
    result = []
    for bits in itertools.combinations(range(n), k):
        s = ['0'] * n
        for bit in bits:
            s[bit] = '1'
        result.append(''.join(s))
    return result

def solve(f):
    done = False
    n, l = f.readline().split()
    outlets = f.readline().split()
    devices = f.readline().split()
    fail = False
    d = {}
    for elem in outlets:
        d[elem] = 0
    for z in devices:
        if z not in d:
            fail = True
            break
        d[z] += 1
        if d[z] > 1:
            fail = True
            break
    if not fail:
        return 0
    for k in range(1, int(l)):
        perm = kbits(int(l), int(k))
        for j in perm:
            fail = False
            d = {}
            temp = [flip(x, find(j)) for x in outlets]
            if len(set(temp)) != int(n):
                continue
            for elem in temp:
                d[elem] = 0
            for z in devices:
                if z not in d:
                    fail = True
                    break
                d[z] += 1
                if d[z] > 1:
                    fail = True
                    break
            if not fail:
                return k
    return "NOT POSSIBLE"
    
if __name__ == "__main__":
    input_filename = 'A-small-attempt0.in'
    output_filename = 'out0.txt'
 
    f_in = open(input_filename)
    counter = int(output_filename.split('.')[0][-1])
    while os.path.isfile(output_filename):
        counter += 1
        output_filename = output_filename.split(str(counter - 1) + '.')[0] + str(counter) + '.txt'
    f_out = open(output_filename, 'a')
 
    test_cases = int(f_in.readline())
    for i in range(test_cases):
        ans = solve(f_in)
        f_out.write('Case #' + str(i + 1) +': ' + str(ans) + '\n')
 
    f_in.close()
    f_out.close()
    print "done"
