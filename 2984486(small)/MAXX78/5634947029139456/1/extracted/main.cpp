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
LL a[NN],b[NN],c[NN];

LL fun(char *p)
{
    int i;
    LL ans=0;
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
    freopen("E:\\A-large.in","r",stdin);
    freopen("E:\\A-large.out","w",stdout);

    int cas,ee=0;
    int n,l,t,i,j,k,ans;
    LL temp;
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

        sort(b+1,b+1+n);
        ans=100;



        for(i=1;i<=1;i++)
        {
            for(j=1;j<=n;j++)
            {
                temp=a[i]^b[j];
                t=0;
                for(k=0;k<l;k++)
                {
                    if((1LL<<k)&temp)
                    {
                        t++;
                    }
                }

             //   cout<<"temp=="<<temp<<endl;

                for(k=1;k<=n;k++)
                {
                    c[k]=a[k]^temp;
                }
                sort(c+1,c+1+n);

                for(k=1;k<=n;k++)
                    if(c[k]!=b[k])
                        break;
                if(k==n+1)
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
