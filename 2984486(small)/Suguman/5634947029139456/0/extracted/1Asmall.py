def flip(s, ar):
    s1 = ''
    j = 0
    for i in ar:
        while(j < i):
            s1 = s1 + s[j]
            j += 1 
        if j == i:
            if s[i] == '1':
                s1 = s1+'0'
            else:
                s1 = s1+'1'
        j += 1
    'print(s1+s[j:])'
    return s1+s[j:]
           

infile = open('/home/suguman/Desktop/A-small-attempt0(1).in','r')
outfile = open('/home/suguman/Desktop/output1.txt','w')

x = int(infile.readline())

for i in range(x):
    line1 = infile.readline().split()
    N = int(line1[0])
    L = int(line1[1])
    print(N, L)
    outlet = sorted(infile.readline().strip().split())
    print(outlet)
    inlet = sorted(infile.readline().strip().split())
    print (inlet)
    min_trials = L
    sol = False
    for k in outlet:
        dif_ar = []
        num_flips = 0
        ans = False
        for j in range(L):
            if (inlet[0][j] != k[j]):
                num_flips += 1
                dif_ar.append(j)
        'print(dif_ar)'
        out = []
        for s in outlet:
            out.append(flip(s, dif_ar))
        out = sorted(out)
        print(out)
        ans = (out == inlet)
        if ans == True:
            if num_flips < min_trials:
                min_trials = num_flips
                print(ans, min_trials)
                sol = True
    
    if sol == True:
        outfile.write('Case #'+str(i+1)+': ' + str(min_trials)+'\n')
    else:
        outfile.write('Case #'+str(i+1)+': ' + 'NOT POSSIBLE'+'\n')
                
