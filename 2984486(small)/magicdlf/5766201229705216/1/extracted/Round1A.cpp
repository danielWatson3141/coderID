// Round1A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "stdio.h"
using namespace std;

vector<int> g[1005];

int visited[1005]={};
int dfs(int cur)
{
	vector<int> ans;
	visited[cur]=1;
	for(int i=0;i<g[cur].size();i++)
	{
		int j=g[cur][i];
		if(visited[j]==1)
			continue;
		int ret=dfs(j);
		if(ret>0)
			ans.push_back(ret);
	}
	sort(ans.rbegin(),ans.rend());
	if(ans.size()<2) return 1;
	return ans[0]+ans[1]+1;
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		for(int i=0;i<1005;i++)
			g[i].clear();
		for(int i=0;i<N-1;i++)
		{
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int best=0;
		for(int i=1;i<=N;i++)
		{
			memset(visited,0,sizeof(visited));
			int ans=dfs(i);
			best=max(ans,best);
		}
		cout<<"Case #"<<tc+1<<": "<<N-best<<endl;
	}
	return 0;
}

//
//int main()
//{
//	int T;
//	cin>>T;
//	//freopen("A-small-attempt0.in","r",stdin);
//	//freopen("A-small-attempt0.out","w",stdout);
//	for(int tc=0;tc<T;tc++)
//	{
//		int N,L;
//		cin>>N>>L;
//		vector<string> g(N), gg(N);
//		for(int i=0;i<N;i++)
//			cin>>g[i];
//		for(int i=0;i<N;i++)
//			cin>>gg[i];
//		int flip[50]={};
//		int isgood=1;
//		for(int i=0;i<L;i++)
//		{
//			int c1=0,c2=0;
//			for(int j=0;j<N;j++)
//			{
//				if(g[j][i]=='1') c1++;
//				if(gg[j][i]=='1') c2++;
//			}
//			if(c1==c2) 
//			{
//				if(c1==N-c2)
//				{
//					flip[i]=2;
//				}
//				continue;
//			}
//			if(c1==N-c2)
//			{
//				for(int j=0;j<N;j++)
//				{
//					if(g[j][i]=='1')
//						g[j][i]='0';
//					else
//						g[j][i]='1';
//				}
//				flip[i]=1;
//			}
//			else
//			{
//				isgood=0;
//				break;
//			}
//		}
//		sort(g.begin(),g.end());
//		sort(gg.begin(),gg.end());
//		if(g!=gg) isgood=0;
//		if(isgood)
//		{
//			cout<<"Case #"<<tc+1<<": "<<ans<<endl;
//		}
//		else
//		{
//			cout<<"Case #"<<tc+1<<": NOT POSSIBLE"<<endl;
//		}
//	}
//	return 0;
//}