__author__ = 'j0hnny'

NOT_POSSIBLE = 'NOT POSSIBLE'


def match(curr, req):
    m = []
    for c in curr:
        m.append([x for x in c])

    for r in req:
        if m.count(r) > 0:
            m.remove(r)
        else:
            return False
    return True

def switch(curr, i):
    new = []
    for d in range(len(curr)):
        new.append([x for x in curr[d]])
        if new[d][i] == 0:
            new[d][i] = 1
        else:
            new[d][i] = 0
    return new


def find(curr, req, index):
    if index == len(curr[0]):
        return len(curr[0])+1, len(curr[0])
    if match(curr, req):
        return 0, len(curr[0])
    elif match(switch(curr, index), req):
        return 1, len(curr[0])

    (r1, l) = find(curr, req, index+1)
    (r2, l) = find(switch(curr, index), req, index+1)
    r2 += 1
    if r1 < r2:
        return r1, l
    else:
        return r2, l

if __name__ == '__main__':
    sol = []
    with open('A-small-attempt2.in', 'r') as input:
        cases = int(input.readline())
        for case in range(cases):

            (devices, outs) = input.readline().split()

            m = [x for x in input.readline().split()]
            c = []
            for x in m:
                l = []
                for y in x:
                    l.append(int(y))
                c.append(l)

            m = [x for x in input.readline().split()]
            r = []
            for x in m:
                l = []
                for y in x:
                    l.append(int(y))
                r.append(l)

            sol.append(find(c, r, 0))

with open('output', 'w') as output:
        for case in range(cases):
            r, l = sol[case]
            if r > l:
                s = 'Case #%d: %s\n' % (case+1, NOT_POSSIBLE)
            else:
                s = 'Case #%d: %d\n' % (case+1, r)
            print s
            output.write(s)