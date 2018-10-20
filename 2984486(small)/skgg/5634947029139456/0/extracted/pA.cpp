#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s[160], t[160], tmp[160];

bool check(int n){
	sort(tmp, tmp+n);
	for (int i = 0; i < n; i++)
		if (t[i] != tmp[i])
			return false;
	return true;
}

int main(){
	int cas, T, n, l, i, j, sw, ans, cnt;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++){
		scanf("%d %d", &n, &l);
		ans = l+1;
		for (i = 0; i < n; i++)
			cin >> s[i];
		for (i = 0; i < n; i++)
			cin >> t[i];
		sort(t, t+n);
		for (sw = 0; sw < (1<<l); sw++){
			for (i = 0; i < n; i++){
				tmp[i] = s[i];
				for (j = 0; j < l; j++){
					if ((1<<j)&sw)
						tmp[i][j] = '1' - tmp[i][j] + '0';
				}
			}
			if (check(n)){
				for (cnt = i = 0; i < l; i++)
					if ((1<<i)&sw) cnt++;
				ans = min(ans, cnt);
			}
		}
		if (ans == l+1) printf("Case #%d: NOT POSSIBLE\n", cas);
		else printf("Case #%d: %d\n", cas, ans);
	}
}

