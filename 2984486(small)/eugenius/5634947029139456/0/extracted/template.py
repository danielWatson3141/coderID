"""
Author: Eugene Yurtsev
"""
import sys
import math
import itertools

debug=False

def parse_case(stream):
    specs1 = map(int,stream.readline().split(' '))
    specs2 = stream.readline().split(' ')
    specs3 = stream.readline().split(' ')
    specs2[-1] = specs2[-1][:-1]
    specs3[-1] = specs3[-1][:-1]
    specs2 = [[int(x) for x in y] for y in specs2]
    #specs3 = [[int(x) for x in y] for y in specs3]
    return [specs1, specs2, specs3]

def compare_equality(outlets, devices):
    outlets = [''.join(map(str, o)) for o in outlets]
    for switch in devices:
        s = ''.join(map(str, switch))
        if s in outlets:
            outlets.remove(s)
        else:
            return False
    return True

def toggle_switches(outlets, switch_nums):
    new_outlets = []
    for o in outlets:
        m = list(o)
        for switch in switch_nums:
            m[switch] = int(not m[switch])
        new_outlets.append(m)
    return new_outlets

def solve_case(specs):
    outlets = specs[1]
    devices = specs[2]
    num_switches = specs[0][1]
    if compare_equality(devices, outlets):
        return str(0)
    for num_flip in range(1, num_switches+1):
        for r in itertools.combinations(range(num_switches), num_flip):
            new_outlets = toggle_switches(outlets, r)
            if compare_equality(new_outlets, devices):
                return str(num_flip)
    return 'NOT POSSIBLE'

def main(stream):
    num_cases = int(stream.readline())

    for case in range(num_cases):
        specs = parse_case(stream)
        print 'Case #{}: {}'.format(case+1, solve_case(specs))

    if debug:
        print
        print '-'*40
        print 'Solution'
        print '-'*40
        print ''.join(stream.readlines())

if __name__ == '__main__':
    if debug:
        with open('test.in', 'r') as stream:
            main(stream)
    else:
        main(sys.stdin)
