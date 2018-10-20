//GCJ round 1A a
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#define MAXN 152
#define MAXL 42
#define INF 1000000000
using namespace std;
int N,L;
char c[MAXL];
vector<int>a,b;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int Case,ans,cnt;
    scanf("%d",&Case);
    for(int ca=1;ca<=Case;++ca)
    {
        scanf("%d%d",&N,&L);
        a.clear();
        b.clear();
        ans=INF;
        cnt=0;
        for(int i=0;i<N;++i)
        {
            scanf("%s",c);
            int x=0;
            for(int j=0;j<L;++j)
            {
                if(c[j]=='0') x*=2;
                else x=x*2+1;
            }
            a.push_back(x);
        }
        for(int i=0;i<N;++i)
        {
            scanf("%s",c);
            int x=0;
            for(int j=0;j<L;++j)
            {
                if(c[j]=='0') x*=2;
                else x=x*2+1;
            }
            b.push_back(x);
        }
        sort(b.begin(),b.end());
        for(int i=0;i<(1<<L);++i)
        {
            int x=i;
            for(int j=0;j<N;++j)
            {
                a[j]^=i;
            }
            sort(a.begin(),a.end());
            bool tmp=0;
            for(int j=0;j<N;++j)
            {
                if(a[j]!=b[j])
                {
                    tmp=1;
                    break;
                }
            }
            for(int j=0;j<N;++j)
            {
                a[j]^=i;
            }
            if(tmp) continue;
            cnt=0;
            for(int j=0;j<L;++j)
            {
                if( (1<<j)&x) cnt++;
            }
            ans=min(ans,cnt);
        }
        printf("Case #%d: ",ca);
        if(ans==INF) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
