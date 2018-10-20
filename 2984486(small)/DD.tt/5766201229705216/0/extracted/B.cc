#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;
const int INF = 1000000000;

int T, N, x, y;

int size[1005];
int f[1005];
int end[2222];
int g[1005];
int next[2222];
int father[1005];
int cnt;

void addedge(int x, int y) {
  end[cnt] = y;
  next[cnt] = g[x];
  g[x] = cnt++;
}

bool cmp(const PII& A, const PII& B) {
  return size[A.second] - A.first > size[B.second] - B.first;
}

int check(int root) {
  size[root] = 1;
  f[root] = 0;
  vector<PII> v;
  for (int i = g[root]; i != -1; i = next[i]) {
    int y = end[i];
    if (father[root] == y) {
      continue;
    }
    father[y] = root;
    int tmp = check(y);
    size[root] += size[y];
    v.push_back(make_pair(tmp, y));
  }
  if (v.size() >= 2) {
    sort(v.begin(), v.end(), cmp);
    f[root] += v[0].first;
    f[root] += v[1].first;
    for (int i = v.size() - 1; i >= 2; --i) {
      f[root] += size[v[i].second];
    }
  } else {
    f[root] = size[root] - 1;
  }
  return f[root];
}

void clear() {
  memset(g, -1, sizeof(g));
  memset(next, -1, sizeof(next));
  cnt = 0;
}

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B.out", "w", stdout);
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    scanf("%d", &N);
    int ans = INF;
    clear();
    for (int i = 1; i < N; ++i) {
      scanf("%d%d", &x, &y);
      addedge(x, y);
      addedge(y, x);
    }
    for (int root = 1; root <= N; ++root) {
      memset(father, 0, sizeof(father));
      ans = min(ans, check(root));
    }
    printf("Case #%d: %d\n", test, ans);
  }
  return 0;
}

