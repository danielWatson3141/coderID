#include <iostream>
using namespace std;

long double f[1005][1005];
long double tmp[1005];

int main()
{
	int t, n = 1000;
	cin >> t;
		
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			f[i][j] = (i == j) ? 1 : 0;
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 0; i <= n; ++i)
		{
			tmp[i] = f[k][i];
			f[k][i] = f[k][i] / n;
		}
		for (int i = 1; i <= n; ++i)
		{
			if (k == i)
				continue;
			for (int j = 1; j <= n; ++j)
			{
				f[k][j] += f[i][j] / n;
				f[i][j] = f[i][j] * (n - 1) / n + tmp[j] / n;
			}
		}
	}
	
	for (int tt = 1; tt <= t; ++tt)
	{
		cin >> n;
		long double p = 1;
		for (int i = 1; i <= n; ++i)
		{
			int j;
			cin >> j;
			p = p * n * f[i][j+1];
		}
		if (p > 1)
			cout << "Case #" << tt << ": BAD" << endl;
		else
			cout << "Case #" << tt << ": GOOD" << endl;
	}
	
	return 0;
}
