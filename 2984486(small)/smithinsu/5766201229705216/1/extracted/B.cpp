#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >

vector < VI > edge;
PII dfs(int cur, int par) {
  int total = 1;
  int del = 0;
  int sz = edge[cur].size();
  int max1 = -1;
  int max2 = -1;
  for(int i=0;i<sz;i++) {
    int nx = edge[cur][i];
    if(par != nx) {
      PII rec = dfs(nx, cur);
      total += rec.second;
      int save = rec.second - rec.first;
      if(save >= max1) {
        max2 = max1;
        max1 = save;
      } else if(save >= max2) {
        max2 = save;
      }
    }
  }
  del = total - 1 - ((max2 == -1) ? 0 : (max1+max2));
  return MP(del, total);
}

int main() {
  int T;
  cin>>T;
  int kase = 1;
  int n;
  while(T--) {
    cin>>n;
    edge.clear();
    edge.resize(n);
    for(int i=0;i+1<n;i++) {
      int u,v;
      cin>>u>>v;
      assert(u <= n);
      assert(v <= n);
      u--;v--;
      edge[v].PB(u);
      edge[u].PB(v);
    }
    int ans = n-1;
    for(int i=0;i<n;i++) {
      ans = min(ans, dfs(i,-1).first);
    }
    printf("Case #%d: %d\n",kase++, ans);
  }
  return 0;
}
