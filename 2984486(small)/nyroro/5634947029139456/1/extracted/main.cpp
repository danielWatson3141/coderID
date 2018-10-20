#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 200;
int uN, vN; // u, v数目，要初始化！！！
int L;
long long g[MAXN][MAXN]; // g[i][j] 表示xi与yj相连
int xM[MAXN],yM[MAXN]; // 输出量
bool chk[MAXN]; // 辅助量检查某轮y[v]是否被check
bool SearchPath(int u,long long val)
{
    int v;
    for(v = 0; v < vN; v++)
        if(g[u][v]==val && !chk[v])
        {
            chk[v] = true;
            if(yM[v] == -1 || SearchPath(yM[v],val))
            {
                yM[v] = u;
                xM[u] = v;
                return true ;
            }
        }
    return false ;
}
int MaxMatch(long long val)
{
    int u, ret = 0 ;
    memset(xM, -1, sizeof (xM));
    memset(yM, -1, sizeof (yM));
    for(u = 0; u < uN; u++)
        if(xM[u] == -1)
        {
            memset(chk, false, sizeof (chk));
            if(SearchPath(u,val)) ret++;
        }
    return ret;
}
long long arr1[MAXN];
long long arr2[MAXN];
char str[50];
long long change(const char str[])
{
    int len=strlen(str);
    long long ret=0;
    for(int i=0;i<len;i++)
    {
        ret=(ret<<1)+str[i]-'0';
    }
    return ret;
}
int digit(long long a)
{
    int ret=0;
    while(a)
    {
        ret+=(a%2);
        a>>=1;
    }
    return ret;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int ti=1;ti<=t;ti++)
    {
        scanf("%d%d",&uN,&L);
        vN=uN;

        for(int i=0;i<uN;i++)
        {
            scanf("%s",str);
            arr1[i]=change(str);
        }
        for(int i=0;i<vN;i++)
        {
            scanf("%s",str);
            arr2[i]=change(str);
        }

        for(int i=0;i<uN;i++)
        {
            for(int j=0;j<vN;j++)
            {
                g[i][j]=(arr1[i]^arr2[j]);
            }
        }
        int ans=100000;
        for(int j=0;j<vN;j++)
        {
            if(MaxMatch(g[0][j])==uN)
            {
                ans=min(ans,digit(g[0][j]));
            }
        }
        printf("Case #%d: ",ti);

        if(ans>L)
        {
            printf("NOT POSSIBLE\n");
        }
        else
            printf("%d\n",ans);
    }
    return 0;
}
