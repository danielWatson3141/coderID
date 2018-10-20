#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f

int first[MAXN], next[MAXN], v[MAXN];
bool vis[MAXN];
int edgeidx;
int n;
int cur;

void addedge(int a, int b)
{
	v[edgeidx] = b;
	next[edgeidx] = first[a];
	first[a] = edgeidx++;
}

void dfs(int cur, int &all, int &binary)
{
	vis[cur] = true;
	all = 1;
	binary = 0;
	
	vector<int> a, b;
	for(int i = first[cur]; i != -1; i = next[i])
	{
		if(!vis[v[i]])
		{
			int allnodes = 0, makebinary = 0;
			dfs(v[i], allnodes, makebinary);
			a.push_back(allnodes);
			b.push_back(makebinary);
		}
	}
	
	for(int i = 0; i < a.size(); ++i)
		all += a[i];
	
	if(a.size() == 0)
		return;
	else if(a.size() == 1)
	{
		binary = a[0];
	}
	else if(a.size() == 2)
	{
		binary = b[0] + b[1];
	}
	else
	{
		binary = 0x3f3f3f3f;
		for(int i = 0; i < a.size(); ++i)
			for(int j = i+1; j < a.size(); ++j)
			{
				int cur = b[i] + b[j] + all - 1 - a[i] - a[j];
				binary = min(binary, cur);
			}
	}
	
	return;
}

int main()
{
	freopen("d:\\2.in", "r", stdin);
	freopen("d:\\2.txt", "w", stdout);
	
	int T;
	cin>>T;
	for(int kase = 1; kase <= T; ++kase)
	{
		
		edgeidx = 0;
		memset(first, -1, sizeof(first));
		
		cin>>n;
		for(int i = 1; i < n; ++i)
		{
			int a, b;
			cin>>a>>b;
			addedge(a, b);
			addedge(b, a);
		}
		
		int ans = INF;
		for(int i = 1; i <= n; ++i)
		{
			memset(vis, false, sizeof(vis));
			int allnodes = 0, makebinary = 0;
			dfs(i, allnodes, makebinary);
		//	cout<<i<<" "<<makebinary<<endl;
			
			ans = min(ans, makebinary);
		}
		
		cout<<"Case #"<<kase<<": "<<ans<<endl;
	}
	return 0;
}
