#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


ll conv(string s) {
  ll two = 2l;
  int sz = s.size();
  ll res = 0;
  ll cur = 1l;
  fr (i, sz) {
    res = res + ((ll) (s[i] - '0')) * cur;
    cur = cur * 2;
  }
  return res;
}

int count_bits(ll n) {     
  unsigned int c; // c accumulates the total bits set in v
  for (c = 0; n; c++) 
    n &= n - 1; // clear the least significant bit set
  return c;
}

int main() {
  int ti;
  si(ti);
  int MAX_FLIPS = 14444;
  f (t, 1, ti + 1) {
    int n;
    int l;
    si(n); si(l);
    ll a[n];
    ll b[n];
    string s;
    fr (i, n) {
      cin >> s;
      a[i] = conv(s);
    }
    
    fr (i, n) {
      cin >> s;
      b[i] = conv(s);
    }

    set<ll> target_set (b, b + n);
    
    ll ref = b[0];

    int max_flips = MAX_FLIPS;
    fr (i, n) {
      ll counter_ref = a[i];
      ll modifer = a[i] ^ ref;
      set<ll>::iterator it;
      bool fail = false;
      fr (j, n) {
        it = target_set.find(modifer ^ a[j]);
        if (it == target_set.end()) {
          fail = true;
          break;
        }
      }
      if (!fail) {
        max_flips = min(max_flips, count_bits(modifer));
      }
    }
    
    cout << "Case #" << t << ": ";
    if (max_flips == MAX_FLIPS) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << max_flips << endl;
    }    
  }

  return 0;
}
