'''
Created on Apr 12, 2014

@author: ignacio
'''

import sys
import logging
import os

if "--debug" in sys.argv:
    logging.basicConfig(level=logging.DEBUG)

def main():
    problem_input = sys.stdin
    if len(sys.argv) > 1:
        input_file = sys.argv[1]
        if os.path.isfile(input_file):
            problem_input = open(input_file)
        
    cases = int(problem_input.readline())
    logging.debug(cases)
    for case in xrange(cases):
        resp = run_case(problem_input)
        print "Case #%s: %s" % (case + 1, resp,)
            
def run_case(problem_input):
    _n, _l = (int(x) for x in problem_input.readline().split())
    outlets = problem_input.readline().split()
    chargers = sorted(problem_input.readline().split())
    
    values = []
    for charger in chargers:
        diff = flip(outlets[0], charger)
        new_outlets = sorted([flip(outlet, diff) for outlet in outlets])
        if new_outlets == chargers:
            values.append(weight(diff))
    
    return min(values) if values else "NOT POSSIBLE"
            

def weight(number):
    return number.count("1")

def flip(a, b):
    res = ["0" if x == y else "1" for x, y in zip(a, b)]
    return "".join(res)

if __name__ == "__main__":
    main()
