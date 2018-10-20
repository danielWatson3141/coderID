#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

int flag[1005];

int solve(int k,vector<vector<int> > e,int N)
{
	flag[k]=1;
	vector<int> ans;
	for(int i=0;i!=e[k].size();++i)
	{
		if(flag[e[k][i]]==0)
			ans.push_back(solve(e[k][i],e,N));
	}
	sort(ans.begin(),ans.end());
	if(ans.size()>=2)
		return ans[ans.size()-1]+ans[ans.size()-2]+1;
	else
		return 1;
}

int main()
{
	ifstream f1("B-small-attempt0.in");
	ofstream f2("out.txt");
	int T;
	f1>>T;
	for(int tt=0;tt!=T;++tt)
	{
		f2<<"Case #"<<tt+1<<": ";
		int N;
		f1>>N;
		vector<vector<int> > e;
		for(int i=0;i<=N;++i)
		{
			vector<int> temp;
			e.push_back(temp);
		}
		for(int i=0;i!=N-1;++i)
		{
			int a,b;
			f1>>a>>b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		int ans=N;
		for(int i=1;i<=N;++i)
		{
			memset(flag,0,sizeof(flag));
			int temp=solve(i,e,N);
			ans=min(ans,N-temp);
		}
		f2<<ans<<endl;
	}
	return 1;
}