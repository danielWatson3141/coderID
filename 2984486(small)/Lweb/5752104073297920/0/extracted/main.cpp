//Immanuel
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long LL;
double p[1005][1000];
double sum[1005];
double t[1005];
int a[1005];

int main()
{
    memset(p,0,sizeof(p));
    for(int i=0;i<1000;++i) p[i][i]=1;
    for(int i=0;i<1000;++i)
    {
        for(int j=0;j<1000;++j) if(i!=j)
        {
            memcpy(t,p[j],sizeof(t));
            for(int k=0;k<1000;++k)
            {
                p[j][k]+=p[i][k]/1000;
                p[i][k]-=p[i][k]/1000;
            }
            for(int k=0;k<1000;++k)
            {
                p[i][k]+=t[k]/1000;
                p[j][k]-=t[k]/1000;
            }
        }
    }
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<1000;++i) scanf("%d",a+i);
        double res=1;
        for(int i=0;i<1000;++i)
        {
            double d=0;
            for(int j=0;j<i;++j) d+=p[i][a[j]];
            d=p[i][a[i]]/(1-d);
            res*=d;
            res*=(i+1);
        }
        printf("Case #%d: ",ca);
        if(res<1) puts("GOOD");
        else puts("BAD");
    }
    return 0;
}
