#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

int n;
vector<vector<int> > G;
vector<bool> T;

pii dfs(int v) {
    T[v]=true;
    int poc=0;
    int dokopy=0,p=0,d=0;
    For(i,G[v].size()) {
        int w=G[v][i];
        if(T[w]) continue;
        poc++;
        pii pom=dfs(w);
        dokopy+=pom.first;
        int roz=pom.first-pom.second;
        if(d<roz) d=roz;
        if(p<d) swap(p,d);
    }
    if(poc<2) return mp(dokopy+1,dokopy);
    return mp(dokopy+1,dokopy-p-d);
}

void solve(int num) {
    scanf("%d",&n);
    G.clear(); G.resize(n);
    T.clear(); T.resize(n,false);
    For(i,n-1) {
        int x,y;
        scanf("%d %d",&x,&y);
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int res=n+47;
    For(i,n) {
        T.clear(); T.resize(n,false);
        pii vys=dfs(i);
        res=min(res,vys.second);
    }
    printf("Case #%d: %d\n",num,res);
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
return 0;
}
