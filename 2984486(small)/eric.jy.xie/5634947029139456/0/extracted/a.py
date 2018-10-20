from sys import stdin
T = int(stdin.readline().strip())
for t in xrange(T):
    l = stdin.readline().strip().split()
    N, L = int(l[0]), int(l[1])
    l = stdin.readline().strip().split()
    let = [ list(i) for i in l ] 
    l = stdin.readline().strip().split()
    dev = [ list(i) for i in l ] 

    flips = 0
    let.sort()
    dev.sort()
    flag = True
    for j in xrange(L):
        for i in xrange(N):
            if let[i][j] != dev[i][j]:
                flag = False
                break
        if not flag:
            flips += 1
            for i in xrange(N):
                if let[i][j] == '0':
                    let[i][j] = '1'
                else:
                    let[i][j] = '0'
            let.sort()
            dev.sort()
            flag = True
            for i in xrange(N):
                if let[i][j] != dev[i][j]:
                    flag = False
                    break
        if not flag:
            break
    if flag:
        print 'Case #%d: %d'%(t+1, flips)
    else:
        print 'Case #%d: NOT POSSIBLE'%(t+1)



