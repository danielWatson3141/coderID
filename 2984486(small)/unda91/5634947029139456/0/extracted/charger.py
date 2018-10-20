#!/bin/usr/python

#
# Program for the google code jam 1A
# charging caos
# Emilio Unda

import sys
from copy import deepcopy


def is_zero(char):
    return 

def bool_to_string(bool):
    if bool:
        return "1"
    else:
        return "0"

def possible_switches(l):
    example = ""
    for i in range(l):
        example += "0"
    result = [ Outlet(example) for i in range(2 ** l)]
    
    for i in range(l):
        for j in range( len(result)):
            base = 2**(i+1)
            div =  2 ** i
            if (j % base) / div  != 0:
                result[j].flip_switch(i)

    return result

            
class Outlet:

    def ones(self):
        result = 0
        for b in self.bits:
            if b :
                result += 1
        return result

    def __init__(self, string):
        #no strict checking
        self.bits = [i=="1" for i in string ]
        return
    
    def flip_switch(self, n):
        self.bits[n] = not self.bits[n]
        return 
    
    def flip_outlet(self, outlet):
        for i in range(len(self.bits)):
            if( outlet[i] ) :
                self.bits[i] = not self.bits[i]
        return

    def __str__(self):
        result = ""
        for i in self.bits:
            result += bool_to_string(i)
        return result

    

    def equals(self, other):
        result = True
        for (i, j) in zip(self.bits, other.bits) :
            result = result and (i == j)
        return result

    def __getitem__(self, index):
        return self.bits[index]

class Case:

    def __init__(self, n, l, initial_string, final_string):
        self.n = n
        self.l = l
        self.initial = [ Outlet(i) for i in initial_string.split() ]
        self.final = [ Outlet(i) for i in final_string.split() ]

    def is_solved(self, outlets):
        outlets = deepcopy(outlets)
        result = True
        for f in self.final:
            is_here = False
            for i in range(len(outlets)):
                if (not is_here) and f.equals(outlets[i]):
                    outlets.pop(i)
                    is_here = True
            if not is_here:
                result = False
        return result

    def solve(self):
        result = ""
        not_solved = 1000000
        best_result = not_solved
        possibles = possible_switches(self.l)
        
        #print map( lambda x:x.bits, possibles)

        for flip in possibles:
            initial = deepcopy(self.initial)
            for outlet in initial:
                outlet.flip_outlet(flip)
                
            #check if this solves
            solved = self.is_solved(initial)

#            print map( lambda x:x.bits, initial)
 #           print map(lambda x:x.bits,   self.final)
  #          print solved

            if solved and (flip.ones() < best_result):
                best_result = flip.ones()
        if not_solved == best_result:
            result = "NOT POSSIBLE"
        else:
            result = str(best_result)
        return result



def main(argv):
    infile = open(argv[1], 'r')
    out =  open(argv[2], 'w')
    t = int( infile.readline().strip() )
    for i in range(t):
        
        n, l  = map(int, infile.readline().split() )
        initial = infile.readline()
        final = infile.readline()

        case = Case(n, l, initial, final)
        result = case.solve()

        out.write("Case #" + str(i+1) + ": " + result + "\n")
    
    infile.close()
    out.close()


if __name__ == "__main__" :
    main(sys.argv)
