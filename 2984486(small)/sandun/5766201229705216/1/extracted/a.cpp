#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<iomanip>
#include<utility>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
const int maxn = 1111;
const int inf = 0x7f7f7f7f;
const int mod = (int)(1e9+7);
const LL INF = 1LL<<50;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int mask = 65535;
char s[maxn];
int a[maxn];
int b[maxn];
LL A[maxn];
LL B[maxn];
int x[maxn];
int get(LL n){
    int ans=0;
    while(n){
        n = n&(n-1);
        ++ans;
    }
    return ans;
}
vector<int>edge[maxn];
int dp[maxn][2];
int sz[maxn];
void dfs(int u,int pre){
    vector<int>::iterator it;
    int v;
    int tag=0,sum=0;
    dp[u][0]=1;
    dp[u][1]=0;
    vector<int>vt;
    for(it=edge[u].begin();it!=edge[u].end();++it){
        v=*it;
        if(v==pre)
            continue;
        ++tag;
        dfs(v,u);
        dp[u][0] += dp[v][0];
        sum += dp[v][0];
        vt.push_back(dp[v][1]-dp[v][0]);
    }
    //printf("u %d v  %d\n",u, dp[u][0]);
    if(tag==1){
        dp[u][1]=dp[u][0]-1;
    }
    if(tag>1){
        int sz=edge[u].size();
        sort(vt.begin(),vt.end());
        sum += vt[0] + vt[1];
        dp[u][1] = sum;
    }
   // printf("u %d v %d %d\n",u,dp[u][0],dp[u][1]);
    if(!tag){
        dp[u][0]=1;
        dp[u][1]=0;
    }
}
void solve(){
    int n,u,v,i;
    scanf("%d",&n);
    for(i=0;i<maxn;++i){
        edge[i].clear();
    }
    for(i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int ans=222222;
    for(i=1;i<=n;++i){
        dfs(i,-1);
        v=min(dp[i][0],dp[i][1]);
    //    printf("%d %d\n",i,v);
        ans=min(ans,v);
    }
    printf("%d\n",ans);
}
int main(){
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int T,cas;
    scanf("%d",&T);
    for(cas=1;cas<=T;++cas){
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}
