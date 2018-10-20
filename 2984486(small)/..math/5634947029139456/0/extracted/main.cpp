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

string XOR(string a, string b) {
	string ret;
	FOR(i, sz(a)) ret.push_back(a[i] == b[i] ? '0' : '1');
	return ret;
}

int main(){

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {

		int n, l; cin >> n >> l;
		vector<string> v(n), to(n);
		FOR(i, n) cin >> v[i];
		FOR(i, n) cin >> to[i];
		sort(to.begin(), to.end());

		int ans = 1000000;
		FOR(i, n) {
			string x = XOR(v[0], to[i]);
			vector<string> vnext;
			FOR(j, n) vnext.push_back(XOR(v[j], x));
			sort(vnext.begin(), vnext.end());
			if (vnext == to) {
				int cnt = 0;
				FOR(j, l){
					if (x[j] == '1') {
						cnt++;
					}
				}
				ans = min(ans, cnt);
			}
		}

		printf("Case #%d: ", t);
		if (ans == 1000000) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
