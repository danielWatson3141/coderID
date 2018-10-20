// written by lonerdude(dvdreddy)
// all rights reserved
//the template by dvdreddy
#include <vector>
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

int main() {
  int ti;
  si(ti);
  f (t, 1, ti + 1) {
    int n;
    si(n);
    int a[n];
    fr (i, n) {
      si(a[i]);
    }
    int cnt = 0;
    fr (i, n) {
      if (a[i] == i) cnt++;
    }
    cout << "Case #" << t << ": ";
    if (cnt >= 1) {
      cout << "BAD";
    } else {
      cout << "GOOD";
    }
    cout << endl;
  }
  return 0;
}
