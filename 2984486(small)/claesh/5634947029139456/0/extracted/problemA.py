#!/usr/bin/python
#
# problemA.py
#

# Import
from gcj import Problem
import itertools

# Parser
def parser(fin):
    return [fin.readInts(), fin.readWords(),fin.readWords()]

def flipSwitch(outlets, switch):
    for i in xrange(len(outlets)):
        outlet = list(outlets[i])
        outlet[switch] = '0' if outlet[switch] == '1' else '1'
        outlets[i] = ''.join(outlet)
    return outlets


# Solver
def solver(data):
    [[N,L], initial, required] = data
    
    required = sorted(required)

    switchPositions = ['{0:0{1}b}'.format(i,L) for i in xrange(2**L)]

    solutions = []
    for switchPosition in switchPositions:
        outlets = initial[:]
        for i in xrange(len(switchPosition)):
            if switchPosition[i] == '1':
                outlets = flipSwitch(outlets,i)
        if sorted(outlets) == required:
            solutions.append(sum(map(int,list(switchPosition))))
            
    if solutions == []:
        return 'NOT POSSIBLE'
    else:
        return min(solutions)
            



    

# Main
if __name__ == '__main__':
    Problem(parser, solver, globals()).run()






















