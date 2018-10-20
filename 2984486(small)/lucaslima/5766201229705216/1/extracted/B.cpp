#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) fr(i,0,n)
#define cl(a,b) memset((a), (b), sizeof(a))
#define all(c) (c).begin(), (c).end()
#define _ << ", " <<
#define db(x) cerr << #x " == " << x << endl

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
const int inf = 0x3f3f3f3f;

vector<int> adj[1010];

int memo_go[1010][1010];
int memo_solve[1010][1010];

int go(int u, int pai) {
  int& ret = memo_go[u][pai];
  if (~ret) return ret;
  ret = 1;
  for (int v : adj[u]) {
    if (v != pai) ret += go(v, u);
  }
  return ret;
}

int solve(int u, int pai) {
  int& ret = memo_solve[u][pai];
  if (~ret) return ret;  
  ii best = {0, -1}, nd_best = {0, -1};
  int ct = 0;
  int filho = -1;
  for (int v : adj[u]) {
    if (v == pai) continue;
    ++ct;
    filho = v;
    int cost = go(v,u) - solve(v, u);
    if (cost > nd_best.first) nd_best = {cost, v};
    if (nd_best.first > best.first) swap(best, nd_best);      
  }
  if (ct == 0) ret = 0;
  else if (ct == 1) ret = go(filho, u);
  else {
    ret = 0;
    for (int v : adj[u]) {
      if (v == pai) continue;
      if (v != best.second and v != nd_best.second) {
        ret += go(v,u);
      } else {
        ret += solve(v,u);
      }
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int testcase = 1; testcase <= t; ++testcase) {
    int n;
    scanf("%d", &n);
    rep(i,n) adj[i].clear();
    rep(i,n-1) {
      int x, y;
      scanf("%d %d", &x, &y);
      --x; --y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    int rsp = inf;
    cl(memo_go, -1);
    cl(memo_solve, -1);
    rep(i, n) {
      rsp = min(rsp, solve(i, n + 1));
    }
    printf("Case #%d: %d\n", testcase, rsp);
  }
  return 0;
}
