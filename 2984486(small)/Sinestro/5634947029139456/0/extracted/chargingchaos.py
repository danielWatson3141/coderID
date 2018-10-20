from sys import stdout
from itertools import combinations
from collections import Counter
from copy import copy


def is_solution(have, want):
    return Counter(have) == Counter(want)


def flip(string, i):
    l = list(string)
    if l[i] == '1':
        l[i] = '0'
    else:
        l[i] = '1'

    return ''.join(l)


def solve(have, want):
    for num_flips in range(0, len(have[0])):
        for flips in combinations(range(0, len(have[0])), num_flips):
            working = copy(have)

            for flip_index in flips:
                for index, item in enumerate(working):
                    working[index] = flip(item, flip_index)

            if is_solution(working, want):
                print num_flips
                return

    print "NOT POSSIBLE"


num_cases = int(raw_input())

for case in range(1, num_cases + 1):
    num, width = map(int, raw_input().split(' '))

    have = raw_input().split(' ')
    want = raw_input().split(' ')

    stdout.write("Case #%i: " % case)
    solve(have, want)
