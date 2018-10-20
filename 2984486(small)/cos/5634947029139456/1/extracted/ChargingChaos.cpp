#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}

int n, l;
string convert(const string &str, const string &sw) {
  string ret = str;
  REP(i, l) {
    ret[i] ^= sw[i] - '0';
  }
  return ret;
}

void solve() {
  scanf("%d %d", &n, &l);
  vector<string> outlet;
  vector<string> device;
  REP(i, n) {
    string str;
    cin >> str;
    outlet.push_back(str);
  }
  REP(i, n) {
    string str;
    cin >> str;
    device.push_back(str);
  }

  int ans = 1000;
  REP(i, n) {
    string sw = "";
    set<string> conv;
    int lans = 0;
    REP(j, l) {
      if (outlet[0][j] != device[i][j]) {
        sw += "1";
        lans++;
      } else {
        sw += "0";
      }
    }
    REP(j, n) {
      conv.insert(convert(outlet[j], sw));
    }
    REP(j, n) {
      if (!conv.count(device[j])) {
        goto next;
      }
    }
    ans = min(ans, lans);
next:;
  }

  if (ans <= l) {
    printf("%d\n", ans);
  } else {
    puts("NOT POSSIBLE");
  }
}
