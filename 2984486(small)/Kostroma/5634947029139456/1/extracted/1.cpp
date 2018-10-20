#pragma comment (linker, "/STACK:128000000")
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
//void precalc();
clock_t start;
//int timer = 1;
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	cout.sync_with_stdio(0);
	//precalc();
	cout.precision(10);
	cout << fixed;
	cin >> t;
	start = clock();
	int testNum = 1;
    while (t--) {
		cout << "Case #" << testNum++ << ": ";
        solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int li


void solve() {
	int n, l;
	cin >> n >> l;
	vector<int> outlets, devices;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int cur = 0;
		for (int j = 0; j < s.length(); ++j)
			cur = cur * 2 + s[j] - '0';
		outlets.push_back(cur);
	}
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int cur = 0;
		for (int j = 0; j < s.length(); ++j)
			cur = cur * 2 + s[j] - '0';
		devices.push_back(cur);
	}
	sort(all(devices));

	int ans = 100000;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int mask = outlets[i] ^ devices[j];

			vector<int> curO;
			for (int k = 0; k < n; ++k)
				curO.push_back(outlets[k] ^ mask);
			sort(all(curO));

			bool flag = true;
			for (int k = 0; k < n; ++k)
				if (curO[k] != devices[k]) {
					flag = false;
					break;
				}
			if (flag) {
				int cnt = 0;
				for (int k = 0; k < l; ++k)
					if (mask & (1LL << k))
						++cnt;
				ans = min(ans, cnt);
			}

		}

	if (ans <= l)
		cout << ans << "\n";
	else
		cout << "NOT POSSIBLE\n";

}
