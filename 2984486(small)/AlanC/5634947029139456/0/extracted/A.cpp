#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
#include <map>
#include <string>
#include <iostream>

using namespace std;

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define FOE(i, s, e) for (int i=(s); i<=(e); i++)
#define CLR(x, a) memset(x, a, sizeof(x))
#define LL long long int
#define N 205

int TC, n, L, f[N];
string s[N], t[N], r[N];

void solve(int tc){
	scanf("%d%d", &n, &L);
	int ret = L + 1;
	FOR(i, 0, n) cin >> s[i], r[i] = s[i];
	FOR(i, 0, n)
		cin >> t[i];
	sort(t, t + n);
	
	
	FOR(i, 0, n)
	FOR(j, 0, n){
		CLR(f, 0);
		int cnt = 0;
		FOR(k, 0, L)
			if (s[i][k] != t[j][k]) f[k] = 1, cnt++;
		FOR(k, 0, n){
			FOR(l, 0, L)
				r[k][l] = (((s[k][l] - '0') ^ f[l]) + '0');
		}	
		sort(r, r + n);
		int ok = 1;
		FOR(k, 0, n)
			if (r[k] != t[k]) {ok = 0; break;}
		if (ok) ret = min(ret, cnt);
	}
	if (ret != L + 1)
		printf("Case #%d: %d\n", tc, ret);
	else printf("Case #%d: NOT POSSIBLE\n", tc);
}


int main(){
	scanf("%d", &TC);
	FOR(i, 0, TC) solve(i + 1);
}
