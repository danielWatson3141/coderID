#include <bits/stdc++.h>
using namespace std;

int countBit(long long n)
{
	int res = 0;
	while (n) res += n & 1, n >>= 1;
	return res;
}

int main()
{
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		int n, m;
		long long mask[222][222];
		map <long long,int> cnt;
		string outlets[222], devices[222];
		
		cin >> n >> m;
		
		for (int i = 0; i < n; i++) cin >> outlets[i];
		for (int i = 0; i < n; i++) cin >> devices[i];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				mask[i][j] = 0;
				for (int k = 0; k < m; k++) 
					mask[i][j] = mask[i][j] << 1 | (outlets[i][k] != devices[j][k]);
				cnt[mask[i][j]]++;
			}
			
		int ans = -1;
		for (map <long long,int>::iterator it = cnt.begin(); it != cnt.end(); it++)
			if (it -> second == n)
			{
				int flip = countBit(it -> first);
				if (ans < 0) ans = flip;
				else ans = min(ans, flip);
			}
		
		printf("Case #%d: ", noTest);
		if (ans < 0) cout << "NOT POSSIBLE" << endl;
		else cout << ans << endl;
	}
}
