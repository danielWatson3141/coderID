import itertools
T = int(input())
for I in range(1, T+1):
    res = "result"
    N, L = [int(x) for x in input().split()]
    inputs = input().split()
    outputs = input().split()
    # convert into array of letters
    for i in range(0, N):
        inputs[i] = [x for x in inputs[i]]
        outputs[i] = [x for x in outputs[i]]
    flip_count = 0
    flippable = []
    for i in range(0, L):
        # for every bit
        # calculate number of inputs that have it activated.
        inp_act, out_act = 0, 0
        for inp in inputs:
            if (inp[i] == '1'):
                inp_act += 1
        # calculate number of outputs that have it activated.
        for out in outputs:
            if (out[i] == '1'):
                out_act += 1
        if (inp_act == out_act):
            # don't flip the bit
            if (inp_act == N - out_act):
                # we may actually try flipping the bit
                flippable.append(i)
            pass
        elif (inp_act == N - out_act):
            # flip the bit
            for inp in inputs:
                if (inp[i] == '1'):
                    inp[i] = '0'
                else:
                    inp[i] = '1'
            flip_count += 1
        else:
            # no can do
            flip_count = -1
            res = "NOT POSSIBLE"
            break
    if (flip_count >= 0):
        # perform the check
        inputs.sort()
        outputs.sort()
        correct = True
        mincount = L + 47
        for i in range(0, N):
            if (inputs[i] != outputs[i]):
                correct = False
        if correct:
            res = str(flip_count)
        else:
            # try flipping the flippable bits, remembering the solution
            # with least flipped bits            
            for subset in list(itertools.chain.from_iterable( itertools.combinations(list(flippable), n) for n in range(len(flippable) + 1) )):                
                for bit in subset:                    
                    # try flipping the bit
                    for inp in inputs:
                        inp[bit] = '0' if inp[bit] == '1' else '1'
                # perform check again
                inputs.sort()                
                correct = True                
                for i in range(0, N):
                    if (inputs[i] != outputs[i]):
                        correct = False
                if correct:
                    if len(subset) < mincount:
                        mincount = len(subset)                        
                for bit in subset:
                    for inp in inputs:
                        inp[bit] = '0' if inp[bit] == '1' else '1'    
                    # flip the bits back
            if mincount != L + 47:
                res = str(flip_count + mincount)
            else:
                # really not possible
                res = "NOT POSSIBLE"
    print("Case #%d: %s" % (I, res))
    
