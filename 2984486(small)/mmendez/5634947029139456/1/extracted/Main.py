def solve():
    T = int(reader.r())+1
    for t in xrange(1,T):
        case = "Case #%d: %s"
        N = int(reader.r())
        L = int(reader.r())
        OL = [int(reader.r(), 2) for i in xrange(N)]
        CL = [int(reader.r(), 2) for i in xrange(N)]
        best = 200
        for i in OL:
            for j in CL:
                x = i ^ j
                b = True
                for k in CL:
                    y = k ^ x
                    if not y in OL:
                        b = False
                        break
                if b:
                    temp = bin(x).count("1")
                    if temp < best:
                        best = temp
        if best < 200:
            print >>fout, case % (t, str(best))
        else:
            print >>fout, case % (t,"NOT POSSIBLE")

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
