// Round1A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "stdio.h"
using namespace std;

int N,L;
vector<string> g, gg;
void flip(int cur)
{
	for(int i=0;i<N;i++)
	{
		if(g[i][cur]=='1')
			g[i][cur]='0';
		else
			g[i][cur]='1';
	}
}
int best=0;
void dfs(int cur, int step)
{
	if(cur==L)
	{
		vector<string> t=g,s=gg;
		sort(t.begin(),t.end());
		sort(s.begin(),s.end());
		if(t==s)
		{
			if(step<best)
				best=step;
		}
		return;
	}
	if(step>best)
		return;
	int c1=0,c2=0;
	for(int i=0;i<N;i++)
	{
		if(g[i][cur]=='1') c1++;
		if(gg[i][cur]=='1') c2++;
	}
	if(c1!=c2)
	{
		if(N-c1==c2)
		{
			flip(cur);
			dfs(cur+1,step+1);
			flip(cur);
		}
		else return;
	}
	else 
	{
		dfs(cur+1,step);
		if(N-c1==c2)
		{
			flip(cur);
			dfs(cur+1,step+1);
			flip(cur);
		}
	}
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		cin>>N>>L;
		string str;
		g.clear();gg.clear();
		for(int i=0;i<N;i++)
		{
			cin>>str;
			g.push_back(str);
		}
		for(int i=0;i<N;i++)
		{
			cin>>str;
			gg.push_back(str);
		}
		best=888;
		dfs(0,0);

		if(best!=888)
		{
			cout<<"Case #"<<tc+1<<": "<<best<<endl;
		}
		else
		{
			cout<<"Case #"<<tc+1<<": NOT POSSIBLE"<<endl;
		}
	}
	return 0;
}