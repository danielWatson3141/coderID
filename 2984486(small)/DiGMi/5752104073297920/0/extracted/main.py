SAMPLES = 1000

import random

def BAD(data):
    d = [x for x in data]
    for x in xrange(len(data)):
        i = random.randint(0,len(data)-1)
        temp = d[x]
        d[x] = d[i]
        d[i] = temp
    return d

class Case(object):
    def __init__(self,data):
        self.data = data

    def solve(self):
        n = len(self.data)
        i = 0
        sum = 0
        for x in self.data:
            if x > i - 50 and x < i + 50:
                sum += 1
            i += 1
        if sum > 99:
            return 'BAD'
        return 'GOOD'

def parse_stdin():
    T = int(raw_input())
    cases = []
    for i in xrange(T):
        n = raw_input()
        data = [int(x) for x in raw_input().split(' ')]
        cases.append(Case(data))
    return cases


def main():
    cases = parse_stdin()
    i = 1
    for c in cases:
        print 'Case #{:d}:'.format(i), c.solve()
        i += 1


if __name__ == '__main__':
    main()
