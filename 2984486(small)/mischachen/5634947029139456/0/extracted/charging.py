#!/usr/bin/python

"""Code Jam 2014"""

import sys

def find_switch(idx, N, L, input, output):
    """docstring for find_switch"""
    #print L, input, output
    diff = [[0 for x in range(N)] for x in range(N)]
    for i in range(N):
        for j in range(N):
            diff[i][j] = input[j] ^ output[i]
    dest = []
    for x in diff[0]:
        is_contain = True
        for i in range(N-1):
            if x not in diff[i+1]:
                is_contain = False
        if is_contain:
            dest.append(x)
    if dest:
        dest2 = [bin(x).count('1') for x in dest]
        min_switch = min(dest2)
        print "Case #%d: %d" % (idx, min_switch)
    else:
        print "Case #%d: NOT POSSIBLE" % (idx)
            



        

def main():
    """entry point"""
    input = sys.stdin.readlines()
    case_num = int(input[0])
    for i in range(case_num):
        info = input[3*i+1].strip().split()
        N = int(info[0])
        L = int(info[1])
        first_line = [int(x, 2) for x in input[3*i+2].strip().split()]
        second_line = [int(x, 2) for x in input[3*i+3].strip().split()]
        find_switch(i+1, N, L, first_line, second_line)


if __name__ == '__main__':
    main()
