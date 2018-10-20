import sys, copy

class tr(object):
    def __init__(self, n):
       self.n = n
       self.e = []
       self.c = 0

def subtree(N, root):
    ret = 1
    # print [n.e for n in N], 'children', N[root].e
    for c in N[root].e:
        Nc = copy.deepcopy(N) 
        Nc[root].e.remove(c)
        Nc[c].e.remove(root)
        ret += subtree(Nc, c)
    return ret 

def count(N, root):
    en = len(N[root].e)
    Nr = copy.deepcopy(N) 
    sr = subtree(Nr, root) 
    if(en == 1):
        return sr-1
    else:
        min_count = sr-1
        for f in range(en-1):
            for s in range(f+1, en):
                fe, se = N[root].e[f], N[root].e[s]
                Nf = copy.deepcopy(N) 
                Nf[root].e.remove(fe)
                Nf[fe].e.remove(root)
                
                Ns = copy.deepcopy(N) 
                Ns[root].e.remove(se)
                Ns[se].e.remove(root)

                Nfs, Nss = (copy.deepcopy(Nf), copy.deepcopy(Ns))
                cf, cs = (count(Nf, fe), count(Ns, se))
                sf, ss = (subtree(Nfs, fe), subtree(Nss, se))
                cnt = cf - sf + cs - ss + sr -1
                # print root, ":", cf, cs, sf, ss, sr, cnt
                if cnt < min_count:
                    min_count = cnt
        # print min_count
        return min_count
    
idata = [line for line in sys.stdin ]
T = int(idata[0].rstrip())
ofs = 1
for t in range(T):
    N = int(idata[ofs].rstrip())
    No = [tr(i+1) for i in range(N)]
    E = [ [ int(e) for e in idata[ofs+n+1].rstrip().split(' ') ] for n in range(N-1)]
    for e in E:
        No[e[0]-1].e.append(e[1]-1)
        No[e[1]-1].e.append(e[0]-1)

    print E
    print 'N: ', [n.e for n in No]
    C = [count(No, n) for n in range(N)]
    # print C
    c = min(C)

    ofs += N
    print 'Case #%d: %d' % (t+1, c)
