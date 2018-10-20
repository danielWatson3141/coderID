#include <stdio.h>
#include <stdlib.h>
#define ULL unsigned long long int
#define LL long long int
#define GC() getchar()

LL ex(int x, int y)
{
    LL out;
    if(y == 1) return x;
    if(y == 0) return 1;
    LL z = ex(x, y/2);
    if(y % 2) out = z*z*x;
    else out = z*z;
    return out;
}

LL frombin(int L)
{
    LL out = 0;
    int i;
    char c = GC();
    while(c != '1' && c!= '0') c = GC();
    for(i = 0; i < L; i++)
    {
        if(c == '1') out += ex(2, L-i-1);
        c = GC();
    }
    return out;
}

int check(LL device[], LL test[], int N)
{
    int flag;
    int i, j;
    for(i=0; i<N; i++)
    {
        flag = 0;
        for(j=0; j<N; j++)
        {
            if(device[i] == test[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0) return 0;
    }
    return 1;
}

int binsum(int n)
{
    int out = 0;
    while(n>0)
    {
        out += n%2;
        n /= 2;
    }
    return out;
}


int fastinput()
{
    char c = GC();
    int sum = 0;
    while(c<'0'||c>'9') c=GC();
    while(c>='0'&&c<='9') 
    {
        sum = (sum<<3) + (sum<<1) + c - '0';
        c = GC();
    }
    return sum;
}

void flip(LL outlet[],LL  test[],LL testnum,int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        test[i] = outlet[i]^testnum;
        //printf("test[%d] = %lld\n",i, test[i]);
    }
}

LL su(LL arr[], int n)
{
    LL sum=0;
    for(int i = 0; i<n; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int main()
{
    int T;
    int N, L;
    int i, j;
    scanf("%d", &T);
    for(i=1; i<=T; i++)
    {
        scanf("%d %d", &N, &L);
        LL device[N], outlet[N], test[N];
        LL sumtest=0, sumdev=0;
        LL testnum;
        int ans, testans, ansflag=1;
        for(j=0; j<N; j++)
        {
            outlet[j] = frombin(L);
            test[j] = outlet[j];
            //sumtest += test[j];
            //printf("outlet[%d] = %lld\n", j, outlet[j]);
        }
        for(j=0; j<N; j++)
        {
            device[j] = frombin(L);
            sumdev += device[j];
            //printf("device[%d] = %lld\n", j, device[j]);
        }
        LL limit = ex(2, L);
        for(testnum = 0; testnum < limit; testnum++)
        {
            //printf("testnum = %lld\n", testnum);
            flip(outlet, test, testnum, N);
            sumtest = su(test, N);
            //sumdev = su(device, N);
            if(sumtest == sumdev) 
            {
                if(check(device, test, N)==1)
                {            
                    testans = binsum(testnum);
                    if(ansflag ==1) 
                    {
                        ans = testans;
                        ansflag = 0;
                    }
                    else
                    {
                        if(testans<ans) ans = testans;
                    }
                }
            }
        }
        if(ansflag==1) printf("Case #%d: NOT POSSIBLE\n", i);
        else printf("Case #%d: %d\n",i, ans);
    }
    return 0;
} 
    