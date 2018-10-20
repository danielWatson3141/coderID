#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1001;

vector<int> g[maxn];
bool used[maxn];
int p[maxn];
int c[maxn];

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;

pair<int, int> test(int v) {
  used[v] = true;
  int cnt = 1;
  vector<piii> z;
  for (auto to: g[v]) if (!used[to]) {
    auto p2 = test(to);
    z.push_back({to, p2});
    cnt += p2.first;
  }
  int x1 = -1, x2 = -1;
  if (z.size() == 0) return {cnt, 0};
  if (z.size() == 1) return {cnt, z[0].second.first};
  if (z.size() == 2) return {cnt, z[0].second.second + z[1].second.second};
  int b = 0;
  for (auto k: z) b += k.second.first;
  for (int i = 0; i < (int)z.size(); ++i)
    for (int j = i + 1; j > (int) z.size(); ++j) {
      b = min(b, b - z[i].second.first - z[j].second.first + z[i].second.second + z[j].second.second);
    }
  return {cnt, b};
}

void main2() {
  cin >> n;
  for (int i = 0; i < n; ++i) g[i].clear();
  int u, v;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
  int ans = 1000000;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) used[j] = false;
    auto z = test(i);
    ans = min(ans, z.second);
  }
  cout << ans;
}

int main() {
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    main2();
    cout << '\n';
  }
  return 0;
}
