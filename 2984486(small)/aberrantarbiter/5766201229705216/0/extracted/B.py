class Solver():
    def __init__(self, f):
        self.n = int(f.readline().strip())
        edges = {}
        for i in range(self.n - 1):
            parts = f.readline().split(' ')
            x = int(parts[0])
            y = int(parts[1])
            if x in edges:
                edges[x].append(y)
            else:
                edges[x] = [y]
            if y in edges:
                edges[y].append(x)
            else:
                edges[y] = [x]
        self.edges = edges

    def children(self, target, incoming):
        if target not in self.edges:
            return []
        childs = [x for x in self.edges[target]]
        if incoming in childs:
            childs.remove(incoming)
        return childs

    def size(self, target, parent):
        return 1 + sum([self.size(c, target) for c in self.children(target, parent)])

    def to_be_root(self, target, incoming):
        childs = self.children(target, incoming)
        if len(childs) == 0:
            return 0
        elif len(childs) == 1:
            print 'Removing %d' % target
            return self.size(childs[0], target)
        elif len(childs) == 2:
            return sum([self.to_be_root(c, target) for c in self.children(target, incoming)])
        else:
            contribs = []
            for c in self.children(target, incoming):
                sz, cost = self.size(c, target), self.to_be_root(c, target)
                print 'Contribution of %d is %d' % (c, sz - cost)
                contribs.append((sz, cost, c))
            best = sorted(contribs, key=lambda x: x[0] - x[1])
            total = sum([x[0] for x in best[:-2]]) + sum([x[1] for x in best[-2:]])
            print 'Keeping %d and %d at cost %d' % (best[-2][2], best[-1][2], total)
            return total




    def solve(self):
        min_cost = self.n
        for i in range(1, self.n + 1):
            print 'Using %d as root' % i
            cost = self.to_be_root(i, None)
            print 'Cost is %d' % cost
            min_cost = min(min_cost, cost)
        return str(min_cost)


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
