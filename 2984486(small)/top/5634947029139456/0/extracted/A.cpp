#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 11;

int n,l;
string s[N],t[N],temp[N];

inline void solve () {
  scanf ("%d %d", &n, &l);
  for (int i = 0;i < n;i ++) {
    cin >> s[i];
  }
  for (int i = 0;i < n;i ++) {
    cin >> t[i];
  }

  sort (t, t+n);

  int ans = -1u/2;
  for (int i = (1<<l)-1;i >= 0;i --) {
    int cnt = 0;
    for (int k = 0;k < l;k ++) {
      if ((i>>k)&1) {
	cnt ++;
      }
    }
    for (int j = 0;j < n;j ++) {
      temp[j] = s[j];
      for (int k = 0;k < l;k ++) {
        if ((i>>k)&1) {
	  if (temp[j][k] == '0') {
	    temp[j][k] = '1';
	  } else {
	    temp[j][k] = '0';
	  }
	}
      }
    }

    sort (temp, temp+n);

    for (int i = 0;i < n;i ++) {
      if (t[i] != temp[i]) {
	goto f;
      }
    }
    ans = min (ans, cnt);
  f:;
  }
  if (ans < -1u/2) {
    printf ("%d\n", ans);
  } else {
    printf ("NOT POSSIBLE\n");
  }
}

int main () {
  int t;
  scanf ("%d", &t);
  for (int i = 1;i <= t;i ++) {
    printf ("Case #%d: ", i);
    solve ();
  }
}
