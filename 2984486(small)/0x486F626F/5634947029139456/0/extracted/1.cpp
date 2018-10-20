#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string s[160], t[160], c[160];
int ans;

void work() {
	int n, l, ans = 0x3f3f3f3f;
	cin >> n >> l;
	for(int i = 0; i < n; i ++)
		cin >> s[i]; 
	for(int i = 0; i < n; i ++)
		cin >> t[i];
	sort(t, t + n);
	int tot = 1 << l;
	for(int k = 0; k < tot; k ++) {
		for(int i = 0; i < n; i ++) {
			c[i] = s[i];
			for(int j = 0; j < l; j ++)
				if((k >> j) & 1) {
					if(c[i][j] == '0') c[i][j] = '1';
					else c[i][j] = '0';
				}
		}
		sort(c, c + n);
		bool flag = true;
		for(int i = 0; i < n; i ++)
			if(c[i] != t[i]) flag = false;
		if(flag) {
			int cnt = 0;
			for(int j = 0; j < l; j ++)
				cnt += ((k >> j) & 1);
			if(cnt < ans) ans = cnt;
		}
	}
	if(ans == 0x3f3f3f3f) printf("NOT POSSIBLE\n");
	else printf("%d\n", ans);
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i ++) 
		printf("Case #%d: ", i), work();
	return 0;
}
