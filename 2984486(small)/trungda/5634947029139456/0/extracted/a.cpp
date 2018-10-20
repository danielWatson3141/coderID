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

ifstream fi("A-small-attempt0.in");
//ifstream fi("A-large.in");
//ifstream fi("A-small-practice.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;

void input();
void solve();
void output();

unsigned int getBit(unsigned int, int);
void setBit(unsigned int &, int);
void clearBit(unsigned int &, int);
void reverseBit(unsigned int &, int);

int n, l;
string x[200];
string y[200];
int res;

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
  fi >> n >> l;
  for (int i = 0; i < n; i ++) {
    fi >> x[i];
  }
  for (int i = 0; i < n; i ++) {
    fi >> y[i];
  }
}

void solve() {
  res = 1000;
  for (unsigned int t = 0; t < (1 << l); t ++) {
    string xx[200];
    for (int i = 0; i < n; i ++) {
      xx[i] = x[i];
    }
    for (int i = 0; i < l; i ++) {
      if (getBit(t, i)) {
	for (int j = 0; j < n; j ++) {
	  if (xx[j][i] == '0') {
	    xx[j][i] = '1';
	  }
	  else {
	    xx[j][i] = '0';
	  }
	}
      }
    }
    bool used[200];
    bool covered[200];
    for (int i = 0; i < n; i ++) {
      used[i] = false;
      covered[i] = false;
    }
    for (int i = 0; i < n; i ++) {
      if (!used[i]) {
	for (int j = 0; j < n; j ++) {
	  if (!covered[j] && xx[i] == y[j]) {
	    used[i] = true;
	    covered[j] = true;
	    break;
	  }
	}
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i ++) {
      if (!used[i]) {
	ok = false;
	break;
      }
    }
    if (ok) {
      res = min(res, __builtin_popcount(t));
    }
  }
}

void output() {
  if (res == 1000) {
    fo << "Case #" << test << ": NOT POSSIBLE" << endl;
  }
  else {
    fo << "Case #" << test << ": " << res << endl;    
  }
}

unsigned int getBit(unsigned int x, int i) {
  return ((x & (1 << i)) != 0);
}
 
void setBit(unsigned int &x, int i) {
  x = x | (1 << i);
}
 
void clearBit(unsigned int &x, int i) {
  x = x & (~(1 << i));
}
 
void reverseBit(unsigned int &x, int i) {
  if (getBit(x, i)) {
    clearBit(x, i);
  }
  else {
    setBit(x, i);
  }
}
