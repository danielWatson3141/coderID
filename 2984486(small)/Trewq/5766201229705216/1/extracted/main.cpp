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
vector<int> mp[1000];
int vs[1000];
int dfs(int r)
{
	int count = 0, maxa = 0, maxb = 0, t;
	if (vs[r] == 0)
	{
		vs[r] = 1;
		for (int i = 0; i < mp[r].size(); i++)
		{
			if (!vs[mp[r][i]])
			{
				t = dfs(mp[r][i]);
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
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++)
	{
		int a, b,mx=0,tmp;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			mp[i].clear();
		for (int i = 0; i < n-1; i++)
		{
			scanf("%d %d", &a, &b);
			mp[a - 1].push_back(b - 1);
			mp[b - 1].push_back(a - 1);
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