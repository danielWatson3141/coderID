#!/usr/bin/python
# vi: set fileencoding=utf-8 :

import math

def judge(N, L, flow, device): 
    for f in flow:
        for d in device:
            if f == d: break
        else: return 'NOT POSSIBLE'
    return 0

def flip(string, i):
    if string[i] == '0':
        return string[:i] + '1' + string[i + 1:]
    else:
        return string[:i] + '0' + string[i + 1:]

def flip_list(zero_one_list, i):
    new_zero_one_list = zero_one_list[:]
    if zero_one_list[i] == 0:
        new_zero_one_list[i] = 1
    else:
        new_zero_one_list[i] = 0
    return new_zero_one_list


def search(N, L, flow, device):
    zeros = [0 for i in range(L)]
    searched = {tuple(zeros): True}
    Q = [zeros]
    while len(Q) > 0:
        v = Q.pop(0)
        #print v
        flow2 = flow[:]
        #print flow, flow2
        for j in range(L):
            if v[j] == 0: continue
            for i in range(N):
                #print 'i', i
                flow2[i] = flip(flow2[i], j)
        result = judge(N, L, flow2, device)
        if result != 'NOT POSSIBLE':
            return sum(v)
        for i in range(L):
            vv = flip_list(v, i)
            if tuple(vv) in searched:
                pass
            else:
                #print vv
                Q.append(vv)
                searched[tuple(vv)] = True
    else:
        return 'NOT POSSIBLE'

T = int(raw_input())
for t in range(T):
    line = raw_input()
    N, L = line.split(' ')
    N = int(N)
    L = int(L)
    line = raw_input()
    line.rstrip()
    flow = line.split(' ')
    line = raw_input()
    line.rstrip()
    device = line.split(' ')
    print 'Case #' + str(t + 1) + ':', search(N, L, flow, device)
