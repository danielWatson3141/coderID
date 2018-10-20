#include <iostream>
#include <cstdio>
#include <algorithm>
#define P 1000000007
#define LL long long
#define N 100
using namespace std;
int n,m,ans;
int a[N],b[N],c[N];
void dfs(int d,int num)
{
    if (d==m)
    {
        for (int i=0;i<n;i++) c[i]=a[i];
        sort(c,c+n);
        for (int i=0;i<n;i++)
            if (c[i]!=b[i])
                return;
        ans=min(ans,num);
        return;
    }
    dfs(d+1,num);
    for (int i=0;i<n;i++) a[i]^=1<<d;
    if (num+1<ans) dfs(d+1,num+1);
    for (int i=0;i<n;i++) a[i]^=1<<d;
}
int main()
{
    //freopen("A.in","r",stdin);
    //freopen("a.out","w",stdout);
    int cnt;
    scanf("%d",&cnt);
    for (int run=1;run<=cnt;run++)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
        {
            getchar();
            a[i]=0;
            for (int j=0;j<m;j++)
                a[i]=a[i]*2+getchar()-'0';
        }
        for (int i=0;i<n;i++)
        {
            getchar();
            b[i]=0;
            for (int j=0;j<m;j++)
                b[i]=b[i]*2+getchar()-'0';
        }
        sort(b,b+n);
        ans=m+1;
        dfs(0,0);
        printf("Case #%d: ",run);
        if (ans<=m) printf("%d\n",ans);
        else printf("NOT POSSIBLE\n");
    }
    return 0;
}
