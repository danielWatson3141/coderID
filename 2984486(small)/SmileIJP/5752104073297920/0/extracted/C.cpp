#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }


int invs(vector< int > & a) {
  int res = 0;
  for (int i = 0; i < a.size(); ++i) {
    for (int j = i + 1; j < a.size(); ++j) {
      if (a[i] > a[j]) {
        res ++;
      }
    }
  }
  return res;
}

int stab(vector< int > & a) {
  int res = 0;
  for (int i = 0; i < a.size(); ++i) {
    res += abs(a[i] - i);
  }
  return res;
}

void shuf1(vector< int > & a) {
  for (int i = 0; i < a.size(); ++i) {
    int x = rand() % (a.size() - i) + i;
    swap(a[i], a[x]);
  }
}


void shuf2(vector< int > & a) {
  for (int i = 0; i < a.size(); ++i) {
    int x = rand() % a.size();
    swap(a[i], a[x]);
  }
}

void x1() {
  int n = 1000;
  for (int u = 0; u < 100; ++u) {
    vector< int > a(n, 0);
    for (int i = 0; i < n; ++i) {
      a[i] = i;
    }
    
    shuf1(a);
    cout << (stab(a) <= 329000 ? "BAD" : "GOOD") << endl;
  
  }
}

void solve() {
  int n = next< int >();
  vector< int > a(n, 0);

  for (int i = 0; i < n; ++i) {
    a[i] = next< int >();
  }
  cout << (stab(a) <= 328000 ? "BAD" : "GOOD") << endl;
}

int main() {

//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

//  x1();
  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}

