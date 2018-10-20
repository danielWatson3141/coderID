#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

//#define test

using namespace std;

const int N = 150 + 10;
const int L = 40 + 10;
const int INF = 12321;

struct String {
	char str[L];
} s[N][N];

char dev[N][L], out[N][L];
int iter[N];
int n, l;

bool cmp(String s1, String s2) {
	for(int i = 0; i < l; i++) {
		if(s1.str[i] != s2.str[i])	return s1.str[i] < s2.str[i];
	}
	return true;
}

bool cmp2(char *s1, char *s2) {
	for(int i = 0; i < l; i++) {
		if(s1[i] != s2[i])	return s1[i] < s2[i];
	}
	return true;
}

bool eq(char *s1, char *s2) {
	for(int i = 0; i < l; i++)	if(s1[i] != s2[i])	return false;
	return true;
}

void dfs(int k, char *tmp, int &ans) {
	if(k == n) {
		#ifdef test
		puts("OAO");
		#endif // test
		int sum = 0;
		for(int i = 0; i < l; i++)	sum += tmp[i];
		ans = min(ans, sum);
		return ;
	}

	for(int &i = iter[k]; i < n; i++) {
		if(eq(tmp, s[k][i].str)) {
			#ifdef test
			printf("%d: %d\n", k, i);
			#endif // test
			dfs(k+1, tmp, ans);
		}
		if(!cmp2(s[k][i].str, tmp))	break;
	}
}

int main() {
	int t;
	scanf("%d", &t);

	for(int kase = 1; kase <= t; kase++) {
		scanf("%d%d", &n, &l);

		for(int i = 0; i < n; i++)	scanf("%s", out[i]);
		for(int i = 0; i < n; i++)	scanf("%s", dev[i]);

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < l; k++) {
					s[i][j].str[k] = (dev[i][k] - '0') ^ (out[j][k] - '0');
				}
				s[i][j].str[l] = '\0';
			}
		}

		for(int i = 0; i < n; i++)	sort(s[i], s[i] + n, cmp);

		#ifdef test
		puts("-----");
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < l; k++)	putchar(s[i][j].str[k] + '0');
				putchar(j == n - 1 ? '\n' : ' ');
			}
		}
		puts("-----");
		#endif // test

		char tmp[L];
		tmp[l] = '\0';
		int ans = INF;
		fill(iter, iter + n, 0);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < l; j++) {
				tmp[j] = s[0][i].str[j];
			}
			#ifdef test
			printf("--%d: ", i);
			for(int j = 0; j < l; j++)	printf("%d", tmp[j]);
			putchar('\n');
			#endif // test

			dfs(1, tmp, ans);
		}

		printf("Case #%d: ", kase);
		if(ans == INF) {
			puts("NOT POSSIBLE");
			continue;
		}
		printf("%d\n", ans);
	}

	return 0;
}
