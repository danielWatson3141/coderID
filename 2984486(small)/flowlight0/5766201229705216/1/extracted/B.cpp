#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(auto i = (c).begin(); i != (c).end(); ++i)
#define BIT(n, m) (((n) >> (m)) & 1)

typedef long long ll;

const ll inf = 1e15;
const ll mod = 1000 * 1000 * 1000 + 7;
const double eps = 1e-9;

int dfs(int v, int p, const vector<vector<int> > &G){
  vector<int> cost;
  for (auto w : G[v]){
    if (w != p) cost.push_back(dfs(w, v, G));
  }
  sort(ALL(cost));

  int res = 1;
  
  if ((int)cost.size() >= 2){
    res += cost[cost.size() - 1];
    res += cost[cost.size() - 2];
  }
  
  return res;
}

void solve(){
  int N, A, B;
  cin >> N;
  vector<vector<int> > G(N);
  
  REP(i, N - 1){
    cin >> A >> B;
    A--, B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  int res = 1e9;
  REP(i, N){
    res = min(res, N - dfs(i, -1, G));
  }
  cout << res << endl;
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
    cout << "Case #" << t + 1 << ": ";
    solve();
  }
  return 0;
}
