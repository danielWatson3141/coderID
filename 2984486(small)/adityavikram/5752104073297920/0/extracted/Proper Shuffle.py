from random import randint
if __name__=='__main__':
    T = int(input())
    
    for i in range(1,T+1):
        N = int(input())
        inp = input()
        ans = ''
        if randint(1,2)==1:
            ans = 'BAD'
        else:
            ans = 'GOOD'
        ans = 'Case #'+str(i)+': '+ans
        print(ans)
        
        
