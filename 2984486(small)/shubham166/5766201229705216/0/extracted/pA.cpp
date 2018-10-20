#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <cstring>

using namespace std;

vector<int> indegree;
vector<vector<int> > adjlist;


bool comp(pair<int,int> p1,pair<int,int> p2)
{
	return p1.first < p2.first;
}
/*
int getmin2(int N);
{
	vector<int> wt;
	wt.clear();
	wt.resize(N+1);
	sort(indegree.begin(),indegree.end(),comp);
	for(int i = 1;i<=N;i++)
	{
		if(indegree[i].first == 1)
		{
			wt[indegree[i].second] = 1;
		}
		else
		{
			for(int j = 0;j<adjlist[i].size();j++)
			{
				if(wt[j]!=0)
					wt[i]+= wt[j];

			}
		}
	}
}




*/





int getmin(int N)
{
	int two = 0,three = 0,one = 0,more = 0;
	// sort(indegree.begin(),indegree.end(),comp);
	int count = 0;
	for(int i = 1;i<N;i++)
	{
		if(indegree[i] == 1)
			one++;
		else if(indegree[i] == 2)
			two++;
		else if(indegree[i] == 3)
			three++;
		else 
			count +=indegree[i]-3;
	}
	int ans = 0;
	if(two==0)
	{
		ans = count +1;
	}
	else
		ans = two + count -1;
	
	return ans;
}
int main()
{
	int T,N;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&N);
		if(N==2|| N==1)
		{
			printf("Case #%d: 0\n",t);
			continue;
		}
		int v1,v2;
		indegree.clear();
		adjlist.clear();
		indegree.resize(N+1);
		/*for(int i =1;i<=N;i++)
			indegree[i] = make_pair(0,i);*/
		//adjlist.resize(N+1);
		for(int i = 0;i<N-1;i++)
		{
			scanf("%d %d",&v1,&v2);

			indegree[v1]++;
			indegree[v2]++;
			// adjlist[v1].push_back(v2);
			// adjlist[v2].push_back(v1);
		}
		int ans = getmin(N);
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}