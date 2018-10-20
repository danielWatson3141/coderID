#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

char a[200][200];
char b[200][200];
int n, l;

const int INF = 1000000;

void flip(int id) {
  for (int i = 0; i < n; ++i) {
    if (a[i][id] == '0')
      a[i][id] = '1';
    else
      a[i][id] = '0';
  }
}

bool can(int len) {
  std::multiset<std::string> A, B;
  for (int i = 0; i < n; ++i) {
    A.insert(std::string(a[i], a[i] + len));
    B.insert(std::string(b[i], b[i] + len));
  }
  return A == B;
}

int solve(int len) {
  if (len == l) {
    if (can(len)) {
      return 0;
    }
    return INF;
  }

  int res = INF;
  if (can(len)) {
    res = min(res, solve(len+1));
  }

  flip(len);
  if (can(len)) {
    res = min(res, 1 + solve(len+1));
  }
  flip(len);
  return res;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int tests;
  cin>>tests;
  for (int t = 0; t < tests; ++t) {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d%d\n",&n,&l);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < l; ++j) {
        a[i][j] = getchar();
      }
      if (i != n-1) {
        getchar();
      }
    }
    gets(a[199]);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < l; ++j) {
        b[i][j] = getchar();
      }
      if (i != n-1) {
        getchar();
      }
    }

    for (int i = 0; i < n; ++i) {

    }

    int ans = solve(0);
    cout << "Case #" << t + 1 << ": ";
    if (ans >= INF) {
      puts("NOT POSSIBLE");
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}