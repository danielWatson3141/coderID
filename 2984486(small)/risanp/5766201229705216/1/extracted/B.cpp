#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <map>

#define PB push_back
#define MP make_pair
#define F first
#define S second

#define oo 1000111000

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

#define MAXV 1000

map<pair<PII,int>, int> MAP;
int V;
vector<int> G[MAXV + 5];

void readTree() {
  scanf("%d", &V);
  for (int i = 0; i < V; i++) {
    G[i].clear();
  }
  for (int i = 0; i < V - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    G[a].PB(b);
    G[b].PB(a);
  }
}

int doDP(int v, int par, int stat) {
  auto state = MP(MP(v, par), stat);
  if (MAP.count(state) != 0) {
    return MAP[state];
  }
  int &ret = MAP[state];
  if (stat == 0) {
    // dia dihapus
    ret = 1;
    for (int i = 0; i < G[v].size(); i++) {
      int w = G[v][i];
      if (w == par) {
        continue;
      }
      ret += doDP(w, v, 0);
    }
    /*
    */
    return ret;
  }
  ret = oo;
  // hapus semua anak
  int tmpRet = 0;
  for (int i = 0; i < G[v].size(); i++) {
    int w = G[v][i];
    if (w == par) {
      continue;
    }
    tmpRet += doDP(w, v, 0);
  }
  ret = min(ret, tmpRet);
  // sisain dua anak
  tmpRet = 0;
  int max1 = -oo, max2 = -oo;
  int totSum = 0;
  for (int i = 0; i < G[v].size(); i++) {
    int w = G[v][i];
    if (w == par) {
      continue;
    }
    totSum += doDP(w, v, 0);
    int x = doDP(w, v, 0) - doDP(w, v, 1);
    if (x > max1) {
      max2 = max1;
      max1 = x;
    } else if (x > max2) {
      max2 = x;
    }
  }
  if (max2 != -oo) {
    ret = min(ret, totSum - max1 - max2);
  }
  return ret;
}

int solve() {
  int ret = oo;
  for (int i = 0; i < V; i++) {
    for (int k = 0; k < 2; k++) {
      ret = min(ret, doDP(i, -1, k));
    }
  }
  return ret;
}

int main() {
  int tc = 0, nTC;
  scanf("%d", &nTC);
  while (++tc && nTC--) {
    MAP.clear();
    readTree();
    printf("Case #%d: %d\n", tc, solve());
  }
  return 0;
}

