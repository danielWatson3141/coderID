#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<memory.h>
#include<unordered_set>
using namespace std;
int n;
int mp[1000][1000], vs[1000];
int dfs(int r)
{
	int count = 0, maxa = 0, maxb = 0, t;
	if (vs[r] == 0)
	{
		vs[r] = 1;
		for (int i = 0; i < n; i++)
		{
			if (mp[r][i] && !vs[i])
			{
				t = dfs(i);
				count++;
				if (t > maxb)
				{
					maxb = t;
					if (maxb > maxa)
						swap(maxa, maxb);
					
				}
			}
		}
		if (count >= 2)
			return maxa + maxb + 1;
		else
			return 1;
	}
}
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++)
	{
		int a, b,mx=0,tmp;
		cin >> n;
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < n-1; i++)
		{
			cin >> a >> b;
			mp[a-1][b-1] = mp[b-1][a-1] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			memset(vs, 0, sizeof(int)*n);
			tmp=dfs(i);
			if (mx < tmp)
				mx = tmp;
		}
		cout << "Case #" << cs << ": " << n - mx << endl;
	}
	return 0;
}