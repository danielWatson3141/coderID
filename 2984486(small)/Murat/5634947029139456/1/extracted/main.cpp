#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
  
#include <iostream>
  
#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>
  
using namespace std;
  
template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }
  
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
  
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
  
const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 160;

li a[N];
li b[N];
li d[N][N];
int ur[N];
int uc[N];

int main() {
	int tests;
	scanf("%d", &tests);
	char s[50];
	int mark = 50;
	for1 (it, tests) {
		int n, L;
		scanf("%d%d\n", &n, &L);
		forn (k, 2) {
			forn (i, n) {
				scanf("%s", s);
				li t = 0;
				forn (j, L) {
					if (s[j] == '0') {

					} else if (s[j] == '1') {
						t |= 1LL << j;
					} else {
						throw 1;
					}
				}
				if (k == 0)
					a[i] = t;
				else
					b[i] = t;
			}
		}
		vector<li> vals;
		forn (i, n)
			forn (j, n) {
				d[i][j] = a[i] ^ b[j];
				vals.pb(d[i][j]);
			}
		sort(all(vals));
		vals.erase(unique(all(vals)), vals.end());
		bool ok = false;
		int ans;
		forn (iv, vals.size()) {
			li v = vals[iv];
			++mark;
			int r = 0, c = 0;
			forn (i, n)
				forn (j, n) {
					if (d[i][j] == v) {
						if (ur[i] != mark) {
							ur[i] = mark;
							++r;
						}
						if (uc[j] != mark) {
							uc[j] = mark;
							++c;
						}
					}
				}
			if (r == c && r == n) {
				int res = 0;
				forn (i, L)
					if (v & (1LL << i))
						++res;
				if (!ok) {
					ans = res;
					ok = true;
				} else
					ans = min(ans, res);
			}
		}
		printf("Case #%d: ", it);
		if (!ok)
			puts("NOT POSSIBLE");
		else
			printf("%d\n", ans);
	}
    return 0;
}
