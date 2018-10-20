#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

#include <random>

int main(){

	int T;
	int cnt = 0;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n; scanf("%d", &n);
		vector<int> v(n);
		FOR(i, n) scanf("%d", &v[i]);
		double pt = 0;
		FOR(i, n) {
			if (i == 0) continue;
			int idx = find(v.begin(), v.end(), i) - v.begin();
			if (i <= idx && idx <= i + 2) {
				if (i != n - 1) {
					pt -= 45 / (3 - (idx - i));
				}
			} else if (idx < i && i < idx + 10) {
				pt += 140 / (10 - (i - idx));
			} else {
				pt -= 0.35;
			}
		}
		printf("Case #%d: %s\n", t, pt > 0 ? "BAD" : "GOOD");
		if (pt > 0) cnt++;
	}
	cerr << cnt << endl;
	return 0;
}
