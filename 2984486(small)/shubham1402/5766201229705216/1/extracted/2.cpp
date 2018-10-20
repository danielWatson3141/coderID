#include<bits/stdc++.h>
using namespace std;
int dfs(vector<int> G[1010],vector<int> &visited,int n,int s)
{
	visited[s]=1;
	int i;
	int count=1;
	int arr[G[s].size()+5];
	for (i=0;i<G[s].size();i++)
	{
		if(visited[G[s][i]]==0 && G[G[s][i]].size()>=3)
			arr[i] = dfs(G,visited,n,G[s][i]);
		else if(visited[G[s][i]]==0)
		{
			visited[G[s][i]]=1;
			arr[i] = 1;
		}
		else
		{
			arr[i]=0;
		}
	}
	int max1=max(arr[0],arr[1]);
	int max2=min(arr[0],arr[1]);
	for (i=2;i<G[s].size();i++)
	{
		if(arr[i]>max1)
		{
			max2=max1;
			max1=arr[i];
		}
		else if(arr[i]>max2)
		{
			max2=arr[i];
		}
	}
	return count + max1 + max2;
}
int main()
{
	int t,n,x,y,i,j;
	ifstream cin("in2.txt");
	ofstream cout("out3.txt");
	cin>>t;
	j=1;
	while(j<=t)
	{
		cin>>n;
		vector<int> G[1010];
		
		for (i=0;i<n-1;i++)
		{
			cin>>x>>y;
			G[x-1].push_back(y-1);
			G[y-1].push_back(x-1);
		}
		int count=INT_MAX;
		for (i=0;i<n;i++)
		{
			if(G[i].size()>=2)
			{
				vector<int> visited(1010,0);
				int x = n-dfs(G,visited,n,i);
				if(x<count)
				{
					count=x;
				}
				if(count==0)
					break;
			}
		}
		if(count==INT_MAX)
			count = n-1;
		cout<<"Case #"<<j<<": "<<count<<endl;
		j++;
	}
	return 0;
}

