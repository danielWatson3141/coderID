#define PRETEST
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <cstdio>
using namespace std;

#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFF
#define BIG 0x4F4F4F4F
#define PI acos(-1)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

typedef long long ll;
typedef unsigned long long ull;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<string, int> psi;

#define DEBUG(x) cout << #x << " : " << x << endl

#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define PB push_back
#define eps 1e-9
#define fst first
#define snd second
#define REP(I,N) for (int I = 0; I < (N); I++)
#define REPP(I,A,B) for (int I = (A); I < (B); I++)
#define REPE(I,A,B) for (int I = (A); I <= (B); I++)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define RS(X) scanf("%s", (X))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

int x[111];
int y[111];
bool flag[111111];
bool vis[111];
int n, l;
bool get_ans;
bool print = false;

void search(int dep) {
  get_ans = true;
  REP(i, n) {
    if (!flag[x[i]]) {
      get_ans = false;
    }
  }
  if (get_ans && !print) {
    print = true;
    printf("%d\n", dep);
    return dep;
  }
  REP(i, l) {
    if (vis[i])
      continue;
    int mask = (1 << i);
    REP(j, n) {
      x[i] ^= mask;
    }
    vis[i] = true;
    search(dep + 1);
    vis[i] = false;
  }
}

int main(int argc, char* argv[]) {
  #ifdef PRETEST
  freopen("in.txt", "r", stdin);
  #endif
  int t;
  REPE(z, 1, t) {
    printf("Case #%d: ", z);
    RII(n, l);
    REP(i, n) {
      cin >> a[i];
    }
    REP(i, n) {
      cin >> b[i];
    }
    RESET(x, 0);
    RESET(y, 0);
    REP(i, n) {
      REP(j, a[i].size()) {
        x[i] = x[i] * 2 + a[i] - '0';
      }
    }
    REP(i, n) {
      REP(j, b[i].size()) {
        y[i] = y[i] * 2 + b[i] - '0';
      }
      flag[y[i]] = true;
    }
    get_ans = true;
    print = false;
    RESET(vis, 0);
    search(0);
  }
  return 0;
}
