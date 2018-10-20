#include<stdio.h>
#include<vector>
#define N 1010
#define INF 1000000000
using namespace std;
vector<int>G[N];
int subsz[N],dp[N];
void dfs(int i,int p){
    int cnt=0,M1=0,M2=0;
    subsz[i]=1;
    for(int j=0;j<G[i].size();j++)if(G[i][j]!=p){
        dfs(G[i][j],i);
        subsz[i]+=subsz[G[i][j]];
        if(M2<subsz[G[i][j]]-dp[G[i][j]])M2=subsz[G[i][j]]-dp[G[i][j]];
        if(M1<M2)swap(M1,M2);
        cnt++;
    }
    if(cnt==0)dp[i]=0;
    else if(cnt==1)dp[i]=subsz[i]-1;
    else dp[i]=subsz[i]-M1-M2-1;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n,ans=INF;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<=n-1;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            dfs(i,i);
            if(ans>dp[i])ans=dp[i];
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
