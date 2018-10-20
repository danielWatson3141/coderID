/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

set<string> devices;
vector<string> outlets;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  REP(t, T) {
    int N, L;
    scanf("%d%d", &N, &L);
    devices.clear();
    outlets.clear();
    int best = L + 1;
    REP(i, N) {
      string s;
      cin >> s;
      outlets.push_back(s);
    }
    REP(i, N) {
      string s;
      cin >> s;
      devices.insert(s);
    }
    string device = *devices.begin();
    REP(i, N) {
      set<string> flows;
      int changes = 0;
      REP(j, L) changes += (device[j] != outlets[i][j]);

      REP(j, N) {
        string s = "";
        REP(l, L) {
          if (device[l] == outlets[i][l]) {
            s.push_back(outlets[j][l]);
          }
          else {
            s.push_back(1 - (outlets[j][l] - '0') + '0');
          }
        }
        flows.insert(s);
      }

      if (flows == devices && changes < best) best = changes;
    }
    printf("Case #%d: ", t + 1);
    if (best <= L) printf("%d\n", best);
    else printf("NOT POSSIBLE\n");
  }

  return 0;
}
