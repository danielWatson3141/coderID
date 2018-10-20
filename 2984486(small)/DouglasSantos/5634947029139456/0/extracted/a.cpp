#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
#include <complex>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

int n, m;
char v[150][150];
char w[150][150];

int calcula(int ind) {
  int res = 0;
  set<string> mapa;
  REP(i, n) {
    string s = "";
    res = 0;
    REP(j, m) {
      if (v[ind][j] == w[0][j]) {
        s = s + v[i][j];
      }
      else {
        if (v[i][j] == '0') s += '1';
        else s += '0';
        res++; 
      }
    }
    mapa.insert(s);
  }
  REP(i, n) {
    if (mapa.find(w[i]) == mapa.end()) return INF;
  }
  return res;
}

int main()
{	
  int t;
  scanf("%d", &t);
  REP(k, t) {
    scanf("%d %d", &n, &m);
    REP(i, n) {
      scanf("%s", v[i]);
    }
    REP(i, n) {
      scanf("%s", w[i]);
    }
    int res = INF;
    REP(i, n) {
      res = min(res, calcula(i));
    }
    printf("Case #%d: ", k+1);
    if (res == INF) {
      printf("NOT POSSIBLE\n");
    }
    else {
      printf("%d\n", res);
    }
  }
	return 0;
}