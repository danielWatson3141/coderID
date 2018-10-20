#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

template <typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template <typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }
template <typename T> inline int sz(const T& x) { return (int) x.size(); }

#define PATH "C:\\Users\\Valenkof\\Desktop\\"
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair

const int INF = 1000000;

typedef bitset<40> MASK;

vector<MASK> a, b;

typedef pair<vector<int>, vector<int> > match;

void solve(int n, int k) {
	int ans = INF;
		
	forn (i, n) {
		MASK change = a[0] ^ b[i];
		int cost = change.count();
		// debug(cost);
		if (cost > ans) continue;
		forn (j, n) {
			MASK xa = a[j] ^ change;
			bool found = false;
			forn (p, n) {
				if (xa == b[p]) {
					found = true;
					break;
				}
			}
			if (!found) {
				cost = INF;
				break;
			}
		}
		mn(ans, cost);
	}
		
	if (ans == INF) cout << "NOT POSSIBLE" << endl;
	else cout << ans << endl;
}

int main() {
	freopen(PATH"A-small-attempt0.in", "r", stdin);
	freopen(PATH"output.txt", "w", stdout);	
	ios_base::sync_with_stdio(false);
	
	int nTests;
	cin >> nTests;
	forn (iTest, nTests) {
	
		cout << "Case #" << iTest + 1 << ": ";
		int n, k;
		cin >> n >> k;
		a.resize(0);
		b.resize(0);
		forn (i, n) { MASK m; string s; cin >> s; forn (j, k) m[j] = s[j] - '0'; a.push_back(m); }
		forn (i, n) { MASK m; string s; cin >> s; forn (j, k) m[j] = s[j] - '0'; b.push_back(m); }
		solve(n, k);
	}
	return 0;
}