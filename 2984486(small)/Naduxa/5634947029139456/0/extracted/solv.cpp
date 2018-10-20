#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		int n, l;
		cin >> n >> l;
		vector <string> c;
		vector <string> best;
		string s;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			c.push_back(s);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			best.push_back(s);
		}
		sort(best.begin(),best.end());
		int ans = 20;
		for (int i = 0; i < (2 << (l - 1)); i++)
		{
			vector <string> c1;
			c1 = c;
			int mask = i;
			int k = l - 1;
			int min = 0;
			while (mask != 0)
			{
				if (k < 0) break;
				if ((mask & 1) == 1)
				{
					for (int j = 0; j < n; j++)
					{
					c1[j][k] = (1 - (c1[j][k] - '0') + '0');
					}
					min++;
				}
				mask = (mask >> 1);
				//cout << mask << endl;
				k--;
			}
			int sov = 0;
			sort(c1.begin(),c1.end());
			for (int j = 0; j < n; j++)
			{
				if (c1[j] == best[j]) sov++;
			}
			if (sov == n && ans > min)
			{
				ans = min;
			}
		}
		cout << "Case #" << q + 1<< ": ";
		if (ans <= l) cout << ans;
		else cout << "NOT POSSIBLE";
		cout << endl;
	}
    return 0;

}