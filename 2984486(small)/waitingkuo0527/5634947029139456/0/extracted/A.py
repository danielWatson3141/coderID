def solve(N, L, charges, devices):
    """ solve the problem """

    #print(N, L, charges, devices)

    count = 0
    ans = 999999999

    #stack = []
    flips = []
    for i in range(L):
        flip = []
        c_0 = 0
        c_1 = 0
        d_0 = 0
        d_1 = 0
        for c in charges:
            if c[i] == '0': c_0+=1
            else: c_1+=1
        for d in devices:
            if d[i] == '0': d_0+=1
            else: d_1+=1

        #print(c_0, c_1, d_0, d_1)

        if c_0 == d_0:
            flip.append(0)
        if c_0 == d_1:
            flip.append(1)

        if len(flip) == 0: return 'NOT POSSIBLE'

        flips.append(flip)

    #print( flips )
    stack = [[i] for i in flips[0]]
    #print(stack)
    for flip in flips[1:]:
        next_stack = []
        for s in stack:
            for f in flip:
                next_stack.append(s + [f])
        stack = next_stack
    #print(stack)

    #charges = [int(ch) for ch in charge for charge in charges]
    _charges = []
    for charge in charges:
        _charges.append([int(ch) for ch in charge])
    #print('--')
    #print(_charges)
    #print('--')
    for flips in stack:
        #print(flip)
        charges = [c[:] for c in _charges]
        for i, flip in enumerate(flips):
            if flip == 1:
                #print('flip', i)
                #print(charges)
                for charge in charges:
                    if charge[i] == 1:
                        charge[i] = 0
                    else:
                        charge[i] = 1
                #print(charges)
                #print('flip-->')
        #print('<----')
        #print(_charges)
        #print()
        #print(flips)
        #print()
        #print(charges)
        #print('---->')
         
        _charges = []  
        for charge in charges:
            #print(charge)
            charge = [str(ch) for ch in charge]
            _charges.append(charge)
        #print(_charges)
        charges = [''.join( charge ) for charge in _charges]
        #print(charges)
        if sorted(charges) == sorted(devices):
            #print(sum(flips))
            fff = sum(flips)
            if fff < ans: ans = fff


    if ans == 999999999: return 'NOT POSSIBLE'
    return ans


def parse():
    """ parse input """
    N, L = map(int, input().split(' '))
    charges = input().split(' ')
    devices = input().split(' ')

    return N, L, charges, devices


def main():
    
    T = int(input())


    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
