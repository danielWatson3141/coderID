#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long

const int MaxN = 1020;

int dp[MaxN][MaxN];
int sub[MaxN][MaxN];
int mark[MaxN][MaxN];
int runID;

int N;
vector<int> adj[MaxN];

int V[MaxN];

void go(int p, int x) {
  if(mark[p][x] == runID) return ;
  mark[p][x] = runID;
  // first calc sub
  int&x_sub = sub[p][x], deg = 0;
  x_sub=1;
  for(int i=0;i<adj[x].size();++i)
    if(adj[x][i] != p){
      go(x, adj[x][i]);
      x_sub += sub[x][adj[x][i]];
      deg ++;
    }
  int&ret = dp[p][x];
  // directly to leaf
  ret = x_sub - 1;
  // to media level node
  if(deg >= 2) {
    int c = 0, base = 0;
    for(int i=0;i<adj[x].size();++i) {
      int u = adj[x][i];
      if(u == p) continue;
      V[c] = dp[x][u] - sub[x][u];
      base += sub[x][u];
      c++;
    }
    nth_element(V,V+1,V+c);
    ret = min(ret, base + V[0] + V[1]);
  }
}

int run() {
  runID++;
  scanf("%d", &N);
  for(int i=0;i<=N;++i) adj[i].clear();
  for(int i=1;i<N;++i){
    int x,y;
    scanf("%d %d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int ans = N - 1;
  for(int i=1;i<=N;++i) {
    go(0, i);
    ans = min(ans, dp[0][i]);
  }
  return ans;
}

int main() {
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int test;
  scanf("%d", &test);
  for(int no=1;no<=test;++no){
    printf("Case #%d: %d\n", no, run());
  }
}

/*
3
3
2 1
1 3
7
4 5
4 2
1 2
3 1
6 4
3 7
4
1 2
2 3
3 4
*/
