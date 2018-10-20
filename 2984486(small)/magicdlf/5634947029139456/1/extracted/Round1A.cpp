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
int check(int cur)
{
	vector<string> s,t;
	for(int i=0;i<N;i++)
	{
		s.push_back(g[i].substr(0,cur));
		t.push_back(gg[i].substr(0,cur));
	}
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	return s==t;
}
int best=0;
int dfs(int cur, int step)
{
	if(cur==L)
	{
		if(check(cur))
		{
			if(step<best)
				best=step;
			return 1;
		}
		return 0;
	}
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
			int ret=0;
			if(check(cur))
				ret=dfs(cur+1,step+1);
			if(ret) return 1;
			flip(cur);
		}
		else return 0;
	}
	else 
	{
		int ret=0;
		if(check(cur))
			ret=dfs(cur+1,step);
		if(ret) return 1;
		if(N-c1==c2)
		{
			flip(cur);
			if(check(cur))
				ret=dfs(cur+1,step+1);
			if(ret) return 1;
			flip(cur);
		}
	}
	return 0;
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