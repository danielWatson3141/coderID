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

bool change[50];

int main(){
	int cas, T, n, l, i, j, k, ans, cnt;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++){
		scanf("%d %d", &n, &l);
		ans = l+1;
		for (i = 0; i < n; i++)
			cin >> s[i];
		for (i = 0; i < n; i++)
			cin >> t[i];
		sort(t, t+n);
		for (i = 0; i < n; i++){
			fill_n(change, l, 0);
			for (j = cnt = 0; j < l; j++){
				if (s[0][j] != t[i][j]){
					change[j] = 1;
					cnt++;
				}
			}
			for (j = 0; j < n; j++){
				tmp[j] = s[j];
				for (k = 0; k < l; k++)
					if (change[k])
						tmp[j][k] = '1' - tmp[j][k] + '0';
			}
			if (check(n)) ans = min(ans, cnt);
		}
		if (ans == l+1) printf("Case #%d: NOT POSSIBLE\n", cas);
		else printf("Case #%d: %d\n", cas, ans);
	}
}

