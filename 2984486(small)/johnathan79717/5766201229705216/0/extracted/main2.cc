#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;


int ones(LL a) {
  if(a == 0) return 0;
  return ones(a >> 1) + (a & 1);
}

V(bool) visited;
V(VI) adj;
VI deg;
VI comp;

// void dfs(int u, int m) {
//   if(visited[u]) return;
//   visited[u] = true;
//   FOR(v, adj[u]) {
//     if((1<<v) & m)
//       dfs(v, m);
//   }
// }

void dfs2(int u, int c) {
  if(comp[u]) return;
  comp[u] = c;
  FOR(v, adj[u])
    if(deg[v] >= 3)
      dfs2(v, c);
}

void dfs(int u, int &cnt) {
  visited[u] = true;
  cnt++;
  FOR(v, adj[u])
    if(!visited[v] && deg[v] >= 3)
      dfs(v, cnt);
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d: ", t);
    DRI(N);
    adj.resize(N);
    deg.resize(N);
    fill(ALL(deg), 0);
    fill(ALL(adj), VI());
    REP(i, N-1) {
      DRII(X, Y);
      X--; Y--;
      adj[X].PB(Y);
      adj[Y].PB(X);
      deg[X]++;
      deg[Y]++;
    }
    visited.resize(N);
    fill(ALL(visited), false);
    comp.resize(N);
    fill(ALL(comp), 0);
    int ans = 1;
    REP(v, N) {
      if(!visited[v] && deg[v] >= 3) {
        int cnt = 0;
        dfs(v, cnt);
        dfs2(v, cnt);
        ans = max(ans, (cnt-1) * 2 + 3);
      }
    }
    REP(v, N) {
      if(deg[v] == 2) {
        ans = max(ans, (comp[adj[v][0]] + comp[adj[v][1]]) * 2 + 3);
      }
    }
    ans = min(N, ans);
    PI(N - ans);
    // int ans = 0;
    // REP(mask, (1<<N)) {
    //   int k = ones(mask);
    //   bool fail = false, d2 = false;
    //   int dsum = 0;
    //   REP(i, N) {
    //     if(!((1<<i) & mask)) continue;
    //     int deg = 0;
    //     FOR(v, adj[i]) {
    //       if((1<<v) & mask) deg++;
    //     }
    //     if(deg == 0 || deg > 3 || (d2 && deg == 2)) {
    //       fail = true;
    //       break;
    //     }
    //     if(deg == 2)
    //       d2 = true;
    //     dsum += deg;
    //   }
    //   if(!fail && d2 && dsum == 2 * (k-1)) {
    //     fill(ALL(visited), false);
    //     REP(j, N) if((1<<j) & mask) {
    //       dfs(j, mask);
    //       break;
    //     }
    //     bool fail = false;
    //     for(auto b: visited) {
    //       if(!b) fail = true;
    //       break;
    //     }
    //     if(fail) continue;
    //     ans = max(ans, k);
    //   }
    // }
    // PI(N - ans);
  }
  return 0;
}
