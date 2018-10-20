#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

#define vt vector
#define ll long long

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int cases = 1; cases <= t; cases++)
	{
		int n, l;
		cin >> n >> l;
		string s;
		vt<ll> devices(n, 0), power(n, 0);
		for(int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for(int j = 0; j < l; j++)
			{
				power[i] <<= 1;
				if (s[j] == '1')
					power[i] += 1;
			}
		}
		for(int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for(int j = 0; j < l; j++)
			{
				devices[i] <<= 1;
				if (s[j] == '1')
					devices[i] += 1;
			}
		}
		int ans = l;
		bool possible = false;
		for(int i = 0; i < n; i++)
		{
			ll swt = devices[0] ^ power[i];
			vt<bool> t(n, false);
			vt<bool> f(n, false);
			f[0] = true;
			t[i] = true;
			for(int j = 1; j < n; j++)
			{
				for(int k = 0; k < n; k++)
					if (!t[k] && devices[j] == (power[k] ^ swt))
					{
						t[k] = true;
						f[j] = true;
						break;
					}
				if (f[j])
					continue;
				else
					break;
			}
			if (f[n-1])
			{
				possible = true;
				int val = 0;
				while(swt > 0)
				{
					if (swt & 1)
						val++;
					swt >>= 1;
				}
				ans = min(ans, val);
			}
		}
		if (possible)
			cout << "Case #" << cases << ": " << ans << endl;
		else
			cout << "Case #" << cases << ": " << "NOT POSSIBLE" << endl;
	}
	return 0;
}