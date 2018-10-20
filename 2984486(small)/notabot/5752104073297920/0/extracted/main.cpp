#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

//#define DB(x) cout << x << " "
//#define DBN(x) cout << #x << "=" << x << endl
//#define DBL cout << endl
#define DB(x) cerr << x << " "
#define DBN(x) cerr << #x << "=" << x << endl
#define DBL cerr << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

const int inf = 1e9;
const int n = 1000;

struct info_t {
  int min;
  int max;
  int sum;
  int num;

  info_t() {
    min = inf;
    max = -inf;
    sum = 0;
    num = 0;
  }

  void add(int x) {
    min = std::min(min, x);
    max = std::max(max, x);
    sum += x;
    num += 1;
  }

  double av() const {
    assert(num > 0);
    return double(sum) / num;
  }

  void print(string t) {
    assert(num > 0);
    const char *s = t.data();
    printf("%s.min=%d   %s.max=%d   %s.av=%.3lf\n", s, min, s, max, s, double(sum) / num);
  }
};

int p[n];

void gengood(int n, int *p) {
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int i = 0; i < n; ++i) {
    int k = rand() % (n - 1 - i + 1);
    swap(p[i], p[k + i]);
  }
}

void genbad(int n, int *p) {
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int i = 0; i < n; ++i) {
    int k = rand() % n;
    swap(p[i], p[k]);
  }
}

int inversions(int n, int i, int *p) {
  int res = 0;
  for (int j = i + 1; j < n; ++j)
    if (p[j] < p[i]) ++res;
  return res;
}

int inversions(int n, int *p) {
  int res = 0;
  for (int i = 0; i < n; ++i)
    res += inversions(n, i, p);
  return res;
}

string itos(int i) {
  ostringstream oss;
  oss << i;
  return oss.str();
}

int invbad = 230000;
int invgood = 259000;

struct gen {
  //vector<set<int>> s;
  info_t invinfo;
  info_t oninfo;
  vector<info_t> invs;
  vector<info_t> valinfo;
  vector<info_t> posinfo;
  gen(bool bad): invs(n), valinfo(n), posinfo(n) {
    int k = 1000;
    int goods = 0;
    int bads = 0;
    int unkowns = 0;
    for (int i = 0; i < k; ++i) {
      if (bad) {
        genbad(n, p);
      } else {
        gengood(n, p);
      }
      int inv = inversions(n, p);
      invinfo.add(inv);
      if (inv <= invbad) ++bads;
      else if (inv >= invgood) ++goods;
      else ++unkowns;
      int on = 0;
      for (int j = 0; j < n; ++j) {
        //s[j].insert(p[j]);
        invs[j].add(inversions(n, j, p));
        valinfo[j].add(p[j]);
        posinfo[p[j]].add(j);
        if (p[j] == j) ++on;
      }
      oninfo.add(on);
    }
  }
};

enum { NONE, GOOD, BAD };

int classify(int x, int good, int bad) {
  if (abs(good - bad) < 10) return NONE;
  if (good < bad) {
    if (x <= good) return GOOD;
    else if (x >= bad) return BAD;
    else return NONE;
  } else {
    if (x >= good) return GOOD;
    else if (x <= bad) return BAD;
    else return NONE;
  }
}

void solve(int testcase, const gen &good, const gen &bad) {
  DBN(testcase);
  printf("Case #%d: ", testcase);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  //gengood(n, p);
  int g = 0;
  int b = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    //k = classify(p[i], good.valinfo[i].av(), bad.valinfo[i].av());
    //if (k == GOOD) { ++g; }//continue; }
    //if (k == BAD) { ++b; }//continue; };
    //k = classify(i, good.posinfo[p[i]].av(), bad.posinfo[p[i]].av());
    //if (k == GOOD) { ++g; continue; }
    //if (k == BAD) { ++b; continue; };
    k = classify(inversions(n, i, p), good.posinfo[i].av(), bad.posinfo[i].av());
    if (k == GOOD) { ++g; }//continue; }
    if (k == BAD) { ++b; }//continue; };
  }
  //DBN(g); DBN(b); DBL;
  if (g > b) puts("GOOD"); else puts("BAD");
}

int main(int argc, char **argv) {
  srand(time(0));
  gen bad(true);
  gen good(false);

  if (false) {
    good.invinfo.print("G.allinv");
    bad.invinfo.print("B.allinv");
    good.oninfo.print("G.on");
    bad.oninfo.print("B.on");
    for (int i = 0; i < n; ++i) {
      DB("------"); DBL;
      DB(i); DBL;
      good.invs[i].print(string("G.invs") + itos(i));
      bad.invs[i].print(string("B.invs") + itos(i));
      DBL;
      good.valinfo[i].print(string("G.val") + itos(i));
      bad.valinfo[i].print(string("B.val") + itos(i));
      DBL;
      good.posinfo[i].print(string("G.pos") + itos(i));
      bad.posinfo[i].print(string("B.pos") + itos(i));
      DBL;
      DB("------");
      DBL;
    }
  }
  freopen("C-small-attempt1.in", "r", stdin);
  freopen("out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
    solve(t, good, bad);
  return 0;
}
