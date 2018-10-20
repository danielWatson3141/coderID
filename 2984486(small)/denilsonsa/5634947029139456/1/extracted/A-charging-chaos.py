#!/usr/bin/env python3

from functools import reduce

def solve_testcase(testcase_number):
    N, L = [int(x) for x in input().split()]

    outlets = [int(x, 2) for x in input().split()]
    devices = [int(x, 2) for x in input().split()]

    matrix = [
        [outlets[i] ^ devices[j] for i in range(N)]
        for j in range(N)
    ]

    response = reduce(set.intersection, (set(x) for x in matrix))
    if response:
        bits = [bin(x) for x in response]
        num_moves = [x.count('1') for x in bits]
        answer = min(num_moves)
    else:
        answer = 'NOT POSSIBLE'

    print('Case #{0}: {1}'.format(testcase_number, answer))


def main():
    testcases = int(input())
    for t in range(testcases):
        solve_testcase(t + 1)


if __name__ == '__main__':
    main()
