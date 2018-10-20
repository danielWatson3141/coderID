#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



void solve()
{
	int n, l;
	cin >> n >> l;
	vector <string> h(n), r(n);
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	for (int i = 0; i < n; ++i)
		cin >> r[i];
	vector <int> hi(n), ri(n);
	vector <bool> f(n);
	for (int i = 0; i < n; ++i)
	{
		hi[i] = stoi(h[i], 0, 2);
		ri[i] = stoi(r[i], 0, 2);
	}
	int ans = 100;
	for (int i = 0; i < (1 << l); ++i)
	{
		for (int j = 0; j < n; ++j)
			f[j] = false;
		for (int j = 0; j < n; ++j)
		{
			hi[j] ^= i;
			for (int k = 0; k < n; ++k)
			{
				if (!f[k] && hi[j] == ri[k])
				{
					f[k] = true;
					break;
				}
			}
			hi[j] ^= i;
		}
		bool ok = true;
		for (int j = 0; j < n; ++j)
			ok &= f[j];
		if (ok)
		{
			int x = 0;
			for (int j = 0; j < l; ++ j)
			{
				if (i & (1 << j))
					++x;
			}
			ans = min(ans, x);
		}
	}
	if (ans != 100)
		cout << ans;
	else
		cout << "NOT POSSIBLE";
}

void main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
}