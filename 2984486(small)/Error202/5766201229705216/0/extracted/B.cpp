#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
typedef unsigned long long  LL;
using namespace std ;
typedef pair<int,int> PII;

vector<int> a[1100];
int f[1100][3];

void dfs(int u,int p){
    f[u][0]=0; f[u][1]=f[u][2]=INT_MAX>>1; 
    for (vector<int>::iterator it=a[u].begin();it!=a[u].end();it++){
        int v=*it;
        if (v==p) continue;
        dfs(v,u);
        int c=f[v][0]+1,d=min(f[v][0],f[v][2]);
        f[u][2]=min(f[u][2]+c,f[u][1]+d);
        f[u][1]=min(f[u][1]+c,f[u][0]+d);
        f[u][0]+=c;
    }
}

int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int _;
    scanf("%d",&_);
    for (int k=1;k<=_;k++){
        int N,i,u,v;
        scanf("%d",&N);
        for (i=1;i<=N;i++) a[i].clear();
        for (i=1;i<N;i++){
            scanf("%d%d",&u,&v);
            a[u].push_back(v); a[v].push_back(u);
        }
        int ans=INT_MAX;
        for (i=1;i<=N;i++){
            dfs(i,0);
            ans=min(ans,min(f[i][0],f[i][2]));
        }
        printf("Case #%d: %d\n",k,ans);
    }
}
