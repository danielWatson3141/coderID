#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<n; i++)
typedef long long int64;

typedef pair<int,int> pii;

#define N 1050
int nad[N], g[N][N];

pii dfs(int x, int p) {
    int sz=1, cost=0, vz=0;

    vector<int> ord;
    REP(i,nad[x]) {
        int y=g[x][i];
        if (p==y) continue;

        pii s = dfs(y,x);
        sz+=s.first;
        cost+=s.second;
        vz++;
        ord.push_back(s.first);
    }

    if (vz==0 || vz==2)
        return pii(sz,cost);
    if (vz==1)
        return pii(1,cost+sz-1);
    sort(ord.begin(),ord.end());

    int sf=0;
    REP(i,vz-2)
        sf+=ord[i];

    return pii(sz-sf, cost+sf);
}


int main() {
    int nt,n;

    scanf("%d",&nt);
    REP(ct,nt) {
        scanf("%d",&n);

        memset(nad,0,sizeof(nad));
        REP(i,n-1) {
            int a,b;
            scanf("%d %d",&a,&b);
            a--; b--;
            g[a][nad[a]++]=b;
            g[b][nad[b]++]=a;
        }

        int res=INF;
        REP(i,n)
            res=min(res, dfs(i,-1).second);

        printf("Case #%d: %d\n",ct+1,res);
    }
    return 0;
}
