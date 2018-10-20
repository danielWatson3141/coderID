#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

LL a[150], b[150];
bool fl[40];
int n, l;
string s;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	REP(test, t) {
		cin >> n >> l;
		REP(i, n) {
			cin >> s;
			a[i] = 0;
			REP(j, l)
				a[i] |= LL(s[j] - '0') << j;
		}
		REP(i, n) {
			cin >> s;
			b[i] = 0;
			REP(j, l)
				b[i] |= LL(s[j] - '0') << j;
		}
		cout << "Case #" << test + 1 << ": ";
		bool flag = false;
		int ans = 0, ans2 = 0, CNT = 0;
		REP(j, l) {
			fl[j] = false;
			int acnt = 0, bcnt = 0;
			REP(i, n)
				if (a[i] & (1ll << j))
					++acnt;
			REP(i, n)
				if (b[i] & (1ll << j))
					++bcnt;
			if (acnt != bcnt && acnt + bcnt != n) {
				flag = true;
				cout << "NOT POSSIBLE\n";
				break;
			} else if (acnt != bcnt) {
				REP(i, n)
					a[i] ^= (1ll << j);
				++ans;
			} else if (acnt + bcnt == n)
				fl[j] = true;
		}
		if (flag) continue;
		sort(b, b + n);
		for (int j = l - 1; j >= 0; --j)
			if (fl[j]) {
				++CNT;
				sort(a, a + n);
				bool dir = true;
				REP(i, n)
					if ((a[i] & (1ll << j)) ^ (b[i] & (1ll << j)))
						dir = false;
				if (dir) continue;
				REP(i, n)
					a[i] ^= (1ll << j);
				++ans2;

				sort(a, a + n);
				dir = true;
				REP(i, n)
					if ((a[i] & (1ll << j)) ^ (b[i] & (1ll << j)))
						dir = false;
				if (dir) continue;
				flag = true;
				cout << "NOT POSSIBLE\n";
				break;
			}
		if (flag) continue;
		sort(a, a + n);
		sort(b, b + n);
		REP(i, n) if (a[i] != b[i]) {
			flag = true;
			cout << "NOT POSSIBLE\n";
			break;
		}
		if (flag) continue;
		REP(j, l)
			if (fl[j]) {
				REP(i, n)
					a[i] ^= (1ll << j);
			}
		sort(a, a + n);
		REP(i, n) if (a[i] != b[i]) {
			flag = true;
			break;
		}
		if (!flag && CNT - ans2 < ans2)
			ans2 = CNT - ans2;
		ans += ans2;
		cout << ans << "\n";
	}
	return 0;
}
