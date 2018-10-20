#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<cctype>
#include<cmath>
#include<sstream>
#include<bitset>
#include<ctime>
using namespace std;
#define LL long long
#define CLR(x,y) memset(x,y,sizeof(x))
template<class T> inline int maximize(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline int minimize(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const int N=1005,INF=0x3f3f3f3f;
struct Edge
{
    int v;
    Edge* next;
}E[N+N+5],*tot,*head[N];
int n,u,v;
void add(int u,int v)
{
    tot->v=v;
    tot->next=head[u];
    head[u]=tot++;
}

int dfs(int u,int fa=-1)
{
    int ret=1,ch=0;
    int mx=0,mxx=0;
    for(Edge* p=head[u];p;p=p->next)
    {
        if(p->v==fa) continue;
        int t=dfs(p->v,u);++ch;
        if(t>mx)
        {
            mxx=mx;
            mx=t;
        }
        else if(t>mxx)
        {
            mxx=t;
        }
    }
    if(ch>=2) return ret+mx+mxx;
    return ret;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("yy.txt","w",stdout);
    ios::sync_with_stdio(false);
    int T;cin>>T;
    for(int cs=1;cs<=T;++cs)
    {
        tot=E;CLR(head,0);
        cin>>n;
        for(int i=1;i<n;++i)
        {
            cin>>u>>v;
            add(u,v);add(v,u);
        }
        int ans=INF;
        for(int i=1;i<=n;++i)
        {
            minimize(ans,n-dfs(i));
//            cout<<i<<" "<<ans<<endl;
        }
        printf("Case #%d: %d\n",cs,ans);
    }
    return 0;
}
