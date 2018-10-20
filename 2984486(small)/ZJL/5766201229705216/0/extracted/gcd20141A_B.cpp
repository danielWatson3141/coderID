#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1010];
bool vis[1010];
vector<int>G[1010];
void dfs(int rt){
    //cout<<rt<<endl;
    vis[rt] = true;

    vector<int>ans;
    ans.clear();
    for(int i = 0; i < G[rt].size(); i++){
        int v = G[rt][i];
        if(vis[v]) continue;
        dfs(v);
        ans.push_back(dp[v]);
    }
    sort(ans.begin(),ans.end());
    if(ans.size() == 1){
         dp[rt] = 1;return;
    }else if(ans.size() == 0){
         dp[rt] = 1; return;
    }
    int h = ans.size();
    dp[rt] = 1 + ans[h-1] + ans[h-2];
}
int main(){
    int T;
    freopen("B-small-attempt0 (2).in","r",stdin);
    freopen("B.out","w",stdout);
    cin>>T;
    for(int cas = 1; cas <= T; cas++ ){
        //cout<<cas<<endl;
        int n;
        cin>>n;
        //cout<<n<<endl;
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i < n; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            //cout<<x<<" "<<y<<endl;
            G[x].push_back(y);
            G[y].push_back(x);
        }
       // cout<<"s";
        int ans = 0;
        for(int i = 1; i <= n; i++){
            memset(vis,0,sizeof(vis));
            dfs(i);
            ans = max(ans,dp[i]);
        }
        printf("Case #%d: %d\n",cas,n - ans);

    }
    return 0;
}
