#!/usr/bin/python
import random
import math
import pickle
from difflib import SequenceMatcher
from collections import Counter

# filename = "sample.in"
filename = "C-small-attempt0.in"
# filename = "C-large.in"

inp = open(filename, "rU")

n = int(inp.readline().strip())

for case in range(1, n + 1):
    size = int(inp.readline().strip())
    lst = [int(x) for x in inp.readline().strip().split()]
    fst = 0.35
    snd = 0.48
    middle = 0.6
    cor = (size-1) /2
    lst = [i/cor for i in lst]
    idl = [0.5] * size
    diff1 = (1/size) * sum(list(map(lambda x: (abs(x[0] - x[1]))**2, zip(idl, lst))))
    idl[0] = fst
    idl[1] = snd
    idl[int(size/2)] = middle
    diff2 = (1/size) * sum(list(map(lambda x: (abs(x[0] - x[1]))**2, zip(idl, lst))))
    if diff2 < diff1:
        outp = 'BAD'
    else:
        outp = 'GOOD'
    print("Case #{}: {}".format(case, outp))
    

# def bpermute(n):
#     a = list(range(n))
#     for i in range(n):
#         p = random.randint(0, n-1)
#         a[i], a[p] = a[p], a[i]
#     return a

# def gpermute(n):
#     a = list(range(n))
#     for i in range(n):
#         p = random.randint(i, n-1)
#         a[i], a[p] = a[p], a[i]
#     return a

# # def distance(l):
# #     s = 1
# #     for item in l:
# #         if item == str(s):
# #             s += 1
# #     return len(l) - s + 1

# def distance(l):
#     a = str(list(range(len(l))))
#     b = l
#     s = SequenceMatcher(None, a, b)
#     return s.ratio()

# n = 6
# T = 100000
# gs = []
# bs = []
# for i in range(T):
#     gs.append(gpermute(n))
#     bs.append(bpermute(n))

# x = int(math.factorial(n)/2)
# gst = 0
# bst = 0
# gpos = [0] * n
# bpos = [0] * n
# print('GS')
# for i in list(Counter([pickle.dumps(x) for x in gs]).items())[:x]:
#     gst += 1
#     gpos = list(map(sum, (zip(gpos,pickle.loads(i[0])))))
#     # if gst >= T/2:
#         # break

    
# print('BS')
# for i in Counter([pickle.dumps(x) for x in bs]).most_common()[:x]:
#     bst += 1
#     bpos = list(map(sum, (zip(bpos,pickle.loads(i[0])))))
#     # if gst >= T/2:
#         # break

# print(gpos)
# print(bpos)
# print(list(map(lambda s: ((s/gst)/((n-1))), gpos)))
# print(list(map(lambda s: ((s/bst)/((n-1))), bpos)))

# # print("good average = {}".format(gst/T))
# # print("bad  average = {}".format(bst/T))



