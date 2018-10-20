#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, l;
char outs[10][11];
char outs2[10][11];
int matchs[10];
char devs[10][11];
int dp[10][1<<10];

int solve(int m)
{
	int ret = 0;
	for (int i = 0; i < n; ++i)
		strcpy(outs2[i], outs[i]);
	for (int i = 0; i < l; ++i)
	{
		if (((m>>i)&1) == 1)
		{
			ret++;
			for (int j = 0; j < n; ++j)
				outs2[j][i] = (outs2[j][i] == '0' ? '1' : '0');
		}
	}
	memset(matchs, -1, sizeof(matchs));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matchs[j] != -1)
				continue;
			else if (strcmp(devs[i], outs2[j]) == 0)
			{
				matchs[j] = i;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		if (matchs[i] == -1)
			return -2;
	return ret;
}

int f(int i, int m)
{
	if (i == l)
		return solve(m);
	else if (dp[i][m] != -1)
		return dp[i][m];
	int res1 = f(i+1, m);
	int res2 = f(i+1, m|(1<<i));
	int res;
	if (res1 == -2 && res2 == -2)
		res = -2;
	else if (res1 == -2 && res2 != -2)
		res = res2;
	else if (res2 == -2 && res1 != -2)
		res = res1;
	else
		res = min(res1, res2);
	return dp[i][m] = res;
}

int main()
{
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	for (int x = 0; x < t; ++x)
	{
		cin >> n >> l;
		for (int i = 0; i < n; ++i)
			cin >> outs[i];
		for (int i = 0; i < n; ++i)
			cin >> devs[i];
		memset(dp, -1, sizeof(dp));
		int res = f(0, 0);
		cout << "Case #" << x+1 << ": "; 
		if (res == -2)
			cout << "NOT POSSIBLE\n";
		else
			cout << res << "\n";
	}
}
