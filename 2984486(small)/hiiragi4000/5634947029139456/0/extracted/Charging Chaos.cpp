#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define N 160
#define L 50
#define INF 1000000000
using namespace std;
typedef long long ll;
int n;
char s[L];
ll a[N],b[N],c[N][N],x[N*N];
int match[2*N];
vector<int>G[N*N][2*N];
bool vis[2*N];
bool dfs(int i,int j){
    vis[j]=1;
    for(int k=0;k<G[i][j].size();k++)if(!match[G[i][j][k]]||!vis[match[G[i][j][k]]]&&dfs(i,match[G[i][j][k]])){
        match[j]=G[i][j][k];
        match[G[i][j][k]]=j;
        return 1;
    }
    return 0;
}
int max_matching(int i){
    int result=0;
    memset(match,0,sizeof(match));
    for(int j=1;j<=2*n;j++)if(!match[j]){
        for(int k=0;k<G[i][j].size();k++)if(!match[G[i][j][k]]){
            match[j]=G[i][j][k];
            match[G[i][j][k]]=j;
            result++;
        }
    }
    for(int j=1;j<=2*n;j++)if(!match[j]&&G[i][j].size()){
        memset(vis,0,sizeof(vis));
        if(dfs(i,j))result++;
    }
    return result;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int len,ans=INF;
        scanf("%d%d",&n,&len);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            a[i]=0;
            for(int j=0;j<len;j++)a[i]+=(ll)(s[j]-48)<<j;
        }
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            b[i]=0;
            for(int j=0;j<len;j++)b[i]+=(ll)(s[j]-48)<<j;
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            c[i][j]=a[i]^b[j];
            x[(i-1)*n+j-1]=c[i][j];
        }
        sort(x,x+n*n);
        int m=unique(x,x+n*n)-x;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)c[i][j]=lower_bound(x,x+m,c[i][j])-x;
        for(int i=0;i<m;i++)for(int j=1;j<=2*n;j++)G[i][j].clear();
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            G[c[i][j]][i].push_back(n+j);
            G[c[i][j]][n+j].push_back(i);
        }
        for(int i=0;i<m;i++){
            if(max_matching(i)==n){
                int cnt=0;
                for(int j=0;j<len;j++)if(x[i]&1<<j)cnt++;
                if(ans>cnt)ans=cnt;
            }
        }
        if(ans==INF)printf("Case #%d: NOT POSSIBLE\n",t);
        else printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
