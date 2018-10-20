#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
set<int> G[1005];
int vcount;
map< pair<int,int>, int > memo;

int set_root(int par, int idx)
{
  const pair<int, int> p = make_pair(par, idx);
  if(memo.find(p) == memo.end() ) {
    vector<int> bs;
    for(set<int>::iterator it = G[idx].begin(); it != G[idx].end(); ++it) {
      if(*it == par) continue;
      bs.push_back(set_root(idx, *it));
    }
    if(bs.size() >= 2) {
      sort( bs.rbegin(), bs.rend() );
      memo[p] = 1 + bs[0] + bs[1];
    } else {
      memo[p] = 1;
    }
  }
  return memo[p];
}

void exec(int tn)
{
  int i, j, ans = 0;
  scanf("%d", &N);
 
  memo.clear();
  for(i = 0; i <= N; ++i) G[i].clear();

  for(i = 1; i < N; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].insert(y);
    G[y].insert(x);
  }

  for(i = 1; i <= N; ++i) {
    vcount = set_root(0, i);
    if(vcount > ans) ans = vcount;
  }

  printf("Case #%d: %d\n", tn, N - ans);
}

int main()
{
  int T, cn;
  scanf("%d", &T);
  for(cn = 1; cn <= T; ++cn) exec(cn);
  return 0;
}
