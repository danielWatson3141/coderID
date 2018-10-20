#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>
#include <set>
#include <bitset>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

vector<vector<int> > v;
vector<int> cost;
vector<int> cnt;

int solve(int cur, int p)
{
	int res=0;
	cnt[cur]=1;
	vector<int> to_cnt;
	vector<int> to_cost;
	for(int i=0;i<v[cur].size();i++)
	{
		if(v[cur][i]!=p)
		{
			to_cost.push_back(solve(v[cur][i],cur));
			to_cnt.push_back(cnt[v[cur][i]]);
			cnt[cur]+=to_cnt.back();
		}
	}
	for(int i=0;i<to_cnt.size();i++)
	{
		res+=to_cnt[i];
		to_cost[i]-=to_cnt[i];
	}
	sort(to_cost.begin(),to_cost.end());
	if(to_cost.size()>=2)
	{
		res+=to_cost[0];
		res+=to_cost[1];
	}
	return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		int n;
		scanf("%d",&n);
		v.clear(); v.resize(n);
		cost.clear(); cost.resize(n);
		cnt.clear(); cnt.resize(n);
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int res=n;
		for(int i=0;i<n;i++)
			res=min(res,solve(i,-1));
		printf("Case #%d: %d\n",test,res);
	}
	return 0;
}
