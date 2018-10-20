#!/usr/bin/python

import sys

T = int(sys.stdin.readline())

def dpcopy(complList):
    if isinstance(complList, list):
        return list( map(dpcopy, complList) )
    return complList


for c in xrange(0,T):
#for c,line in enumerate(sys.stdin):
    print 'Case #{}:'.format(c+1),    
    
    # N, L = map(int, line.strip().split())
    N, L = map(int, sys.stdin.readline().strip().split())
    
    sockets = sys.stdin.readline().strip().split() # N of L length
    dev = sys.stdin.readline().strip().split() # N of L length
    
    sockets = map(list, sockets)
    dev =  map(list, dev)

    
    sw = 0
    dual_idx = []
    
    # print >>sys.stderr, sockets, dev, N, L
    
    for t in xrange(0,L):
        zero = [0,0]
        for r in xrange(0,N):
            if sockets[r][t] == '0':
                zero[0] += 1                
            if dev[r][t] == '0':
                zero[1] += 1
        
        # print >>sys.stderr, zero
        
        if zero[0] == zero[1]:
            if zero[0] == N - zero[0]:
                #Duality
                dual_idx.append(t)                            
        elif zero[0] == N - zero[1]:
            if zero[0] == N - zero[0]:
                #Duality
                dual_idx.append(t)
                            
            else:
                #Switch              
                sw += 1
                for r in xrange(0,N):
                    if sockets[r][t] == '0':
                        sockets[r][t] = '1'
                    else:
                        sockets[r][t] = '0'
        else:
            sw = 'NOT POSSIBLE'
            dual_idx = []
            break
    
    if dual_idx:
        # print >>sys.stderr, 'Duality', dual_idx
        min = sys.maxint        
        # Check duality
        
        for d in dev:
            if d not in sockets:
                break
        else:
            print sw
            continue

        # print >>sys.stderr, 'Not direct'
        
        varz = 2**len(dual_idx)

        # sockets = map(list, sockets)
        # 
        for i in xrange(1, varz):
            # print >>sys.stderr, 'Check', bin(i)
            
            if min != sys.maxint and min <= bin(i).count("1"):
                continue

            s = dpcopy(sockets)
            for d in xrange(len(dual_idx)):
                # print >>sys.stderr, i, d, i & 2**d
                if i & 2**d:
                    # print >>sys.stderr, 'Switch!'
                    #switch
                    for r in xrange(0,N):
                        if s[r][dual_idx[d]] == '0':
                            s[r][dual_idx[d]] = '1'
                        else:
                            s[r][dual_idx[d]] = '0'
                            
            # print >>sys.stderr, 'New s: ', s, dev             
            # s=map(lambda x: ''.join(x), s)
            for d in dev:
                if d not in s:
                    # print >>sys.stderr, 'd not in s: ', d,s  
                    break
            else:
                if bin(i).count("1") < min: 
                    min = bin(i).count("1")
                    
                # print >>sys.stderr, 'New min: ', min 
                # print sw + bin(i).count("1")
                # break
        else:
            if min != 0:
                print sw + min
            else:
                print 'NOT POSSIBLE'
    else:
        print sw
                    
                    
                    
                    
                    
                    