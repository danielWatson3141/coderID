#include <algorithm>
#include <stdio.h>
#include <string.h>
#define REP(i, n) for (i = 0; i < (n); i++)
#define REP1(i, n) for (i = 1; i <= (n); i++)
using namespace std;

const int N = 1000 +10;

int ans1, ans2, nowtd, tdnum, n;
int a[N];
int f[N];

void ri()
{
	int i;

	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
}

int go(int x)
{
	int i, j, result = 0;

	memset(f, 0, sizeof(f));
	REP(i, n)
	{
		f[i] = 1;
		REP(j, i - 1) if ((a[j] - a[i]) * x > 0) f[i] = max(f[i], f[j] + 1);
		result = max(result, f[i]);
	}
	return result;
}

void solve()
{
	ans1 = go(-1);
	ans2 = go(1);
}

void print()
{
	printf("Case #%d: ", nowtd);
	if (ans1 < ans2) printf("GOOD\n"); else printf("BAD\n");
}

int main()
{
	scanf("%d", &tdnum);
	REP1(nowtd, tdnum)
	{
		ri();
		solve();
		print();
	}
	return 0;
}
