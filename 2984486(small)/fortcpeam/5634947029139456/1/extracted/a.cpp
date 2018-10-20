#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int MAXN = 151;

LL a[MAXN], b[MAXN], c[MAXN];
int n, L, ans;

void get(LL &x)
{
	char st[51];
	scanf("%s", st);
	x = 0;
	for (int i = 0; i < L; i ++)
		x = x * 2 + st[i] - '0';
}

int solve()
{
	LL LIM = (1LL << 45) - 1;
	int ret = -1;
	for (int i = 0; i < n; i ++){//a[0]: b[i]
		LL s = (b[i] ^ a[0]) & LIM;
		int t = 0;
		for (int k = 0; k < L; k ++)
			if (s & (1LL << k))
				t ++;
		for (int j = 0; j < n; j ++)
			c[j] = (a[j] ^ s) & LIM;
		sort(c, c + n);
		for (int j = 0; j < n; j ++)
			if (c[j] != b[j]){
				t = -1; break;
			}
		if (t != -1 && (t < ret || ret == -1))
			ret = t;
	}
	return ret;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t ++){
		scanf("%d%d", &n, &L);
		for (int i = 0; i < n; i ++)
			get(a[i]);
		for (int i = 0; i < n; i ++)
			get(b[i]);
		sort(b, b + n);
		ans = solve();
		printf("Case #%d: ", t+1);
		if (ans == -1)
			puts("NOT POSSIBLE");
		else
			printf("%d\n", ans);
	}
	return 0;
}
