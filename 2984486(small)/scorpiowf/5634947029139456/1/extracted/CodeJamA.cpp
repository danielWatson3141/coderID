#include <iostream>
using namespace std;
int n, m;
char outlet[160][80];
char device[160][80];
__int64 out[160];
__int64 dev[160];
void updateAll(int k)
{
	int i;
	__int64 t;
	for (i = 0; i <n; i++)
	{
		t = dev[i];
		dev[i] = ((t | (~t & k)) & (~(t&k)));
	}
}
bool check() {
	int i, j;
	bool flag;
	for (i = 0; i < n; i++)
	{
		flag = false;
		for (j = 0; j < n; j++)
		{
			if (dev[i] == out[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			return false;
		}
	}
	return true;
}
void solve(int tc)
{
	scanf("%d %d", &n, &m);
	int i;
	int ans = 100000;
	__int64 j;
	for (i = 0; i < n; i++) {
		scanf("%s", &outlet[i]);
		out[i] = 0;
		for (j = 0; j < m; j++)
		{
			if (outlet[i][j] == '1') {
				out[i] |= (1<<j);
			}
		}
	}
	for (i = 0; i < n; i++) {
		scanf("%s", &device[i]);
		dev[i] = 0;
		for (j = 0; j < m; j++)
		{
			if (device[i][j] == '1')
			{
				dev[i] |= (1<<j);
			}
		}
	}
	int c = 0;
	__int64 k = 0;
	for (i = 0; i < n; i++)
	{
		k = 0;
		c = 0;
		for (j = 0; j < m; j++)
		{
			if ((out[0] & (1<<j)) != (dev[i] & (1<<j)))
			{
				k |= (1<<j);
				c++;
			}
		}
		updateAll(k);
		if (check())
		{
			if (c < ans)
			{
				ans = c;
			}
		}
		updateAll(k);
	}
	if (ans < 100000)
	{
		printf("Case #%d: %d\n", tc, ans);
	}
	else
	{
		printf("Case #%d: NOT POSSIBLE\n", tc);
	}
}
int main()
{
//	freopen("c:\\data\\r1\\A-large.in", "r", stdin);
//	freopen("c:\\data\\r1\\A-large.out", "w", stdout);
	
	int tc;
	scanf("%d", &tc);
	int i;
	for (i = 1; i <= tc; i++)
	{
		solve(i);
	}
	return 0;
}