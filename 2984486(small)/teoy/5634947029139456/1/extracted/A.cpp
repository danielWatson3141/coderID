#include "iostream"
#include "cstdio"
#include "string"
#include "cstring"
#include "algorithm"
#include "map"
using namespace std;

const int N = 500;
string a[N], b[N], c[N];

int main() {
	freopen("A-large.in","r", stdin);
	map<string, int> MAP;
	int T, g = 0;
	scanf("%d", &T);
	while (T--) {
		MAP.clear();
		int n, l;
		int ans = 0x3ffffff;
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; ++ i) cin >> a[i];
		for (int i = 0; i < n; ++ i) cin >> b[i];
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				string s = "";
				for (int k = 0; k < l; ++ k) {
					if (a[i][k] == b[j][k]) s += "0";
					else s += "1";
				}
				MAP[s] ++;
			}
		}
		map<string, int>::iterator iter;
		for (iter = MAP.begin(); iter != MAP.end(); ++iter) {
			if (iter -> second == n) {
				string s = iter -> first;
				int ret = 0;
				for (int i = 0; i < l; ++ i) {
					ret += (s[i] == '1');
				}
				ans = min(ans, ret);
			}
		}
		if (ans > 100) {
			printf("Case #%d: NOT POSSIBLE\n", ++g);	
		} else {
			printf("Case #%d: %d\n", ++g, ans);
		}
	}
	return 0;
}
