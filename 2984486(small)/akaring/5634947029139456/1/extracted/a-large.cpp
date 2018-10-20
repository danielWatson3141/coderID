#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

int n, l;

vector<string> a, b;

inline void flip(char &c) {
  c = c == '0' ? '1' : '0';
}

int count(vector<string> &sv, int j) {
  int ret = 0;
  for (string s: sv) {
    ret += s[j] == '1';
  }
  return ret;
}

bool check(int j) {
  vector<string> x, y;
  REP (i, n) {
    x.PB(a[i].substr(0, j));
    y.PB(b[i].substr(0, j));
  }
  sort(ALL(x));
  sort(ALL(y));
  return x == y;
}

int ans;

void dfs(int j, int counter) {
  if (j == l) {
    checkMin(ans, counter);
  } else {
    if (check(j + 1)) {
      dfs(j + 1, counter);
    }
    REP (i, n) {
      flip(a[i][j]);
    }
    if (check(j + 1)) {
      dfs(j + 1, counter + 1);
    }
  }
}

vector<string> input() {
  vector<string> sv;
  char s[1024];
  REP (i, n) {
    scanf("%s", s);
    sv.PB(s);
  }
  sort(ALL(sv));
  return sv;
}

int work() {
  scanf("%d%d", &n, &l);
  a = input();
  b = input();
  ans = l + 1;
  dfs(0, 0);
  return ans;
}

int main() {
  srand(time(0));
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: ", index);
    int ans = work();
    if (ans > l) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
