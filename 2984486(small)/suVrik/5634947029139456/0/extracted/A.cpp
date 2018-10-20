// includes, defines, typedefs //{

#include <functional>
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <time.h>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define endl '\n'
#define mp(a, b) make_pair((a), (b))
#define pb(a) push_back(a)
#define gi greater<int>()
#define gip greater<ip>()
#define y second
#define x first

//}

const int MAX = 99999999;
int T, N, L, sol;
int a[60], b[60];
char str[60];

long long c[155];
map<long long, int> f[45];
map<long long, int> p[45];

void dfs(int turns, int step, long long mask) {
   if (turns >= sol) return;
   if (step == L) {
      sol = turns;
   } else {
      if (a[step] == b[step]) {
         for (map<long long, int>::iterator i = f[step].begin(); i != f[step].end(); i++) {
            if (p[step][i->first ^ (mask << 1)] != i->second) {
               goto bad0;
            }
         }
         dfs(turns, step + 1, mask << 1);
         bad0:
         if (N - a[step] == b[step]) {
            for (map<long long, int>::iterator i = f[step].begin(); i != f[step].end(); i++) {
               if (p[step][i->first ^ ((mask << 1) + 1)] != i->second) {
                  goto bad1;
               }
            }
         }
         dfs(turns + 1, step + 1, (mask << 1) + 1);
         bad1: ;
      } else if (N - a[step] == b[step]) {
         for (map<long long, int>::iterator i = f[step].begin(); i != f[step].end(); i++) {
            if (p[step][i->first ^ ((mask << 1) + 1)] != i->second) {
               goto bad2;
            }
         }
         dfs(turns + 1, step + 1, (mask << 1) + 1);
         bad2: ;
      }
   }
}

int main() {
   ios::sync_with_stdio(false);

   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);

   cin >> T;

   for (int t = 1; t <= T; t++) {
      cin >> N >> L;
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));
      for (int i = 0; i < 45; i++) {
         p[i].clear();
         f[i].clear();
      }
      for (int i = 0; i < N; i++) {
         cin >> str;
         long long q = 0;
         for (int j = 0; j < L; j++) {
            q <<= 1;
            q += (str[j] == '1');
            a[j] += (str[j] == '1');
            p[j][q]++;
         }
      }
      for (int i = 0; i < N; i++) {
         cin >> str;
         long long q = 0;
         for (int j = 0; j < L; j++) {
            q <<= 1;
            q += (str[j] == '1');
            b[j] += (str[j] == '1');
            f[j][q]++;
         }
         c[i] = q;
      }
      sol = MAX;
      dfs(0, 0, 0);
      if (sol >= MAX) cout << "Case #" << t << ": " << "NOT POSSIBLE" << endl;
      else cout << "Case #" << t << ": " << sol << endl;
   }

   return 0;
}
