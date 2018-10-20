def do():
    times = input()
    for i in xrange(times):
        print 'Case #%d:'%(i+1),
        calculate()

def bit_count(x):
    i = 0
    while x>0:
        i += x%2
        x >>= 1
    return i

def get():
    L = raw_input().split()
    return [eval('0b'+x) for x in L]

def calculate():
    L,N = map(int,raw_input().split())
    init = get()
    final = get()

    valid_case = []




    S = set(x ^ init[0] for x in init)
    valid = []
    for y in final:
        if S == set(x ^ y for x in final):
            valid.append(y)
    if valid:
        valid_case.append(min(bit_count(x^init[0]) for x in valid))







    if len(valid_case) == 0:
        print "NOT POSSIBLE"
    else:
        print min(valid_case)


if __name__ == '__main__':
    do()

