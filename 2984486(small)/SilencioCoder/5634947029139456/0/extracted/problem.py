from copy import copy
from copy import deepcopy
from math import factorial
from itertools import combinations

f = factorial
c = combinations

def solve_case(case):
    n, l, initial, target = case

    if is_same(initial, target):
        return 0

    for i in range(1, l):
        for combi in c(range(l), i):
            new = deepcopy(initial)
            for pos in combi:
                for item in new:
                    item[pos] = '1' if item[pos] == '0' else '0'
            if is_same(new, target):
                return i

    return 'NOT POSSIBLE'

def is_same(x, y):
    new_x = deepcopy(x)
    new_y = deepcopy(y)

    new_x.sort()
    new_y.sort()
    
    if new_x == new_y:
        return True

    return False

def parse(input_lines):
    n_cases = int(input_lines.pop(0))
    cases = []

    for i in range(0, len(input_lines), 3):
        if not input_lines[i]:
            break

        n, l = [int(num) for num in input_lines[i].split(' ')]
        initial = [list(num) for num in input_lines[i + 1].split(' ')]
        target = [list(num) for num in input_lines[i + 2].split(' ')]

        cases.append((n, l, initial, target))

    if n_cases != len(cases):
        raise ValueError('Parse error.')

    return n_cases, cases

def solve(input_file):
    with open(input_file + '.in', 'r') as f:
        input_lines = f.read().split('\n')

    n_cases, cases = parse(input_lines)

    solution = []
    for i in range(0, n_cases):
        answer = solve_case(cases[i])
        solution.append('Case #%s: %s' % (i + 1, answer))

    with open(input_file + '.out', 'w') as f:
        f.write('\n'.join(solution))

if __name__ == '__main__':
    solve('problem')

