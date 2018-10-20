import sys
from itertools import product

def check(flows, reqs, choice):
    flows2 = [tuple(int(flow[i] != choice[i]) for i in range(L)) for flow in 
            flows]
    return set(reqs) == set(flows2)


basename = "A-small-attempt2"

input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())
irritating = 0
for case in range(1, test_cases+1):
    
    N, L = [int(i) for i in input_file.readline().rstrip().split()]
    flows = []
    for string in input_file.readline().rstrip().split():
        flows.append(tuple(int(i) for i in string))

    reqs = []
    for string in input_file.readline().rstrip().split():
        reqs.append(tuple(int(i) for i in string))

    #Check to see if it is possible
    reqsums = tuple(sum(req[i] for req in reqs) for i in range(L))
    flowsums = tuple(sum(flow[i] for flow in flows) for i in range(L))

    if all(reqsums[i] == flowsums[i] or reqsums[i] == N - flowsums[i] for i in 
            range(L)):
        
        swappos = [i for i in range(L) if reqsums[i] != flowsums[i]]
        choicepos = [i for i in range(L) if reqsums[i] == flowsums[i] and
                reqsums[i] == N - flowsums[i]]
        choices = []
        for i in range(L):
            if i in swappos:
                choices.append([1])
            elif i in choicepos:
                choices.append([0,1])
            else:
                choices.append([0])
        found = False
        for choice in product(*choices):
            if check(flows, reqs, choice):
                found = True
                solution = sum(choice)
                break
        
        if not found:
            solution = "NOT POSSIBLE"

    else:
        solution = "NOT POSSIBLE"


    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')
