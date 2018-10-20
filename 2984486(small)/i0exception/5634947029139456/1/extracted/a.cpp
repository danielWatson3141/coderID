#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define GI(x) scanf("%d", &x);
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FOR(i, start, end) for(int i = start; i < end; i++)
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 1000000000
using namespace std;
int N, L;
vector<string> seed;
vector<string> target;

void solve() {
  int ret = 1e9;
  int xt = 0;
  FORN(i, (1<<L)) {
    vector<string> x;
    FORN(j, SZ(seed)) {
      string s = seed[j];
      FORN(k, L) {
        if (i & (1<<k)) {
          if (s[k] == '0')
            s[k] = '1';
          else s[k] = '0';
        }
      }
      x.PB(s);
    }
    sort(ALL(x));
    if (x == target) {
      if (ret > __builtin_popcount(i)) {
        ret = __builtin_popcount(i);
        xt = i;
      }
    }
  }
  if (ret == 1e9) {
    printf("NOT POSSIBLE\n");
  } else {
    printf("%d, %d\n", ret, xt);
  }
}

void solve2() {
  int ret = 1e9;
  FORN(i, N) {
    FOR(j, i, N) {
      int pos[100];
      int cnt = 0;
      CLR(pos);
      FORN(k, L) {
        if (seed[i][k] != target[j][k]) {
          cnt++;
          pos[k] = 1;
        }
      }
      vector<string> t;
      FORN(k, N) {
        string s = seed[k];
        FORN(l, L) {
          if (pos[l]) {
            if (s[l] == '0')
              s[l] = '1';
            else s[l] = '0';
          }
        }
        t.PB(s);
      }
      sort(ALL(t));
      if (t == target) {
        ret = MIN(ret, cnt);
      }
    }
  }
  if (ret == 1e9) {
    printf("NOT POSSIBLE\n");
  } else {
    printf("%d\n", ret);
  }
}

int main() {
  int tes;
  GI(tes);
  FORN(i, tes) {
    seed.clear();
    target.clear();
    GI(N); GI(L);
    FORN(j, N) {
      string s;
      cin >> s;
      seed.PB(s);
    }
    FORN(j, N) {
      string s;
      cin >> s;
      target.PB(s);
    }
    sort(ALL(seed));
    sort(ALL(target));
    /*FORN(j, N) {
      cout<<seed[j]<<endl;
    }
    cout<<endl;

    FORN(j, N) {
      cout<<target[j]<<endl;
    }*/
    printf("Case #%d: ", i+1);
    solve2();
  }
}
