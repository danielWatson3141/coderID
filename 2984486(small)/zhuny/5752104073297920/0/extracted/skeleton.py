import pprint

def do():
    times = input()
    for i in xrange(times):
        print 'Case #%d:'%(i+1),
        calculate()

def calculate():
    N = input()
    
    L = map(int,raw_input().split())

    if len(filter(lambda X:X[0]==X[1],enumerate(L)))>1:
        print 'BAD'
    else:
        print 'GOOD'


if __name__ == '__main__':
    do()

