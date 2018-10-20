def countRemoved(tree, node, visited):
    v = visited[:]
    v.append(node)
    c = tree[node][:]
    s = 1
    for i in c:
        if not i in v:
            s += countRemoved(tree, i, v)
    return s

def count(tree, node, visited):
    v = visited[:]
    c = tree[node][:]
    for i in v:
        if i in c:
            c.remove(i)
    v.append(node)
    if len(c) == 0:
        return 0
    elif len(c) == 1:
        return countRemoved(tree, c[0], v)
    elif len(c) == 2:
        return count(tree, c[0], v) + count(tree, c[1], v)
    else:
        m = [-10000, -10000]
        r = [-1, -1]
        e = [0, 0]
        s = 0
        for i in c:
            t = countRemoved(tree, i, v)
            t2 = count(tree, i, v)
            s += t
            x = t - t2
            if m[0] == -10000:
                r[0] = t2
                e[0] = t
                m[0] = x
            elif x > m[1] or (x == m[1] and t > e[1]):
                r[1] = t2
                e[1] = t
                m[1] = x
                if x > m[0] or (x == m[0] and t > e[0]):
                    r[1] = r[0]
                    e[1] = e[0]
                    m[1] = m[0]
                    r[0] = t2
                    e[0] = t
                    m[0] = x
        s -= e[0]
        s -= e[1]
        return s + r[0] + r[1]

def solve():
    T = int(reader.r())+1
    for t in xrange(1,T):
        case = "Case #%d: %d"
        N = int(reader.r())
        conn = {}
        for i in xrange(1,N):
            a = int(reader.r())
            b = int(reader.r())
            if conn.has_key(a):
                conn[a].append(b)
            else:
                conn[a] = [b]
            if conn.has_key(b):
                conn[b].append(a)
            else:
                conn[b] = [a]
        m = N - 1
        for i in xrange(1,N+1):
            x = count(conn, i, [])
            if x < m:
                m = x
                if x == 0:
                    break
        print >>fout, case % (t,m)

class reader:
    buffer = []
    @staticmethod
    def r():
        if not reader.buffer:
            #reader.buffer = raw_input().split()
            reader.buffer = fin.readline().rstrip().split()
        temp = reader.buffer[0]
        reader.buffer = reader.buffer[1:]
        return temp
    @staticmethod
    def rl():
        return fin.readline().rstrip()
        #return raw_input()

#solve()
fin = open('test.in', 'r')
fout = open('test.out', 'w')
solve()
fin.close()
fout.close()
