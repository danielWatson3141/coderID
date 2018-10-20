class Solver():
    def __init__(self, f):
        parts = f.readline().split(' ')
        self.N = int(parts[0])
        self.L = int(parts[1])
        self._outlets = [list(x.strip()) for x in f.readline().split(' ')]
        self.outlets = [x for x in self._outlets]
        self.devices = [x.strip() for x in f.readline().split(' ')]


    def is_kosher(self, decisions):
        k = len(decisions)
        outlets = [[x for x in o] for o in self.outlets]
        for i, d in enumerate(decisions):
            if d == '1':
                for j in range(self.N):
                    outlets[j][i] = '1' if outlets[j][i] is '0' else '0'
        outlets = [''.join(o) for o in outlets]
        prefixes = {}
        for outlet in outlets:
            prefix = outlet[0:k]
            if prefix in prefixes:
                prefixes[prefix] += 1
            else:
                prefixes[prefix] = 1
        for device in self.devices:
            prefix = device[0:k]
            if prefix not in prefixes or prefixes[prefix] == 0:
                return False
            prefixes[prefix] -= 1
        return True




    def min_flips(self, i, devices, outlets, decisions):
        if i == self.L:
            return 0, []
        zero_outlets = [o for o in outlets if o[i] == '0']
        one_outlets = [o for o in outlets if o[i] == '1']
        zero_devices = [d for d in devices if d[i] == '0']
        one_devices = [d for d in devices if d[i] == '1']
        dont_flip = None
        do_flip = None
        new_decision = decisions + ['0']
        if self.is_kosher(new_decision):
            dont_flip = self.min_flips(i + 1, devices, outlets, new_decision)

        new_decision = decisions + ['1']
        if self.is_kosher(new_decision):
            do_flip = self.min_flips(i + 1, devices, outlets, new_decision)

        if dont_flip is None and do_flip is None:
            return None
        elif dont_flip is None:
            return do_flip[0] + 1, ['1'] + do_flip[1]
        elif do_flip is None:
            return dont_flip[0], ['0'] + dont_flip[1]
        elif do_flip[0] + 1 < dont_flip[0]:
            return do_flip[0] + 1, ['1'] + do_flip[1]
        else:
            return dont_flip[0], ['0'] + dont_flip[1]


    def solve(self):
        ans = self.min_flips(0, self.devices, self.outlets, [])
        #if ans is not None:
            #print [''.join(x) for x in self._outlets]
            #print self.devices
            # for i, do_flip in enumerate(ans[1]):
            #     if do_flip == '1':
            #         for j in range(self.N):
            #             self._outlets[j][i] = '1' if self._outlets[j][i] == '0' else '0'
            #print ans[1]
            #print sorted([''.join(x) for x in self._outlets])
            #print sorted(self.devices)
        return str(ans[0]) if ans is not None else "NOT POSSIBLE"


def main():
    with open('input.txt', 'rb') as f:
        num_problems = int(f.readline())
        answers = []
        for i in xrange(num_problems):
            solver = Solver(f)
            answers.append('Case #%d: %s' % (i + 1, solver.solve()))
        with open('output.txt', 'w') as fout:
            fout.write('\n'.join(answers))
        print answers


if __name__ == "__main__":
    main()
