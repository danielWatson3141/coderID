def switch(n):
    for e in outlets:
        if(e[n]=='0'):
            e[n]='1'
        else:
            e[n]='0'

def is_valid():
    return sorted(outlets)==sorted(elements)

def rec(l,b):
    global best
    if(b>=best):
        return
    if(is_valid()):
        if(b<best):
            best=b
        return
    if(l==L):
        return

    switch(l)
    rec(l+1,b+1)
    switch(l)
    rec(l+1,b)

    return

def solve():
    global N,L,best,outlets,elements
    N,L = [int(i) for i in raw_input().split(' ')]
    best = L+1
    outlets = [list(e) for e in raw_input().split(' ')]
    elements = [list(e) for e in raw_input().split(' ')]

    rec(0,0)
    return best


if __name__=='__main__':
    global L
    T = input()

    for t in range(1,T+1):
        b = solve()
        if(b==L+1):
            print("Case #%d: NOT POSSIBLE" % t)
        else:
            print("Case #%d: %d" % (t,b))

