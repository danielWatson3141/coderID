

file_in = open('b.in', 'r')
file_out = open('b.out', 'w')

n_case = int(file_in.readline())
    
class X:
    def __init__(self, ident):
        self.ident = ident
        self.me_best = 1
        self.adj = {}

    def update(self):
        change = False
        if len(self.adj) <= 1:
            return change

        tops = list(self.adj.keys())
        tops.sort(key=lambda x: -x.adj[self])

        old = self.me_best
        self.me_best = tops[0].adj[self] + tops[1].adj[self] + 1
        assert old <= self.me_best
        change = change or old < self.me_best

        if len(self.adj) <= 2:
            return change

        for x in self.adj:
            val = tops[0].adj[self] + tops[1].adj[self] + 1
            if x == tops[0]:
                val = tops[1].adj[self] + tops[2].adj[self] + 1
            if x == tops[1]:
                val = tops[0].adj[self] + tops[2].adj[self] + 1

            old = self.adj[x]
            self.adj[x] = val
            assert old <= val
            change = change or old < val

        return change
                            
    
def connect(x, y):
    x.adj[y] = 1
    y.adj[x] = 1

for i_case in range(n_case):
    #print i_case

    N = int(file_in.readline())
    xs = [] 
    for i in range(N):
        xs.append(X(i))
    for k in range(N-1):
        i, j = (int(s) for s in file_in.readline().split())
        connect(xs[i-1], xs[j-1])
    
    counter = 0
    consider = set(xs)
    while True:
        counter += 1
        changed = set()

        for x in consider:
            if x.update():
                changed.add(x)
            for y in x.adj:
                if y not in consider:
                    if y.update():
                        changed.add(y)
        if not changed:
            break

        consider = changed 

    print N, counter
    best = max(xs, key=lambda x: x.me_best)
            

    file_out.write("Case #%d: %d\n" % (i_case + 1, N - best.me_best))

file_in.close()
file_out.close()
