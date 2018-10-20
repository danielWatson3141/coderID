#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cout << __LINE__ << ' ' << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;

//ハマったらチェックリスト見ろ!!

const int N = 1000;

vector<int> G[N];

int cnt[N][N];
int dp[N][N];


int calc(int from, int now){
  int &ret = cnt[from][now];
  if(ret != -1)return ret+1;
  ret = 0;
  FOR(it, G[now]){
    if(*it == from)continue;
    ret += calc(now, *it);
  }
  return ret + 1;
}

int solve(int from, int now){
  int &ret = dp[from][now];
  if(ret != -1)return ret;
  if((from == now) + G[now].size() < 3){
    ret = 0;
    FOR(it, G[now]){
      if(*it == from)continue;
      ret += calc(now, *it);
    }
    return ret;
  }
  ret = 1e9;
  int sum = 0;
  rep(i, G[now].size()){
    if(G[now][i] == from)continue;
    sum += calc(now, G[now][i]);
  }
  rep(i, G[now].size()){
    if(G[now][i] == from)continue;
    REP(j, i+1, G[now].size()){
      if(G[now][j] == from)continue;
      ret = min(sum - calc(now, G[now][i]) - calc(now, G[now][j]) + solve(now, G[now][i]) + solve(now, G[now][j]), ret);
    }
  }
  return ret;
}


int main(){
  int T;
  cin >> T;
  rep(tc, T){
    cout << "Case #" << tc+1<<": ";
    rep(i, N)G[i].clear();
    int n;
    cin >> n;
    rep(i, n-1){
      int a, b;
      cin >> a >>b;
      a--;b--;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    rep(i, n)rep(j, n)dp[i][j] = cnt[i][j] = -1;
    int ans = 1e9;
    rep(i, n){
      ans = min(ans, solve(i, i));
    }
    cout <<ans <<endl;
  }
  return 0;
}
