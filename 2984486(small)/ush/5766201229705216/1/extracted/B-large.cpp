
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

int iCase;

int memo2[1010][1010];
int solve2(int parent, int v) {
  int& res = memo2[parent][v];
  if(res < 0){
    res = 1;
    REP(i, g[v].size()){
      int u = g[v][i];
      if(u != parent){
	res += solve2(v, u);
      }
    }
  }
  return res;
}

int memo[1010][1010];
int solve(int parent, int v) {
  int& res = memo[parent][v];
  if(res < 0){
    int total = 0;
    vector<int> vs;
    REP(i, g[v].size()){
      int u = g[v][i];
      if(u != parent){
	vs.push_back(solve(v, u) - solve2(v,u));
	total += solve2(v, u);
      }
    }
    
    sort(vs.begin(), vs.end());
//     reverse(vs.begin(), vs.end());
    int nChild = vs.size();
    if(nChild == 0){
      res = 0;
    }else if(nChild == 1){
      res = total;
    }else{
      res = total;
      total += vs[0];
      total += vs[1];
      res = min(res, total);
      assert(res >= 0);
    }
    if(iCase == 40){
      cerr << "solve(" << parent << ", " << v << ") = "  << res << endl;
    }
  }
  return res;
}


int main(void) {
  int nCase;
  cin >> nCase;
  for(iCase = 0; iCase < nCase; ++iCase){
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
      if(iCase == 40){
	cerr << a << " " << b << endl;
      }
    }
    memset(memo, -1, sizeof memo);
    memset(memo2, -1, sizeof memo2);
    int res = 1000000000;
    REP(i, n){
      int tmp = solve(n, i);
      res = min(res, tmp);
      if(iCase == 40){
	cerr << i << " -> " << tmp << endl;
      }
    }
    printf("Case #%d: %d\n", iCase+1, res);
    
    
  }
  return 0;
}
