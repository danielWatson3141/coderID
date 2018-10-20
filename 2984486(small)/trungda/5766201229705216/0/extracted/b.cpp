//this is the default for Google code jam only
#include <string>
#include <vector>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define pii pair<int, int>

using namespace std;

ifstream fi("B-small-attempt0.in");
//ifstream fi("A-large.in");
//ifstream fi("A-small-practice.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;

int n;
int m;
int res;
vector<int> ll[1001];
vector<int> llnew[1001];

void input();
void solve();
bool ok();
void output();

int main() {
  int ntest;
  fi >> ntest;
  for (test = 1; test <= ntest; test ++) {
    input();
    solve();
    output();
  }
  fi.close();
  fo.close();
  return 0;
}

void input() {
  //start code here
  fi >> n;
  for (int i = 1; i <= n; i ++) {
    ll[i].clear();
  }
  for (int e = 0; e < n - 1; e ++) {
    int x, y;
    fi >> x >> y;
    ll[x].push_back(y);
    ll[y].push_back(x);
  }
}

unsigned int getBit(unsigned int x, int i) {
  return ((x & (1 << i)) != 0);
}

void construct(unsigned int t) {
  bool Removed[2000];
  for (int i = 1; i <= n; i ++) {
    llnew[i].clear();
    Removed[i] = false;
  }
  for (int i = 0; i < n; i ++) {
    if (getBit(t, i) == 0) { // remove i + 1
      Removed[i + 1] = true;
    }
  }
  m = 0;
  int lab[1001];
  for (int i = 1; i <= n; i ++) 
    if (!Removed[i]) {
      m ++;
      lab[i] = m;
    }
  for (int i = 1; i <= n; i ++)
    if (!Removed[i]) {
      for (int j = 0; j < ll[i].size(); j ++) 
	if (!Removed[ll[i][j]]) {
	  llnew[ lab[i] ].push_back( lab[ ll[i][j] ] );
	}
    }
}

bool ok() {
  if (m == 1) {
    return true;
  }
  int ii = -1;
  for (int i = 1; i <= m; i ++)
    if (llnew[i].size() == 2) {
      ii = i;
      break;
    }
  if (ii == -1) {
    return false;
  }
  bool visited[1001];
  for (int i = 1; i <= m; i ++) {
    visited[i] = false;
  }
  visited[ii] = true;
  queue<int> q;
  q.push(ii);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    int c = 0;
    for (int i = 0; i < llnew[x].size(); i ++) {
      int y = llnew[x][i];
      if (!visited[y]) {
	visited[y] = true;
	q.push(y);
	c ++;
      }
    }
    if (!(c == 0 || c == 2)) {
      return false;
    }
  }
  for (int i = 1; i <= m; i ++) {
    if (!visited[i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  res = n - 1;
  for (unsigned int t = 0; t < (1 << n); t ++) {
    construct(t);
    // if (t == 14) {
    //   cout << m << endl;
    //   for (int i = 1; i <= m; i ++) {
    // 	for (int j = 0; j < llnew[i].size(); j ++) {
    // 	  cout << llnew[i][j] << " ";
    // 	}
    // 	cout << endl;
    //   }
    // }
    if (ok()) {
      res = min(res, n - __builtin_popcount(t));
    }
  }
}

void output() {
  fo << "Case #" << test << ": " << res << endl;
}
