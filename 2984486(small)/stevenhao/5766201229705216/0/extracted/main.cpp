#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 1010;
const int inf = 1 << 30;

vector<int> conn[MAXN];

int T;
int N;

int DP[MAXN];
int get(int x, int prv = -1) {
  int &ret = DP[x];
  if (ret) return ret - 1;

  ret = 0;
  int mx = -inf;
  repi(i, conn[x]) {
    int nxt = *i;
    if (nxt == prv) continue;

    int val = get(nxt, x);
    if (val + mx > ret) ret = val + mx;
    if (val > mx) mx = val;
  }
  ++ret;

  return ret++;
}

int go() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    conn[i].clear();
  }


  for(int i = 1; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    conn[a].push_back(b);
    conn[b].push_back(a);
  }

  int ret = 1;
  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= N; ++j) {
      DP[j] = 0;
    }
    int ans = get(i);
    if (ans > ret) ret = ans;
  }

  return N - ret;
}

int main() {
  scanf("%d", &T);
  for(int t = 1; t <= T; ++t) {
    printf("Case #%d: ", t);
    int ans = go();
    printf("%d\n", ans);
  }
  return 0;
}
