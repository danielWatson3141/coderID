#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define FORR(i,n) for(int i = n-1;i >= 0;i--)
#define REP(i,a,b) for(int i = (a);i<(b);++i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define sz(a) (int)(a).size()
#define CLEAR(a) memset(a, 0, sizeof(a))
#define INF 2000000000

typedef long long LL;

char flip(char x) {
  if (x == '0')
    return '1';
  return '0';
}

int main() {
  ios_base::sync_with_stdio(0);
  int tt;
  cin >> tt;

  FOR(tn,tt) {
    int n,l;
string s;

vector<string> h,t,hp;
set<string> ts;

    cin >> n >> l;
    FOR(i, n) {
      cin >> s;
      h.push_back(s);
      hp.push_back(s);
    }
    FOR(i, n) {
      cin >> s;
      t.push_back(s);
      ts.insert(s);
    }

    int mn = INF;

    FOR(i, n) {
      FOR(j, n) {

        int cnt = 0;        
        FOR(k,l) {
          if (h[i][k] != t[j][k]) {
            cnt++;
            FOR(q,n) {
              hp[q][k] = flip(hp[q][k]);
            }
          }
        }

        bool fail = 0;
        FOR(q, n) {
          if (ts.find(hp[q]) == ts.end()) {
            fail = 1;
            break;
          }
        }

        //revert
        FOR(k,l) {
          if (h[i][k] != t[j][k]) {
            FOR(q,n) {
              hp[q][k] = flip(hp[q][k]);
            }
          }
        }

        if (!fail) {
          mn = min(mn, cnt);
        }
      }
    }

  	cout << "Case #" << tn + 1 << ": ";
    if (mn != INF)
    cout << mn << endl;
    else
    cout << "NOT POSSIBLE" << endl;
  }

  return 0;
}
