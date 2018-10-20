class Case(object):
    def __init__(self,initial, devices):
        self.initial = initial
        self.devices = devices

    def solve_recursive(self, ini, dev, i,s):
        if i == len(ini[0]) + 1:
            return s
        if self.count_matches(ini,dev,i) == len(ini):
            res = self.solve_recursive(ini,dev,i+1,s)
            if res != 'NOT POSSIBLE':
                return res
            new_ini = [y[0:i] + str(int(not int(y[i]))) + y[i+1:] for
                        y in ini]
            res = self.solve_recursive(new_ini,dev,i+1,s+1)
            if res != 'NOT POSSIBLE':
                return res
        return 'NOT POSSIBLE'




    def solve(self):
        return self.solve_recursive(self.initial, self.devices, 0, 0)
        

    def count_matches(self,ini,dev,bit):
        ini = [s[0:bit] for s in ini]
        dev = [s[0:bit] for s in dev]
        sum = 0
        for x in ini:
            if x in dev:
                dev.remove(x)
                sum += 1
        return sum


def parse_stdin():
    n = int(raw_input())
    cases = []
    for i in xrange(n):
        data = [int(x) for x in raw_input().split(' ')]
        N = data[0]
        L = data[1]
        initial = raw_input().split(' ')
        devices = raw_input().split(' ')
        cases.append(Case(initial, devices))
    return cases


def main():
    cases = parse_stdin()
    i = 1
    for c in cases:
        print 'Case #{:d}:'.format(i), c.solve()
        i += 1


if __name__ == '__main__':
    main()
