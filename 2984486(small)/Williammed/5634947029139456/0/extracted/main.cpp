#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

char s[205];
long long a[205], b[205], c[205];
int n,l;

bool check(long long t)
{
    for (int i=0; i<n; i++)
        c[i]=a[i]^t;
    sort(c, c + n);
    for (int i=0; i<n; i++)
        if (c[i]!=b[i])
            return false;
    return true;
}

int count_bit(long long x)
{
    int ret=0;

    while (x)
    {
        if(x%2)
            ret++;
        x /= 2;
    }
    return ret;
}

int main()
{
    int cas,ca=1;

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d",&n,&l);
        for (int i=0;i<n;i++)
        {
            scanf("%s", s);
            a[i]=0;
            for (int j=0;j<l;j++)
                a[i]=2*a[i]+s[j]-'0';
        }
        for (int i=0;i<n;i++)
        {
            scanf("%s", s);
            b[i]=0;
            for (int j=0;j<l;j++)
                b[i]=2*b[i]+s[j]-'0';
        }
        sort(b, b + n);
        int ans = -1;
        for (int i=0;i<n;i++)
        {
            long long tmp = a[0] ^ b[i];
            int cnt=count_bit(tmp);
            if (!check(tmp))
                continue;
            if (ans==-1||cnt<ans)
                ans=cnt;
        }
        if (ans == -1)
            printf("Case #%d: NOT POSSIBLE\n", ca++);
        else
            printf("Case #%d: %d\n", ca++, ans);
    }

    return 0;
}
