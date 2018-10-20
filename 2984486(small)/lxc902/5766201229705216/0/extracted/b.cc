#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<iostream>
#include<cmath>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;

const int N = 2100;

struct Eg {
    int v,nxt;
} e[N*2];
int en,h[N];
void init() {
    en=0;mem(h,-1);
}
void adde(int u,int v) {
    e[en].v=v;
    e[en].nxt=h[u];
    h[u]=en++;
}

int n;

int son[N];
int dp[N];
void dfs(int x,int p) {
    son[x]=1;
    for(int i=h[x];~i;i=e[i].nxt) if(e[i].v!=p) {
        dfs(e[i].v,x);
        son[x]+=son[e[i].v];
    }
}
int da(int x,int p) {
    if(~dp[x]) return dp[x];
    int cnt=0;
    for(int i=h[x];~i;i=e[i].nxt) if(e[i].v!=p) {
        cnt++;
    }
    if(cnt<2) return dp[x]=1;
    int mx,mx2;
    mx=mx2=0;
    for(int i=h[x];~i;i=e[i].nxt) if(e[i].v!=p) {
        int d=da(e[i].v,x);
        if(d>mx) {
            mx2=mx;
            mx=d;
        } else if(d>mx2) {
            mx2=d;
        }
    }
    return dp[x]=1+mx+mx2;
}

int gao(int rt) {
    dfs(rt,-1);
    mem(dp,-1);
    return da(rt,-1);
}

int main()
{
	int T; scanf("%d",&T);
	for(int ka=1;ka<=T;ka++) {
        scanf("%d",&n);
        init();
        for(int i=1;i<n;i++) {
            int u,v;scanf("%d%d",&u,&v);
            adde(u,v);adde(v,u);
        }
        int ans=1;
        for(int i=1;i<=n;i++) ans=max(ans,gao(i));
        printf("Case #%d: %d\n",ka,n-ans);
	}

    return 0;
}
