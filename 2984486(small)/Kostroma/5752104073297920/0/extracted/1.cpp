#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
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

int good = 0, bad = 0, err = 0;
int good1 = 0, bad1 = 0;

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
	//cin >> t;
	start = clock();
	int testNum = 1;
    while (t--) {
		//cout << "Case #" << testNum++ << ": ";
        solve();
		//++timer;
	}
	//cout << good << ' ' << bad << ' ' << err << "\n";
	//cout << good1 << ' ' << bad1 << "\n";

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int a[1010];

void solve() {

	int n = 1000;

	/*freopen("in.txt", "w", stdout);
	cout << 120 << endl;
	for (int it = 0; it < 120; ++it) {
		cout << "1000\n";
		for (int i = 0; i < n; ++i)
			a[i] = i;
		if (rand() & 1) {
			for (int i = 0; i < n; ++i) {
				int k = rand() % n;
				swap(a[i], a[k]);
			}
			for (int i = 0; i < n; ++i)
				cout << a[i] << ' ';
			cout << "\nbad\n";
		}
		else {
			for (int i = 0; i < n; ++i) {
				int k = i + (rand() % (n - i));
				swap(a[i], a[k]);
			}
			for (int i = 0; i < n; ++i)
				cout << a[i] << ' ';
			cout << "\ngood\n";
		}
	}
	exit(0);*/

	int t;
	cin >> t;

	vector<pair<int, int>> now;
	vector<string> real(120);
	for (int it = 0; it < 120; ++it) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		/*string s;
		cin >> s;
		if (s == "good")
			++good1;
		else
			++bad1;
		real[it] = s;*/
		int cycles = 0;
		vector<char> used(n, false);
		int sumSqr = 0;
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			int cur = a[i];
			used[i] = true;
			int sz = 1;
			while(!used[cur]) {
				used[cur] = true;
				cur = a[cur];
				++sz;
			}
			++cycles;
			sumSqr += sz * sz;
		}
		now.push_back(mp(cycles, it));
	}

	sort(all(now));

	vector<string> res(120);
	for (int i = 0; i < 60; ++i) {
		/*if (now[i].first > 9)
			res[now[i].second] = "GOOD";
		else*/
			res[now[i].second] = "BAD";
	}
	for (int i = 60; i < 120; ++i)  {
		/*if (now[i].first < 9)
			res[now[i].second] = "BAD";
		else*/
			res[now[i].second] = "GOOD";
	}

	for (int testNum = 0; testNum < 120; ++testNum) {
		cout << "Case #" << testNum + 1 << ": ";
		cout << res[testNum] << "\n";
		if (res[testNum] == "GOOD" && real[testNum] == "bad")
			++err;
		if (res[testNum] == "BAD" && real[testNum] == "good")
			++err;
		if (res[testNum] == "GOOD")
			++good;
		else
			++bad;
	}


	/*int cycles = 0;
	li sumSqr = 0;
	vector<char> used(n, false);
	for (int i = 0; i < n; ++i) {
		if (used[i])
			continue;
		int sz = 1;
		int cur = a[i];
		used[i] = true;
		while(!used[cur]) {
			used[cur] = true;
			cur = a[cur];
			++sz;
		}
		++cycles;
		sumSqr += sz * sz;
	}
	if (cycles <= 10 && sumSqr >= 430000) {
		cout << "BAD\n";
		++bad;
		if (s != "bad")
			++err;
	}
	else {
		cout << "GOOD\n";
		++good;
		if (s != "good")
			++err;
	}*/

	/*int NUMBER = 100000;
	int sumCycles = 0;
	li sumSqr = 0;
	li inversions = 0;

	for (int it = 0; it < NUMBER; ++it) {
		for (int i = 0; i < n; ++i)
			a[i] = i;
		for (int i = 0; i < n; ++i) {
			int k = rnd.next(n);
			swap(a[i], a[k]);
		}

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (a[i] > a[j])
					++inversions;

		vector<char> used(n, false);
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			int sz = 1;
			int cur = a[i];
			used[i] = true;
			while(!used[cur]) {
				used[cur] = true;
				cur = a[cur];
				++sz;
			}
			++sumCycles;
			sumSqr += sz * sz;
		}

	}

	cout << "cycles = " << sumCycles / 1.0 / NUMBER << "\n";
	cout << "sumSqr = " << sumSqr / 1.0 / NUMBER << "\n";
	cout << "inversions = " << inversions / 1.0 / NUMBER << "\n";

	int sumCycles1 = 0;
	li sumSqr1 = 0;
	li inversions1 = 0;
	for (int it = 0; it < NUMBER; ++it) {
		for (int i = 0; i < n; ++i)
			a[i] = i;
		for (int i = 0; i < n; ++i) {
			int k = rnd.next(i, n);
			swap(a[i], a[k]);
		}

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (a[i] > a[j])
					++inversions1;

		vector<char> used(n, false);
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			int sz = 1;
			int cur = a[i];
			used[i] = true;
			while(!used[cur]) {
				used[cur] = true;
				cur = a[cur];
				++sz;
			}
			++sumCycles1;
			sumSqr1 += sz * sz;
		}

	}

	cout << "cycles = " << sumCycles1 / 1.0 / NUMBER << "\n";
	cout << "sumSqr = " << sumSqr1 / 1.0 / NUMBER << "\n";
	cout << "inversions = " << inversions1 / 1.0 / NUMBER << "\n";

	exit(0);*/

}
