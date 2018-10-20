#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 150+5, MAXL = 40+5;
int T, N, L, ans;
char s[2][MAXN][MAXL];
string str[2][MAXN];
bool cmp(const char *a, const char *b) {
	return strcmp(a, b) < 0;
}
bool check() {
	string x[2][MAXN];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < N; j++)
			x[i][j] = str[i][j];
	for (int i = 0; i < 2; i++)
		// sort(s[i], s[i]+N, cmp);
		sort(x[i], x[i]+N);
	// for (int j = 0; j < N; j++) if (!strcmp(s[0][j], s[1][j]))
	for (int j = 0; j < N; j++) if (x[0][j] != x[1][j])
		return false;
	return true;
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d%d", &N, &L);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < N; j++)
				// scanf("%s", s[i][j]);
				cin >> str[i][j];
		int ans = INF;
		for (int j = 0; j < N; j++) {
			int flip[MAXL] = {}, cnt = 0;
			for (int k = 0; k < L; k++) {
				if (str[0][0][k] != str[1][j][k])
					flip[k] = 1, cnt++;
			}
			// for (int k = 0; k < L; k++)
			// 	cout << flip[k] << ' ';
			// cout << endl;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < L; k++) if (flip[k])
					str[0][j][k] = 1-(str[0][j][k]-'0')+'0';
			}
			if (check())
				ans = min(ans, cnt);
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < L; k++) if (flip[k])
					str[0][j][k] = 1-(str[0][j][k]-'0')+'0';
			}
		}
		if (ans < INF)
			printf("Case #%d: %d\n", cas, ans);
		else
			printf("Case #%d: NOT POSSIBLE\n", cas);
	}
	return 0;
}