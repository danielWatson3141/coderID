#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[1010], n, t;

bool check()
{
	for (int i = 1; i < n; i++)
		if (a[i] == 0)
		{
			int tmp = a[i];
			a[i] = a[n - 1];
			a[n - 1] = tmp;
		}
	for (int i = 1; i < n; i++)
		if (a[i] != i) return true;
	return false;
}

int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (check())
			printf("Case #%d: GOOD\n", tt);
		else printf("Case #%d: BAD\n", tt);
	}
	return 0;
}
