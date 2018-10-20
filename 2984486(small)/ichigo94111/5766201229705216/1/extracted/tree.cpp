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
    int max1=0,max2=0;
    for(int i=0;i<d[x].size();i++){
        if(d[x][i]!=parent){
            y.push_back(d[x][i]);
            int c=y.size()-1;
            calc(y[c],x);
            sum[x]+=sum[y[c]];
            int tt=sum[y[c]]-f[y[c]];
            if(max1<tt){
                max1=tt;
            }
            else max2=max(max2,tt);
        }
    }
    f[x]=min(f[x],sum[x]-1);
    if(y.size()>=2) f[x]=min(f[x],sum[x]-1-max1-max2);
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
    freopen("B-large.in","r",stdin);
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
