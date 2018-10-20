#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1055;
const int INF = 10000000;
int T,n;
int cases=0;
vector<int> d[N];
int sum[N];
int f[N];
int res=INF;

void calc(int x,int parent)
{
    int cnt=0;
    if(d[x].size()==1 && parent!=-1){ //leaf_node
        sum[x]=1;
        f[x]=0;
        return;
    }
    vector<int> y;
    sum[x]=1;
    for(int i=0;i<d[x].size();i++){
        if(d[x][i]!=parent){
            y.push_back(d[x][i]);
            int c=y.size()-1;
            calc(y[c],x);
            sum[x]+=sum[y[c]];
        }
    }
    f[x]=min(f[x],sum[x]-1);
    for(int i=0;i<y.size();i++)
        for(int j=i+1;j<y.size();j++)
            f[x]=min(f[x],sum[x]-1-sum[y[i]]-sum[y[j]]+f[y[i]]+f[y[j]]);
}

void dp(int root)
{
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
        f[i]=INF;
    calc(root,-1);
    res=min(res,f[root]);
}

int main()
{
    int i,j,k;
    freopen("B-small-attempt1.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++cases);
        for(int i=0;i<=N;i++)
            d[i].clear();
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            d[u].push_back(v);
            d[v].push_back(u);
        }
        res=INF;
        for(int i=1;i<=n;i++)
            dp(i);
        printf("%d\n",res);
    }
}
