#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > GG;
vector<vector<int> > G;
int dp[1001][1001][3];
vector<int> dp2;

void sub(int node, int parent) {
  for(int v: GG[node]) {
    if(v == parent)continue;
    for(int i = 0; i < 3; i++)
      dp[node][G[node].size()][i] = -1;
    G[node].push_back(v);
    sub(v, node);
  }
  for(int i = 0; i < 3; i++)
    dp[node][G[node].size()][i] = -1;
}
void construct_tree(int root){
  G = vector<vector<int> >(GG.size());
  dp2 = vector<int>(GG.size(), -1);
  sub(root, root);
}
int count(int v) {
  if(dp2[v] >= 0)return dp2[v];
  int ret = 1;
  for(int vv: G[v]) {
    ret += count(vv);
  }
  return dp2[v] = ret;
}
int solve(int v, int k, int used) {
  if(k == G[v].size()) {
    if(used == 0 || used == 2)
      return 0;
    return 999999;
  }
  if(dp[v][k][used] >= 0)return dp[v][k][used];
  int ret = 999999;
  if(used < 2) {
    ret = min(ret, solve(G[v][k], 0, 0) + solve(v, k + 1, used + 1));
  }
  ret = min(ret, solve(v, k + 1, used) + count(G[v][k]));
  return ret;
}
int main () {
  int TC;
  cin>>TC;
  for(int testCase = 1; testCase <= TC; testCase++) {
    cout << "Case #" << testCase << ": ";
    int N;
    cin>>N;
    GG = vector<vector<int> >(N);
    for(int i = 0; i < N - 1; i++){
      int x,y;
      cin>>x>>y;
      GG[x-1].push_back(y-1);
      GG[y-1].push_back(x-1);
    }
    int ret =  99999999;
    for(int i = 0; i < N; i++){
      construct_tree(i);
      ret = min(solve(i, 0, 0), ret);
    }
    cout << ret << endl;
  }
}
