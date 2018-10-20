#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++)
	{
		char c;
		int n, l,count;
		long long t;
		long long outl[150], dev[150];
		long long mn = 50;
		cin >> n >> l;
		for (int i = 0; i < n; i++)
		{
			t = 0;
			for (int j = 0; j < l; j++)
			{
				cin >> c;
				t <<= 1;
				if (c == '1')
				{
					t |=1;
				}
			}
			outl[i] = t;
		}
		for (int i = 0; i < n; i++)
		{
			t = 0;
			for (int j = 0; j < l; j++)
			{
				cin >> c;
				t <<= 1;
				if (c == '1')
				{
					t |= 1;
				}
			}
			dev[i] = t;
		}
		//sort(dev, dev + n);
		set<long long> st;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				st.clear();
				t = dev[i] ^ outl[j];
				for (int k = 0; k < n; k++)
					st.insert(outl[k] ^ t);
				bool succ = 1;
				for (int k = 0; k < n; k++)
				{
					if (st.find(dev[k]) == st.end())
					{
						succ = 0;
						break;
					}
				}
				if (succ)
				{
					count = 0;
					while (t)
					{
						t &= t - 1;
						count++;
					}
					if (count < mn)
						mn = count;
				}
			}
		}
		cout << "Case #" << cs << ": ";
		if (mn < 50)
			cout << mn << endl;
		else
			cout << "NOT POSSIBLE" << endl;
	}
	return 0;
}