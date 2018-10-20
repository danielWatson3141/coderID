#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> G[1000];
//bool done[1000];
int counts[1000];
int mind[1000];
void dfs(int v, int p)
{
	counts[v]=1;
	int ch=0;
	int td=0;
	int m1=-1;
	int m2=-1;
	for (int i=0;i<G[v].size();i++)
	{
		if (G[v][i]!=p)
		{
			dfs(G[v][i],v);
			ch++;
			counts[v]+=counts[G[v][i]];
			td+=mind[G[v][i]];
			if (counts[G[v][i]]-mind[G[v][i]]>m1)
				m1=counts[G[v][i]]-mind[G[v][i]];
			else if (counts[G[v][i]]-mind[G[v][i]]>m2)
				m2=counts[G[v][i]]-mind[G[v][i]];
		}
	}
	if (ch<2)
	{
		mind[v]=counts[v]-1;
	}
	else if (ch==2)
	{
		mind[v]=td;
	}
	
	else
	{
		mind[v]=counts[v]-1-m1-m2;
		
	}
	
}

int main()
{
	int t;
	cin >> t;
	for (int x=1;x<=t;x++)
	{
		int n;
		cin >> n;
		int a,b;
		for (int i=0;i<n;i++)
		{
			G[i].clear();
			
		}
		for (int i=0;i<n-1;i++)
		{
			cin >> a >> b;
			G[a-1].push_back(b-1);
			G[b-1].push_back(a-1);
		}
		int best=n-1;
		for (int i=0;i<n;i++)
		{
		
			dfs(i,-1);
			best=min(best,mind[i]);
		}
		cout << "Case #" << x << ": " << best << endl;
	}
}