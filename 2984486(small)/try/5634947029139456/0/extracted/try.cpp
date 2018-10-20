#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 100
#define MAXL 40
#define INF 1000000000
using namespace std;

long long a[MAXN+1],b[MAXN+1];
int v[MAXN+1];
int n,l;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int c,t,i,j,k,s,mins;
    long long x;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d %d",&n,&l);
        for(i=0;i<n;i++)
        {
            for(j=0;j<l;j++)
            {
                scanf("%1I64d",&x);
                a[i]=a[i]|(x<<j);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<l;j++)
            {
                scanf("%1I64d",&x);
                b[i]=b[i]|(x<<j);
            }
        }
        mins=INF;
        for(i=0;i<n;i++)
        {
            x=a[0]^b[i];
            s=__builtin_popcountll(x);
            if(mins>s)
            {
                memset(v,0,sizeof(v));
                v[i]=1;
                for(k=1;k<n;k++)
                {
                    for(j=0;j<n;j++)
                    {
                        if((v[j]==0)&&((a[k]^b[j])==x))
                        {
                            v[j]=1;
                            break;
                        }
                    }
                    if(j>=n)
                    {
                        break;
                    }
                }
                if(k>=n)
                {
                    mins=s;
                }
            }
        }
        printf("Case #%d: ",c+1);
        if(mins<INF)
        {
            printf("%d\n",mins);
        }
        else
        {
            printf("NOT POSSIBLE\n");
        }
    }
    return 0;
}
