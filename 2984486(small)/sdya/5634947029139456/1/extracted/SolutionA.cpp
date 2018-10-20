#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 200;
const int inf = 1000000000;
int n, l;
vector < string > a, b;

map < pair < vector < string >, int >, int > M;

int calc(vector < string > current, int position) {
	if (M.count(make_pair(current, position))) {
		return M[make_pair(current, position)];
	}

	if (current == b) {
		return M[make_pair(current, position)] = 0;
	}

	if (position == l) {
		return inf;
	}

	vector < string > old = current;

	int res = inf;
	{
		bool nice = true;
		for (int i = 0; i < n; ++i) {
			if (current[i].substr(0, position + 1) != b[i].substr(0, position + 1)) {
				nice = false;
				break;
			}
		}
		if (nice) {
			res = min(res, calc(current, position + 1));
		}
	}
	{
		for (int i = 0; i < n; ++i) {
			current[i][position] = (current[i][position] == '1' ? '0' : '1');
		}
		sort(current.begin(), current.end());

		bool nice = true;
		for (int i = 0; i < n; ++i) {
			if (current[i].substr(0, position + 1) != b[i].substr(0, position + 1)) {
				nice = false;
				break;
			}
		}
		if (nice) {
			res = min(res, calc(current, position + 1) + 1);
		}
	}
	return M[make_pair(old, position)] = res;
}

int trivial() {
	int res = inf;
	for (int i = 0; i < (1 << l); ++i) {
		vector < string > cur = a;
		int bits = 0;
		for (int j = 0; j < l; ++j) {
			if ((i & (1 << j)) == 0) {
				continue;
			}
			++bits;

			for (int k = 0; k < n; ++k) {
				cur[k][j] = (cur[k][j] == '1' ? '0' : '1');
			}
		}
		sort(cur.begin(), cur.end());
		if (cur == b) {
			if (bits < res) {
				res = bits;
			}
		}
	}
	return res;
}

void solve(int test) {
	M.clear();
	cin >> n >> l;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	b.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	//printf("%d\n", trivial());

	int res = calc(a, 0);
	if (res == inf) {
		printf("Case #%d: NOT POSSIBLE\n", test);
	} else {
		printf("Case #%d: %d\n", test, res);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}