#! /usr/bin/env python

def main():
    with open('a.in', 'r') as fin, open('a.out', 'w') as fout:
        num_cases = int(fin.readline())
        for case in range(1, num_cases + 1):
            num_outlets, len_str = map(int, fin.readline().split())
            initial_state = fin.readline().split()
            desired_state = fin.readline().split()
            answer = solve(initial_state, desired_state, num_outlets, len_str)
            fout.write('Case #{0}: {1}\n'.format(case, answer))
    return

def solve(initial_state, desired_state, num_outlets, len_str):
    print initial_state
    print desired_state
    flip = float('inf')
    for index in range(num_outlets):
        flip = min(flip, match(initial_state[:], desired_state[:], index))
    return flip if flip != float('inf') else 'NOT POSSIBLE'

def match(initial, desired, index):
    """Match inital[index] = desired[0], see if possible."""
    print 'Index = ', index
    x = initial.pop(index)
    y = desired.pop(0)
    switches = int(x, 2) ^ int(y, 2)
    initial = [switches ^ int(z, 2) for z in initial]
    print sorted(initial)
    print sorted([int(z, 2) for z in desired])
    if set(initial) == set([int(z, 2) for z in desired]):
        return bin(switches)[2:].count('1')
    else:
        return float('inf')

if __name__ == '__main__':
    main()
