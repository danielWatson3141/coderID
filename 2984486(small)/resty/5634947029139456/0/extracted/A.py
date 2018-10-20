import sys
#f = open("A.txt")
f = sys.stdin

def split(s):
    s0 = []
    s1 = []
    for i in s:
        if i[0] == '0':
            s0.append(i[1:])
        else:
            s1.append(i[1:])
    return (s0, s1)

def calc(sets):
    assert len(sets) != 0
    s0 = True
    s1 = True
    l0 = []
    l1 = []
    for ra in sets:
        sa, sb = ra
        if len(sa[0]) == 0:
            return 0
        sa0, sa1 = split(sa)
        sb0, sb1 = split(sb)
        if s0 and len(sa0) == len(sb0):
            assert len(sa1) == len(sb1)
            if len(sa0) != 0:
                l0.append((sa0, sb0))
            if len(sa1) != 0:
                l0.append((sa1, sb1))
        else:
            s0 = False
        if s1 and len(sa0) == len(sb1):
            assert len(sa1) == len(sb0)
            if len(sa0) != 0:
                l1.append((sa0, sb1))
            if len(sa1) != 0:
                l1.append((sa1, sb0))
        else:
            s1 = False
    ans = -1
    #res = []
    if s0:
        ans = calc(l0)
        #res = [0] + res
    if s1:
        new_ans = calc(l1)
        if new_ans != -1:
            new_ans = new_ans + 1
            if ans == -1 or new_ans < ans:
                ans = new_ans
                #res = [1] + nres
    return ans
            
def check(res, setA, setB):
    new_setA = []
    for s in setA:
        ss = ''
        for i in range(len(res)):
            if res[i] == 0:
                ss += s[i]
            elif s[i] == '1':
                ss += '0'
            else:
                ss += '1'
        new_setA.append(ss)
    new_setA.sort()
    return new_setA == setB

def solve():
    N, L = map(int, f.readline().split(' '))
    setA = f.readline().rstrip().split(' ')
    setB = f.readline().rstrip().split(' ')
    setA.sort()
    setB.sort()
    assert len(setA) == N
    for s in setA:
        assert(len(s) == L)
    assert len(setB) == N
    for s in setB:
        assert (len(s) == L)
    cnt = calc([(setA, setB)])

    # calc by enum:
##    tans = 100000
##    ttres = -1
##    for x in range(2 ** L):
##        tres = []
##        for i in range(L):
##            tres.append( x / 2 ** i % 2)
##        if check(tres, setA, setB):
##            tans = min(tans, sum(tres))
##            ttres = tres
##
##    if tans <= L:
##        assert tans == cnt
    if cnt == -1:
        return "NOT POSSIBLE"
    else:
        return cnt
    
T = int(f.readline())
for i in range(T):
    print "Case #%d: %s" % (i + 1, solve())
