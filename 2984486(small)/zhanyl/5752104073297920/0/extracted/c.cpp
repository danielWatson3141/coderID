#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

const int maxn=1005;

int n,g[maxn];
int p[maxn],x;
bool flag;
int ans[1000];
double f[1000];

int main()
{
    //freopen("c-in.txt","r",stdin);
    //freopen("c-out.txt","w",stdout);
    freopen("C-small-attempt3.in","r",stdin);
    freopen("C-small-attempt3.out","w",stdout);
    //freopen("C-large.in","r",stdin);
    //freopen("C-large.out","w",stdout);
    int t,a=0,b=0;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        flag=true;
        int c=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&g[i]);
            if(g[i]==i)flag=false;
            if(g[i]<i)c++;
        }
        if(flag)
        {
            a++;
            ans[cas]=1;
            f[cas]=c*c/(double)a;
        }
        else
        {
            ans[cas]=0;
            b++;
        }
    }
    while(b<t/2)
    {
        int x=-1;
        for(int i=1;i<=t;i++)
            if(ans[i]==1&&(x==-1||f[x]>f[i]))x=i;
        ans[x]=0;
        b++;
    }
    for(int cas=1;cas<=t;cas++)
    if(ans[cas])printf("Case #%d: GOOD\n",cas);
    else printf("Case #%d: BAD\n",cas);
    return 0;
}
