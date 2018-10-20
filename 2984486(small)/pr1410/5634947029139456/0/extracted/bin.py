f=open('/Users/pruthvikarreddy/Downloads/A-small-attempt2.in').read()
a = open('/Users/pruthvikarreddy/Downloads/outbin.txt','w')

c=0
v=f.splitlines()
i=1
def countones(k):
    return bin(k).count('1')
for ix,x in enumerate(v[1::3]):
    m,l=[int(x) for x in v[i].split(' ')]
    dd={int(x,2) for x in v[i+1].split(' ')}
    od={int(x,2) for x in v[i+2].split(' ')}
    d={bin(x) for x in dd}
    o={bin(x) for x in od}
    matched=False
    nums=sorted(range(2**l),key=countones)
    for j in nums:
        
        os={x^j for x in od}

        if m== len(dd.intersection(os)):
            matched=True
            break
        
    switch=False
    i+=3
    if matched:
        print 'Case #'+str(ix+1)+': '+str(bin(j).count('1'))
        a.write('Case #'+str(ix+1)+': '+str(bin(j).count('1'))+'\n')
    else:
        print 'Case #'+str(ix+1)+': NOT POSSIBLE'
        a.write('Case #'+str(ix+1)+': NOT POSSIBLE'+'\n')
    
    