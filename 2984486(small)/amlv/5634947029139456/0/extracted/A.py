__author__ = 'Ana'


__author__ = 'Ana'



import sys

def main():

    inName=''
    outName=''


    if inName is not '' :
        sys.stdin=open(inName,'r')


    if outName is not '':
        sys.stdout=open(outName,'w')


    file=sys.stdin
    T=int(file.readline())
    for i in range(T):
        values=file.readline().split(' ')
        n,l=int(values[0]),int(values[1])

        flows=file.readline().rstrip().split(' ')
        req=file.readline().rstrip().split(' ')
        flips=[-1]*l
        for j in range(l):
            if get_ones(j,flows)==get_ones(j,req):
                flips[j]=0
            if get_ones(j,flows)==n-get_ones(j,req):
                if flips[j]==0:
                    flips[j]=2
                else:
                    flips[j]=1


        poss_ans=[flows]
        for j in range(l):
            if flips[j]==1 :
                for c in poss_ans:
                    for k in range(n):
                        m=list(c[k])
                        if m[j]=='0':
                            m[j]='1'
                        else:
                            m[j]='0'
                        c[k]=''.join(m)


        count=0
        flag=0
        for v in poss_ans:
            for j in range(n):
                 if  req.__contains__(v[j]):
                     flag+=1

        for j in range(l):
            if flips[j]==1:
                count+=1
        if flag<n:
            print 'Case #'+ str(i+1)+': NOT POSSIBLE'

        else:
            print 'Case #'+ str(i+1)+': '+str(count)



def flip(s,j):
    m=list(s)
    if m[j]=='0':
         m[j]='1'
    else:
         m[j]='0'

    return ''.join(m)


def main1():

    inName='A-small-attempt2.in.txt'
    outName=''


    if inName is not '' :
        sys.stdin=open(inName,'r')


    if outName is not '':
        sys.stdout=open(outName,'w')


    file=sys.stdin
    T=int(file.readline())
    for i in range(T):
        values=file.readline().split(' ')
        n,l=int(values[0]),int(values[1])
        line=file.readline().rstrip()

        req=file.readline().rstrip().split(' ')
        min=100000
        for j in range(n):
            flips=[False]*l
            flows=line.split(' ')
            for k in range(l):
                if flows[j][k]!=req[0][k]:
                    flips[k]=True
            for k in range(l):
                for m in range(n):
                    if flips[k]:
                        flows[m]=flip(flows[m],k)

            count=0
            flag=0
            for v in flows:
                if  req.__contains__(v):
                         flag+=1
            if flag==n:
                for t in flips:
                    if t:
                        count+=1
                if count<min:
                    min=count

        if min<10000:
            print 'Case #'+ str(i+1)+': '+str(min)
        else:
            print 'Case #'+ str(i+1)+': NOT POSSIBLE'

def get_ones(index,values):
    ans=0
    for s in values:
        if s[index]=='1':
            ans+=1
    return ans






main1()