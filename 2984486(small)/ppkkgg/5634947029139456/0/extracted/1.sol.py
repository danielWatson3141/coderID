def strbool2int(a):
    b=0
    for i in range(len(a)):
        b+=int(a[(len(a)-1)-i])*2**i
    return b
    
def flip(p, j):
    return [x^j for x in p]
                    
def changerequired(p,d):
    for ed in d:
        if not ed in p:
            return 1
    return 0
    
infile=r'C:\Users\prasun\Downloads\A-small-attempt1.in'
outfile=r'C:\Users\prasun\Downloads\a-small-out-01.txt'
ip=open(infile,'r')
t=int(ip.readline().strip())
#print t
ans=''
for i in range(t):
    ans+='Case #%d: ' %(i+1)
    n,l=map(int,ip.readline().strip().split())
    power=map(strbool2int, ip.readline().strip().split())
    devices=map(strbool2int, ip.readline().strip().split())
    #print power, devices
    change=changerequired(power, devices)            
    if change:
        pos=0
        for j in range(2**l+1):
            newpower=flip(power, j)
            if not changerequired(newpower,devices):
                ans+=str(sum([int(x) for x in bin(j)[2:]]))
                pos=1
                break
        if not pos:
            ans+='NOT POSSIBLE'
    else:
        ans+='0'
    ans+='\n'
    print i
ip.close()
#print ans

op=open(outfile,'w')
op.write(ans)
op.close()
