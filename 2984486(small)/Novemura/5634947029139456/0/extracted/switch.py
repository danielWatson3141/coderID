import datetime

def main():
    filename='A-small-attempt0.in'
    F=open(filename,'r')
    inputdata=F.read()
    F.close
    inputdata=inputdata.split('\n')
    T=int(inputdata[0])
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        N,L=[int(num) for num in inputdata[3*q+1].split(' ')]
        init=[int(num,2) for num in inputdata[3*q+2].split(' ')]
        req=[int(num,2) for num in inputdata[3*q+3].split(' ')]
        ans=getswitch(N,L,init,req)
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        answer.append('Case #'+str(q+1)+': '+ans+'\n')
        
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()

def getswitch(N,L,init,req):
    sinit=sorted(init)
    sw=100000
    for i in range(2**L):
        reqsw=[i^app for app in req]
        
        #print sinit
        
        sreq=sorted(reqsw)
        #print sreq
        if sreq==sinit:
         #   print 'here'
            sww=getones(i)
            if sw>sww:
                sw=sww
    if sw>L:
        return 'NOT POSSIBLE'
    else:
        return str(sw)
        
def getones(i):
    ret=0
    while i>0:
        ret+=i%2
        i=i/2
    return ret