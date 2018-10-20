//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<map>
#include<set>
using namespace std;
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back(x)
typedef long long LL;
//typedef unsigned __int64 ULL;
/* ****************** */
const int INF=1000111222;
const double INFF=1e100;
const double eps=1e-8;
const int mod=1000000007;
const int NN=505;
const int MM=401010;
/* ****************** */

char ss[100];
int a[NN],b[NN],c[NN];

int fun(char *p)
{
    int i;
    int ans=0;
    for(i=0;ss[i];i++)
    {
        ans<<=1;
        if(ss[i]=='1')
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("E:\\A-small-attempt0.in","r",stdin);
    freopen("E:\\A-small-attempt0.out","w",stdout);

    int cas,ee=0;
    int n,l,t,i,j,mask,ans;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&l);
        for(i=1;i<=n;i++)
        {
            scanf("%s",ss);
            a[i]=fun(ss);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%s",ss);
            b[i]=fun(ss);
        }
        mask=1<<l;

        sort(b+1,b+1+n);
        ans=100;
        for(i=0;i<mask;i++)
        {
            t=0;
            for(j=0;j<l;j++)
            {
                if((1<<j)&i)
                    t++;
            }
            for(j=1;j<=n;j++)
            {
                c[j]=a[j]^i;
            }
            sort(c+1,c+1+n);
            for(j=1;j<=n;j++)
            {
                if(c[j]!=b[j])
                    break;
            }
            if(j==n+1)
            {
                ans=min(ans,t);
            }
        }

        printf("Case #%d: ",++ee);
        if(ans==100)
        {
            puts("NOT POSSIBLE");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}
