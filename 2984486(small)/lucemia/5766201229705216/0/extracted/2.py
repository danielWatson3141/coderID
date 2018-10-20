import StringIO
import sys
from collections import defaultdict

def check(m):
    root = None
    for a in m:
        cs = len(m[a])
        if cs == 2 and not root:
            # print 'root', a
            root = True
        elif cs not in (0, 1, 3):
            return False

    return True

def remove_node(m, node):
    m = dict(m)
    m.pop(node)
    for i in m:
        if node in m[i]:
            m[i].remove(node)

    # print 'remove', m, node
    return m

def main(input):
    T = int(input.readline())

    for i in range(T):
        m = defaultdict(lambda: set())

        print "Case #%s:"% (i+1),

        N = int(input.readline())
        # print N
        for n in xrange(N-1):
            x, y = map(int, input.readline().split())

            m[x].add(y)
            m[y].add(x)


        passed = []
        # print check(m)
        m = dict(m)
        movs = [(m, 0, set())]
        passed.append(set(m.keys()))
        # print movs
        # print m
        while movs:
            # print len(movs), len(passed), N
            if not movs:
                break
            movs.sort(key=lambda i:i[1])

            m, step, removed = movs.pop(0)
            # print '#', step

            if check(m):
                print step
                break

            # print m
            ks = [(k, len(m[k])) for k in m]
            ks.sort(key = lambda i: i[1])

            min_c = ks[0][1]
            # print 'min_c', min_c
            for k, connected in ks:
                if connected > min_c:
                    break

                node = k
                # print 'remove', node
                new_m = remove_node(m, node)
                removed = set(removed)
                removed.add(node)

                if not set(new_m.keys()) in passed:
                    movs.append((new_m, step+1,removed))
                    passed.append(set(new_m.keys()))

            # print len(movs), passed


inputs = sys.stdin
main(inputs)
