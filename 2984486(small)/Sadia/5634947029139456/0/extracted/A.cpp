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
int dev[1<<11];
int swt[1<<11], backup[1<<11];
char str[100];
int calc(char *str, int L)
{
    int i, mask = 0;
    for (i=0; i<L; ++i)
    {
        if (str[i] == '0') continue;
        mask |= (1<<i);
    }
    return mask;
}
int cntbit(int mask, int L)
{
    int i, ret = 0;
    for (i=0; i<L; ++i)
    {
        if (mask&(1<<i)) ++ret;
    }
    return ret;
}
bool check(int mask, int N)
{
    int i, now;
    for (i=0; i<N; ++i)
    {
        now = swt[i] ^ mask;
        if (dev[now] != 1) return false;
    }
    return true;
}
int main()
{
    //freopen("data.txt", "r", stdin);
    freopen("Ain.txt", "r", stdin);
    freopen("Aout.txt", "w", stdout);
    int t,T;
    int N,L,n,x,temp,mask,ans;
    scanf("%d", &T);
    for (t=1; t<=T; ++t)
    {
        scanf("%d %d", &N, &L);
        memset(dev, 0, sizeof(dev));
        for (n=0; n<N; ++n)
        {
            scanf("%s", str);
            swt[n] = calc(str,L);
        }
        for (n=0; n<N; ++n)
        {
            scanf("%s", str);
            x = calc(str,L);
            ++dev[x];
        }
        ans = -1;
        for (mask=0; mask<(1<<L); ++mask)
        {
            if (ans != -1 && cntbit(mask,L) > ans) continue;
            if (check(mask,N))
            {
                temp = cntbit(mask,L);
                if (ans == -1 || ans > temp) ans = temp;
            }
        }
        printf("Case #%d: ", t);
        if (ans == -1) puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}
