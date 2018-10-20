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
#include <ctime>
#include <fstream>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
int n,ans,A[15][15],node_used[15],degree[15];
bool is_bin()
{
	vector <int> counter(n,0);
	vector <bool> visited(n,false);
	int curr_root=-1;
	for (int i = 0; i < n; ++i)
	{
		if(node_used[i]==1 && degree[i]==2)
		{
			curr_root=i;
			break;
		}
	}
	if(curr_root==-1)
		return false;
	stack <int> dfs;
	dfs.push(curr_root);
	visited[curr_root]=true;
	while(!dfs.empty())
	{
		int top=dfs.top();
		dfs.pop();
		for (int i = 0; i < n; ++i)
		{
			if(A[top][i]==1 && !visited[i] && node_used[i]==1)
			{
				visited[i]=true;
				dfs.push(i);
				counter[top]++;
			}
		}
	}
	int tempc=0;
	for (int i = 0; i < n; ++i)
	{
		if(node_used[i]==1 && !visited[i])
			return false;
		if(counter[i]!=0 && counter[i]!=2)
			return false;
	}
	return true;
}
void recursor(int depth,int used)
{
	if(depth==n)
	{
		if(is_bin())
		{
			ans=min(ans,used);
		}
		return;
	}
	node_used[depth]=1;
	recursor(depth+1,used);
	for (int i = 0; i < n; ++i)
	{
		if(A[i][depth]==1)
		{
			degree[depth]--;
			degree[i]--;
		}
	}
	node_used[depth]=0;
	recursor(depth+1,used+1);
	for (int i = 0; i < n; ++i)
	{
		if(A[i][depth]==1)
		{
			degree[depth]++;
			degree[i]++;
		}
	}
}
int main()
{
	freopen("bs.in","r",stdin);
	freopen("b_temp.out","w",stdout);
	int t,x,y;
	scanf("%d",&t);
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		scanf("%d",&n);
		for (int i = 0; i < 15; ++i)
		{
			degree[i]=0;
			for (int j = 0; j < 15; ++j)
			{
				A[i][j]=0;
			}
		}
		for (int i = 0; i < n-1; ++i)
		{
			scanf("%d %d",&x,&y);
			A[x-1][y-1]=1;
			A[y-1][x-1]=1;
			degree[x-1]++;
			degree[y-1]++;
		}
		ans=100;
		recursor(0,0);
		printf("Case #%d: %d\n", test_case,ans);
	}
	return 0;
}