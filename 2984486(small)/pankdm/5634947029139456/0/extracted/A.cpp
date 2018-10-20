#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>


using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef vector <int> vi;
typedef vector <vi> vvi;

typedef vector<string> vs;


void change(string& s, const vi& flip) {
	for (int i = 0; i < sz(s); ++i) {
		if (flip[i] == 1) {
			if (s[i] == '1') s[i] = '0';
			else s[i] = '1';
		}
	}
}

void show(vs& a) {
	for (int i = 0; i < sz(a); ++i) {
		cerr << a[i] << endl;
	}
	cerr << "=====" << endl;
}

void solve() {
	int n;
	int l;
	cin >> n >> l;
	vs a(n);
	vs b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	
	bool ok = false;
	int best = 1e9;
	string start = b[0];
	for (int i = 0; i < n; ++i) {
		vi flip(l);
		string now = a[i];
		int num = 0;
		for (int j = 0; j < l; ++j) {
			if (start[j] != now[j]) {
				++num;
				flip[j] = 1;
			}
		}
		vs a0 = a;
		vs b0 = b;
		for (int j = 0; j < n; ++j) {
			change(a0[j], flip);
		}

		sort(all(a0));
		sort(all(b0));

		// cerr << endl;
		// cerr << "tried " << i << endl;
		// show(a0);
		// show(b0);

		if (a0 == b0) {
			ok = true;
			best = min(best, num);
		}

	}

	if (ok) {
		cout << best << endl;
	} else {
		cout << "NOT POSSIBLE" << endl;
	}

}




int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);
	//std::ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";
		solve();
	}


    return 0;
}

