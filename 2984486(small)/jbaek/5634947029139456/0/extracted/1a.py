from math import *
from itertools import *
from Queue import *


# general helper functions

def split_to_int(f):
    return [int(v) for v in f.next().split()]

def split_to_float(f):
    return [float(v) for v in f.next().split()]

def split_to_str(f):
    return [str(v) for v in f.next().split()]

def factors(n):
    return set(reduce(list.__add__,
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

# def isPrime(n):
  # if n == 2 or n == 3: return True
  # if n < 2 or n%2 == 0: return False
  # if n < 9: return True
  # if n%3 == 0: return False
  # r = int(n**0.5)
  # f = 5
  # while f <= r:
  #   if n%f == 0: return False
  #   if n%(f+2) == 0: return False
  #   f +=6
  # return True

def solve(num_devices, length_flow, initial_flows, devices):
    initial_flows.sort()
    devices.sort()
    str_devices = str(devices)
    if str(initial_flows) == str(devices):
        return 0
    else:
        for i in range(1, length_flow+1):
            for comb in combinations(range(length_flow), i):
                new_flows = initial_flows[:]
                for j in range(len(new_flows)):
                    curr_flow_list = list(new_flows[j])
                    for index_to_change in comb:
                        curr = curr_flow_list[index_to_change]
                        if curr == '1':
                            curr_flow_list[index_to_change] = '0'
                        else:
                            curr_flow_list[index_to_change] = '1'
                    new_flows[j] = ''.join(curr_flow_list)
                new_flows.sort()
                if str(new_flows) == str_devices:
                    return i
        return "NOT POSSIBLE"




# problem

def main():

    with open("/Users/jackiebaek/Dropbox/Documents/Programs/Codejam/2014/Round 1A/in.in") as f:
        cases = int(f.next())
        for i in range(cases):
            print "Case #%d:" % (i+1),
            N, L = split_to_int(f)
            initial_flows = split_to_str(f)
            devices = split_to_str(f)

            num_devices = N
            length_flow = L
            print solve(N, L, initial_flows, devices)
            

main()
