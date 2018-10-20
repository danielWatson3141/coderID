#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <queue>
#include <complex>
#include <functional>
#include <sstream>

using namespace std;

int n, l;
vector<long long> a, b, c;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	cin >> n >> l;
    	a.resize(n);
    	b.resize(n);
    	for (int i = 0; i < n; i++)
    	{
    		string s;
    		cin >> s;
    		long long cur = 0;
    		for (int j = 0; j < l; j++)
    			cur = cur * 2 + (s[j] == '1');
    		a[i] = cur;
    	}
    	for (int i = 0; i < n; i++)
    	{
    		string s;
    		cin >> s;
    		long long cur = 0;
    		for (int j = 0; j < l; j++)
    			cur = cur * 2 + (s[j] == '1');
    		b[i] = cur;
    	}
    	int best = -1;
    	sort(b.begin(), b.end());
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
    		{
    			c.clear();
    			int fail = 0;
    			for (int k = 0; k < n; k++)
    				c.push_back(a[i] ^ b[j] ^ a[k]);
	 		   	sort(c.begin(), c.end());
    			if (c == b)
    			{
    				int cur = 0;
    				for (int k = 0; k < l; k++)
    					cur += (a[i] >> k) % 2 != (b[j] >> k) % 2;
    				if (best == -1 || best > cur)
    					best = cur;
    			}
    		}
    	cout << "Case #" << tc + 1 << ": ";
    	if (best == -1)
    		cout << "NOT POSSIBLE";
    	else
    		cout << best;
    	cout << endl;
    }
    return 0;
}