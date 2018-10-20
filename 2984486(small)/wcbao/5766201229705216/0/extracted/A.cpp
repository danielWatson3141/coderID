#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#define clr(A) memset(A,0,sizeof(A))
#define mm 100005
#define eps  (1e-8)
using namespace std;
typedef long long LL;
typedef pair<int,int > P;
typedef unsigned int ULL;
const int INF = 10000000;

vector<int> by[mm],bc[mm];
int x[mm],y[mm];
int N,X,Y;
int num[mm];

int dfs(int u,int fa){
    num[u] = 1;
    bc[u].resize(0);
    for(int i = by[u].size()-1;i>=0;i--){
        int v = by[u][i];
        if(v==fa) continue;
        int res = dfs(v,u);
        bc[u].push_back(num[v]-res);
        num[u]+=num[v];
    }
    sort(bc[u].begin(),bc[u].end());
    if(bc[u].size()<2) return num[u]-1;
    int Sz = bc[u].size()-1;
    return num[u]-1-bc[u][Sz]-bc[u][Sz-1];
}
int main()
{
     int T,C = 0;
//    freopen("BUAA.in","r",stdin);
//    freopen("gcj.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++C);
        scanf("%d",&N);
        for(int i =1;i<=N;i++)
        {
            by[i].resize(0);
        }
        for(int i =1;i<N;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            by[x].push_back(y);
            by[y].push_back(x);
        }
        int ans = N-1;
        for(int i =1;i<=N;i++)
        {
            fill(num,num+N+2,0);
            ans = min(ans,dfs(i,0));
        }
        printf("%d\n",ans);
    }
    return 0;
}
