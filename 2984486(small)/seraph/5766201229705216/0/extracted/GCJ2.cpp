#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;

vector<int> v[16];

int byk(int n, int root)
{
	vector<int> temp(v[n].size());
	
	vector<int> vv;
	for (int i=0;i<v[n].size();i++)
	{
		if (v[n][i] == root) continue;
		
		int t = byk(v[n][i], n);
		vv.push_back(t);
	}
	
	if (v[n].size()==1) return 1;
	
	sort(vv.begin(), vv.end());
	if (vv.size()==1) return 1;
	
	return vv[vv.size()-1] + vv[vv.size()-2] + 1;
}

int main()
{
	int tc;
	cin>>tc;
	int count=1;
	while (tc--)
	{
		int ans = 0;
		for (int i=0;i<16;i++) v[i].clear();
		int n;
		cin>>n;
		for (int i=0;i<n-1;i++)
		{
			int a, b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i=1;i<=n;i++)
		{
			ans = max(ans, byk(i,0));
		}
		cout<<"Case #"<<count++<<": "<<n-ans<<endl;
	}
	return 0;
}

