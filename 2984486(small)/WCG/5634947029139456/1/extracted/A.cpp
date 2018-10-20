#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int t, tt;
	
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		long long n, l;
		cin >> n >> l;
		vector<long long> a;
		vector<long long> b;
		
		for (int i = 0; i < n; ++i)
		{
			long long k = 0;
			string s;
			cin >> s;
			for (int j = 0; j < l; ++j)
				k = k * 2 + (s[j] - '0');
			a.push_back(k);
		}
		for (int i = 0; i < n; ++i)
		{
			long long k = 0;
			string s;
			cin >> s;
			for (int j = 0; j < l; ++j)
				k = k * 2 + (s[j] - '0');
			b.push_back(k);
		}
		
		sort(b.begin(), b.end());
		
		long long c;
		long long best = l+1;
		for (int i = 0 ;i < n; ++i)
		{
			sort(a.begin(), a.end());
			c = a[0] ^ b[i];
			for (int j = 0; j < n; ++j)
				a[j] = a[j] ^ c;
			sort(a.begin(), a.end());
			bool eq = true;
			for (int j = 0; j < n; ++j)
				if (a[j] != b[j])
					eq = false;
			for (int j = 0; j < n; ++j)
				a[j] = a[j] ^ c;
			if (eq)
			{
				long long cur = 0;
				while (c > 0)
				{
					cur++;
					c = c - (c & (-c));
				}
				if (cur < best)
					best = cur;
			}
		}
		cout << "Case #" << tt << ": ";
		if (best == l + 1)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << best << endl;
	}
	
	return 0;
}
