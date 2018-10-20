#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define WRITE

void output()
{
	static int cc = 1;
	printf("Case #%d: ", cc++);
}
vector<int>node[20];
int cnt[20];
bool hash[20];
int mini;
int n;
bool judge()
{
	bool flag = false;
	for(int i = 1; i <= n; i ++)
	{
		if(hash[i])continue;
		if(cnt[i] == 2)
		{
			if(!flag)
			{
				flag = true;
			}
			else
			{ 
				return false;
			}
		}
		else if(!(cnt[i] == 1 || cnt[i] == 3))
		{
			return false;
		}
	}
	return true;
}
bool gao(int step,int ss)
{
	if(step > n)
	{
		return false;
	}
	for(int i = step - 1; i < n; i ++)
	{
		if(!hash[i])
		{
			hash[i] = true;
			for (int j = 0; j <node[i + 1].size(); j ++)
			{
				cnt[node[i + 1][j]] --;
			}
			if(judge() && cnt[i + 1] <= 1)
			{
				mini = min(mini, ss);
			}
			if(gao(i + 1, ss + 1))return true;
			hash[i] = false;
			for (int j = 0; j <node[i + 1].size(); j ++)
			{
				cnt[node[i + 1][j]] ++;
			}
		}
	}
}
int main() 
{
	#ifdef WRITE
	freopen("B--small-attempt5.in","r",stdin);
	freopen("result","w",stdout);
	#endif
	int _;
	cin>>_;
	while(_--)
	{
		cin>>n;
		mini = 10000;
		memset(cnt, 0, sizeof(cnt));
		memset(hash, false, sizeof(hash));
		for(int i = 1; i <= n; i ++)
			node[i].clear();
		for(int i = 0; i < n - 1; i ++)
		{
			int x,y;
			cin>>x>>y;
			node[x].push_back(y);
			node[y].push_back(x);
			cnt[x] ++;
			cnt[y] ++;
		}
		if(judge())
		{
			mini = 0;
			output();
			cout<<mini<<endl;
			continue;	
		}
		gao(1, 1);
		output();
		cout<<mini<<endl;
		
	}
}