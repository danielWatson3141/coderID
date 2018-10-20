#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAX_N 65

using std::sort;

bool vis[MAX_N];
int sticks[MAX_N], n, sum;

bool cmp(int a, int b)
{
	return a > b;
}

bool read()
{
	int i;

	scanf("%d", &n);
	if (n == 0) return false;

	for (i = sum = 0; i < n; i++) {
		scanf("%d", &sticks[i]);
		sum += sticks[i];
	}
	
	return true;
}

bool combination(int leftSticks, int left, int slen)
{
	int i;

	if (leftSticks == 0 && left == 0) return true;
	if (left == 0) left = slen;

	for (i = 0; i < n; i++) {
		if (!vis[i] && left >= sticks[i]) {
			vis[i] = true;
			if (combination(leftSticks - 1, left - sticks[i], slen)) 
				return true;
			vis[i] = false;
			if (left == slen || left == sticks[i]) break;
		}
	}

	return false;
}

void solve()
{
	int i;

	sort(sticks, sticks + n, cmp);

	for (i = sticks[0]; i <= sum; i++) {
		if (sum % i) continue;
		memset(vis, 0, sizeof(vis));
		if (combination(n, i, i)) break;
	}

	printf("%d\n", i);
}

int main()
{
	while (read()) {
		solve();
	}
	return 0;
}

