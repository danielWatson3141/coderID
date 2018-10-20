#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;

const int N = 1010;
const ll M = 1000000009LL;
const int K = 3;
const int LIT = 2500;
const int INF = 1 << 30;
const ll MOD = 1000000007;
const int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int n;
vi r[N];

void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) r[i].clear();
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    r[u].pb(v);
    r[v].pb(u);
  }
}

int cal(int u, int root, int fa) {
  // printf("%d %d %d\n", u, root, fa);
  int sz = r[u].size();
  int tmp = sz - root;
  
  if (tmp <= 1) { // no more or only 1 left
    return 1;
  } else { // select 2
    vi opt;
    for (int i = 0; i < sz; i++) {
      int v = r[u][i];
      if (v == fa) {
        continue;
      }
      opt.pb(cal(v, 1, u));
    }
    sort(opt.begin(), opt.end());
    return 1 + opt[tmp - 1] + opt[tmp - 2];
  }
}

void solve(int tcase) {
  int Min = n * 10;
  for (int i = 1; i <= n; i++) {
    int tmp = n - cal(i, 0, -1);
    // printf("%d: %d\n", i, tmp);
    Min = min(Min, tmp);
  }
  printf("Case #%d: %d\n", tcase, Min);
}

int main() {
  int T, tcase;
  cin>>T;
  
  // T = 3;
  for (int i = 1; i <= T; i++) {
    init();
    solve(i);
  }
}