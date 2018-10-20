"""Python2- and Python3-compatible. That's all."""
from time import clock
from sys import argv
#import math
import itertools
#import numpy
from copy import deepcopy as dc

def read(f):
    return next(f).strip("\n")
    
def read_singles(f):
    # returns chars of a word
    # or digits (as strings) of an int
    return list(read(f))
    
def read_int(f, b=10):
    return int(read(f), b)
 
def read_float(f):
    return float(read(f))
 
def read_digits(f, b=10):
    return [int(n, b) for n in read_singles(f)]

#---------------------------------------------

def read_strs(f, s=" "):
    return read(f).split(s)
    
def read_ints(f, b=10, s=" "):
    return [int(n, b) for n in read_strs(f, s)]

def read_floats(f, s=" "):
    return [float(n) for n in read_strs(f, s)]
               
#---------------------------------------------

def read_lines(f, n, reader=read_ints, *args, **kwargs):
    ret = []
    for i in range(n):
        ret.append(reader(f, *args, **kwargs))
    return ret

#---------------------------------------------

def change_bit(s, place):
    if s[place] == "0":
        return s[:place]+"1"+s[place+1:]
    else:
        return s[:place]+"0"+s[place+1:]


def switch_lever(list1, place):
    pass
    

def get_combinations(l):
    """Source: http://stackoverflow.com/questions/464864
    /python-code-to-pick-out-all-possible-combinations-from-a-list"""
    for length in range(1, l+1):
        for subset in itertools.combinations(range(l), length):
            yield subset

def run(data):
    list1 = data[0]
    set2 = set(data[1])
    n = len(list1)
    l = len(list1[0])
    """Naive solution."""
    if set(list1) == set2:
        return "0"
    for combo in get_combinations(l):
        list1_modified = dc(list1)
        for i in range(l):
            if i in combo:
                for j in range(n):
                    list1_modified[j] = (change_bit(list1_modified[j], i))
        set1 = set(list1_modified)
        if set1 == set2:
            return len(combo)
    return "NOT POSSIBLE"

#---------------------------------------------

def read_case(f):
    read(f)
    return [read_strs(f), read_strs(f)]

def write_case(f, i, sol):
    f.writelines("Case #"+str(i+1)+": "+str(sol)+"\n")

#---------------------------------------------

def main():
    f = open(argv[1])
    f2 = open(argv[2], "wt")
    for i in range(read_int(f)):
        print("Init case "+str(i+1)+".")
        write_case(f2, i, run(read_case(f)))
        print("Finished in "+str(clock())+".")
    f.close()
    f2.close()

if __name__ == "__main__":
    main()
