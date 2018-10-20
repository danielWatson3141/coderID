import math
#f_in = open('test.txt', 'r')
#f_out = open('test_out.txt', 'w')
if 1:
    f_in = open('A-small-attempt1.in', 'r')
    f_out = open('A-small.out', 'w')
if 0:
    f_in = open('A-large.in', 'r')
    f_out = open('A-large.out', 'w')

T = int(f_in.readline())
for case_id in range(T):
    N, L = [int(x) for x in f_in.readline().strip().split()]
    S = f_in.readline().strip().split()
    R = f_in.readline().strip().split()
    S_count = [sum([int(s[i]) for s in S]) for i in range(L)]
    R_count = [sum([int(r[i]) for r in R]) for i in range(L)]
    flips = [[0 for i in range(L)]]
    impossible = 0
    for i in range(L):
        if (S_count[i]+R_count[i])==N:
            M = len(flips)
            if S_count[i]==R_count[i]:
                for j in range(M):
                    new = flips[j][:];
                    new[i] = 1;
                    flips += [new];
            else:
                for j in range(M):
                    flips[j][i] = 1
            continue
        if S_count[i]!=R_count[i]:
            impossible = 1;
            break
    if impossible:
        f_out.write("Case #"+str(case_id+1)+": NOT POSSIBLE\n")
        continue
    for flip in flips:
        Si = S[:]
        impossible = 0
        for i in range(N):
            for j in range(L):
                if flip[j]:
                    if Si[i][j]=='1':
                        Si[i] = Si[i][:j]+'0'+Si[i][j+1:]
                    else:
                        Si[i] = Si[i][:j]+'1'+Si[i][j+1:]
#        if flip==[1, 1, 1, 1, 1, 1, 1, 0]:
#            print Si
        for s in Si:
            if s not in R:
                impossible = 1
                break
        if impossible ==0:
            break
    if impossible:
        f_out.write("Case #"+str(case_id+1)+": NOT POSSIBLE\n")
    else:
        f_out.write("Case #"+str(case_id+1)+": "+str(sum(flip))+"\n")
    print impossible
            
                    
            
#    r = 10000000000000000; t= 1000000000000000000;
#    r = 1; t = 1000000000000000000;
#    a = 2; b = 2*r-1; c = -t;
#    out = (-b+pow(b*b-4*a*c, 0.5))/(2*a)
#    out = int(math.floor(out))
#    while 2*out*out-out+2*r*out-t>0:
#        out -= 1
#    while 2*(out+1)*(out+1)-(out+1)+2*r*(out+1)-t<0:
#        out +=1
#    f_out.write("Case #"+str(case_id+1)+": "+str(out)+"\n")