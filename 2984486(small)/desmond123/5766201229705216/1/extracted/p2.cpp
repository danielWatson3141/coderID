#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

typedef long long int ll;

int DFS(vector<vector<int> > &G, int root, vector<bool> &visited)
{
	// cout<<root<<" ";
	visited[root] = true;
	vector<int> v;
	for(int i=0;i<G[root].size();i++)
	{
		int n;
		if(visited[G[root][i]] == false)
		{
			n = DFS(G,G[root][i],visited);
			v.push_back(n);
		}
	}
	if(v.size() < 2)
	{
		return 1;
	}
	else
	{
		sort(v.begin(),v.end());
		return 1 + v[v.size()-1] + v[v.size()-2];
	}
}
int main()
{
	vector<long long int> ans;
	int t;
	cin>>t;
	while (t--)
	{
		int n,e;
		cin>>n;
		vector<vector<int> > G(vector<vector<int> >(n+1));
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int minCount = n;
		for(int i=1;i<=n;i++)
		{
			int count = 0;
			vector<bool> visited(n+1,false);
			// cout<<"i = "<<i<<" Size = "<<G[i].size()<<endl;
			count = n-DFS(G,i,visited);
			if(count < minCount)
				minCount = count;
		}
		ans.push_back(minCount);
	}

	for(int i=0; i<ans.size();i++)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}
}