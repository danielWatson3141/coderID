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
string has[155],need[155];
char str[105];
bool rev[45];
int n,L;
bool used[45];

inline bool ok(int a,int b)
{
    memset(used,0,sizeof(used));
    used[b]=1;
    for(int i=0;i<n;++i)
    {
        if(i==a) continue;
        bool fg=0;
        for(int j=0;j<n;++j) if(!used[j])
        {
            bool f=1;
            for(int k=0;k<L;++k)
            {
                if(rev[k]&&need[i][k]==has[j][k])
                {
                    f=0; break;
                }
                if(!rev[k]&&need[i][k]!=has[j][k])
                {
                    f=0; break;
                }
            }
            if(f)
            {
                fg=used[j]=1;
                break;
            }
        }
        if(!fg) return false;
    }
    return true;
}

int main()
{
    int T;
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca)
    {
        scanf("%d%d",&n,&L);
        for(int i=0;i<n;++i)
        {
            scanf("%s",str);
            has[i]=str;
        }
        for(int i=0;i<n;++i)
        {
            scanf("%s",str);
            need[i]=str;
        }
        int ans=INF;
        for(int i=0;i<n;++i)
        {
            memset(rev,0,sizeof(rev));
            for(int j=0;j<n;++j)
            {
                int cnt=0;
                for(int k=0;k<L;++k) if(need[i][k]!=has[j][k]) rev[k]=1,++cnt;
                if(ok(i,j)) ans=min(ans,cnt);
            }
        }
        printf("Case #%d: ",ca);
        if(ans==INF) puts("NOT POSSIBLE");
        else printf("%d\n",ans);
    }
    return 0;
}
