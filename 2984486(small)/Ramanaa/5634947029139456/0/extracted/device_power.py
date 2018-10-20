def chk(dev,bits,inp,out):
    a=comp(dev,inp,out)
    if a==1:
        return str(0)
    

    i=0
    while i < 2**bits:
        #flap
        swap_str = gen_swap(bits,i)
        j=0
        m=[]
        
        while j < dev:
            ha=my_and(bits,inp[j],swap_str)
            
            m.append(ha)
            #print m
            j=j+1
        m.sort()
        #print inp,swap_str,m,out
        chk=comp(dev,m,out)
        if chk==1:
            lp=count1(swap_str)
            return str(lp)
        
        i=i+1
    return "NOT POSSIBLE"

def count1(swap_str):
    j=0
    count=0
    while j<len(swap_str):
        if swap_str[j]=="1":
            count=count+1
        j=j+1
    return count    
    
            
def my_and(bits,inp,swap_str):
    soln=""
    i=0
    
    
    while i<bits:
        
        if swap_str[i]=="1":
            if inp[i]=="1":
                soln=soln+"0"
            else:
                soln=soln+"1"
        else:
            soln=soln+inp[i]
                
        
        i=i+1
    
    return soln    
        


def comp(dev,inp,out):
    i=0
    flag=0
    while i < dev :
        if inp[i] != out[i]:
            flag=1
            break
        i=i+1
    if flag==0:
        return 1
    else:
        return 0

def gen_swap(bits,pos):
    k=str(bin(pos))
    k=k[2:]
    i=len(k)
    sol=k
    
    while i <bits:
        sol="0"+sol
        i=i+1
    return sol
  
    
        

file=open("c:/users/rhv/Desktop/code_jam/2014/dev_swtch_2.in","r")
file1=open("c:/users/rhv/Desktop/code_jam/2014/switch_dev_out.txt","w")
m=file.readline()
i=0
l = m.split()


while i<int(l[0]):
    input=[]
    output=[]
    m1=file.readline()
    m2=m1.split()
    m3=file.readline()
    m3=m3.split()
    m4=file.readline()
    m4=m4.split()
    m3.sort()
    m4.sort()
    print i
    ans = chk(int(m2[0]),int(m2[1]),m3,m4)
    
    d = "Case #" + str(i+1) +": "+ans+"\n"
    file1.write(d)
    i=i+1

file.close()
file1.close()
