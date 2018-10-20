#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<utility>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
set < long long > dev;
long long swt[156];
char str[100];
long long calc(char *str, long long L)
{
    long long i, mask = 0;
    for (i=0; i<L; ++i)
    {
        if (str[i] == '0') continue;
        mask |= (1LL<<i);
    }
    return mask;
}
long long cntbit(long long mask, long long L)
{
    long long i, ret = 0;
    for (i=0; i<L; ++i)
    {
        if (mask&(1LL<<i)) ++ret;
    }
    return ret;
}
bool check(long long mask, long long N)
{
    long long i, now;
    for (i=0; i<N; ++i)
    {
        now = swt[i] ^ mask;
        if (dev.find(now) == dev.end()) return false;
    }
    return true;
}
int main()
{
    //freopen("data.txt", "r", stdin);
    freopen("Ain.txt", "r", stdin);
    freopen("Aout.txt", "w", stdout);
    long long t,T;
    long long N,L,n,x,temp,mask,ans,i;
    vector < long long > VM;
    scanf("%lld", &T);
    for (t=1; t<=T; ++t)
    {
        scanf("%lld %lld", &N, &L);
        dev.clear();
        VM.clear();
        VM.push_back(0);
        for (n=0; n<N; ++n)
        {
            scanf("%s", str);
            swt[n] = calc(str,L);
        }
        for (n=0; n<N; ++n)
        {
            scanf("%s", str);
            x = calc(str,L);
            dev.insert(x);
            for (i=0; i<N; ++i) VM.push_back(x^swt[i]);
        }
        ans = -1;
        for (i=0; i<VM.size(); ++i)
        {
            mask = VM[i];
            if (ans != -1 && cntbit(mask,L) > ans) continue;
            if (check(mask,N))
            {
                temp = cntbit(mask,L);
                if (ans == -1 || ans > temp) ans = temp;
            }
        }
        printf("Case #%lld: ", t);
        if (ans == -1) puts("NOT POSSIBLE");
        else printf("%lld\n", ans);
    }
    return 0;
}
