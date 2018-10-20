#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define BIG 1000000000
#define LL long long
#define MAXN 210
using namespace std;

int ntest, n, l;
string a[MAXN], b[MAXN], tmp[MAXN];

char flipChar(char c) {
	return c == '0' ? '1' : '0';
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> ntest;
	for (int test = 1; test <= ntest; test++) {
		cin >> n >> l;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(b, b + n);
		int ans = BIG;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				tmp[j] = a[j];
			int cnt = 0;
			for (int j = 0; j < l; j++)
				if (a[i][j] != b[0][j]) {
					cnt++;
					for (int k = 0; k < n; k++) 
						a[k][j] = flipChar(a[k][j]);
				}
			sort(a, a + n);
			bool ok = true;
			for (int j = 0; j < n; j++)
				if (a[j] != b[j]) ok = false;
			if (ok) ans = min(ans, cnt);
			for (int j = 0; j < n; j++)
				a[j] = tmp[j];
		}
		if (ans == BIG) cout << "Case #" << test << ": NOT POSSIBLE" << endl;
		else cout << "Case #" << test << ": " << ans << endl;
	}
}

