
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>
#include <limits>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

vector<int> g[1010];
bool visited[1010];

inline bool exist(int pat, int v) {
  return (pat & (1 << v)) != 0;
}

pair<int,bool> dfs(int p, int v, int pat) {
  int res = 1;
  int nChild = 0;
  REP(i, g[v].size()){
    int u = g[v][i];
    if(!exist(pat, u))
      continue;
    if(u == p)
      continue;
    nChild++;
    if(nChild >= 3)
      return make_pair(-1, false);
    pair<int,bool> hoge = dfs(v, u, pat);
    if(hoge.second == false)
      return make_pair(-1, false);
    res += hoge.first;
  }
  if(nChild == 0 || nChild == 2)
    return make_pair(res, true);
  return make_pair(-1, false);
}


int main(void) {
  int nCase;
  cin >> nCase;
  REP(iCase, nCase){
    int n;
    cin >> n;
    REP(i, n)
      g[i].clear();
    REP(i, n-1){
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    
    int res = n+1;
    REP(pat, 1 << n){
      int rest = __builtin_popcount(pat);
      int deleted = n - rest;
      if(deleted  >= res)
	continue;
      memset(visited, 0, sizeof visited);
      bool ok = false;
      REP(i, n){
	if(!exist(pat, i))
	  continue;
	pair<int,bool> tmp = dfs(n, i, pat);
	if(tmp.first == rest && tmp.second){
	  ok = true;
	  break;
	}
      }
      if(ok){
	res = deleted;
      }
    }
    printf("Case #%d: %d\n", iCase+1, res);
  }
  return 0;
}
