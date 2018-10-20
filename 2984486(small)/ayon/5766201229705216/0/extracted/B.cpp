#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<limits.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);


typedef long long LL;





vector<int> ADJ[1020];
int vis[1020];
int dp2[1020];//dp

void INI()
{
    int i;
    for(i=0;i<1010;i++) ADJ[i].clear();
    memset(vis,0,sizeof(vis));
}

void ini()
{
    int i;
    memset(vis,0,sizeof(vis));
}



void dfs2(int u)
{
    int i,v;
    vis[u]=1;
    vector<int> ch;
    for(i=0;i<ADJ[u].size();i++)
    {
        v=ADJ[u][i];
        if(vis[v]) continue;
        dfs2(v);
        ch.push_back(dp2[v]);
    }

    dp2[u]=1;
    sort(ch.begin(),ch.end());
    if(ch.size()>=2)
    {
        dp2[u]=max(dp2[u],ch[ch.size()-1]+ch[ch.size()-2]+1);
    }
}






int main()
{
    freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);



    int i,j,k,T,n,cs,v,u;
    scanf("%d",&T);


    for(cs=1;cs<=T;cs++)
    {
        INI();
        printf("Case #%d: ",cs);
        scanf("%d",&n);

        for(i=0;i<(n-1);i++)
        {
            scanf("%d %d",&u,&v);
            u--;
            v--;

            ADJ[u].push_back(v);
            ADJ[v].push_back(u);
        }


        int ans=n;
        for(i=0;i<n;i++)
        {
            ini();
            dfs2(i);
            ans=min(ans,n-dp2[i]);
        }

        printf("%d\n",ans);

    }


    return 0;
}
