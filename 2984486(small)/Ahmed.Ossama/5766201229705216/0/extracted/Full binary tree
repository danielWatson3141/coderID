#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <map>
#include <set>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <stack>
#include <iomanip>
#define ll long long
#define endl '\n'
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pull pair<ull,ull>
ll MOD=1000000007;
ll inf=1e18;
using namespace std;
bool Taken[1001];
vector< vector<int> > Children;
vector<int> V;
int DFS(int node)
{
	Taken[node]=true;
	int child=0;
	int ans=0;
	int X;
	for(int i=0;i<Children[node].size();i++)
	{
		if(Taken[Children[node][i]]){continue;}
		child+=1;
		X=DFS(Children[node][i]);
		ans+=X;
	}
	if(child==0)
	{
		return ans;
	}
	if(child==1)
	{
		return ans+1;
	}
	return ans+child-2;
}


int main()
{
	
	freopen("/home/ahmed_ossama/B-example","r",stdin);
	freopen("/home/ahmed_ossama/OUTPUT1A.out","w",stdout);
	
	int T,t;
	int n,i,x,y;
	
	cin>>T;
	int best,start;
	for(t=0;t<T;t++)
	{
		Children.clear();
		cin>>n;
		for(i=0;i<n;i++)
		{
			Children.pb(V);
		}
		for(i=0;i<n-1;i++)
		{
			cin>>x>>y;
			x--;y--;
			Children[x].pb(y);
			Children[y].pb(x);
		}
		best=0;
		for(start=0;start<n;start++)
		{
			for(i=0;i<n;i++)
			{
				Taken[i]=false;
			}
			if(start==0){best=DFS(start);}
			else{best=min(best,DFS(start));}
		}
		cout<<"Case #"<<t+1<<": "<<best<<endl;
	}
	
	return 0;
}
