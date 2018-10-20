#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 200;

int T, N, L;

vector<int> in[MAXN];
vector<int> out[MAXN];

int main() {
	scanf("%d", &T);
	REP(t,T) {
		REP(n, MAXN) {
			in[n].clear();
			out[n].clear();
		}
		scanf("%d%d ", &N, &L);
		REP(n, N) REP(l, L) {
			char c;
			scanf("%c ", &c);
			in[n].push_back(c == '1' ? 1 : 0);
		}
		REP(n, N) REP(l, L) {
			char c;
			scanf("%c ", &c);
			out[n].push_back(c == '1' ? 1 : 0);
		}

		set<ll> s1;
		REP(n,N) {
			ll r = 0;
			REP(l,L) {
				r *= 2;
				r += in[n][l];
			}
			s1.insert(r);
		}

		int best = L+1;

		REP(tarI, N) {
			vector<int> changes;
			int cnt = 0;
			REP(l,L) if ((in[0][l] != out[tarI][l])) {
				changes.push_back(true);
				++cnt;
			} else {
				changes.push_back(false);
			}
			REP(n,N) REP(l,L) if (changes[l]) {
				out[n][l] = !out[n][l];
			}

			bool ok = true;
			REP(n,N) {
				ll r = 0;
				REP(l,L) {
					r *= 2;
					r += out[n][l];
				}
				if (s1.find(r) == s1.end()) {
					ok = false;
					break;
				}
			}

			if (ok) {
				best = min(best, cnt);
			}

			REP(n,N) REP(l,L) if (changes[l]) {
				out[n][l] = !out[n][l];
			}
		}

		printf("Case #%d: ", t+1);
		if (best > L) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", best);
		}
	}
	return 0;
}
