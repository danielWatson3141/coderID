#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI adj;

int vis[1010];
int mem[1010];
int dfsSZ(int u)
{
	vis[u] = 1;
	int ret = 1;
	vector<int> V;
	for(int i = 0; i < adj[u].size(); ++i)
	{
		int v = adj[u][i];
		if(vis[v]) continue;
		V.push_back(dfsSZ(v));
	}
	sort(V.rbegin(),V.rend());
	if(V.size() >= 2)
	{
		ret += V[0] + V[1];
	}
	return ret;
}

int main() 
{
	freopen("out.txt","w",stdout);
	freopen("B-large.in","r",stdin);
	int TC;
	cin >> TC;
	for(int tc = 1; tc<=TC ; ++tc)
	{
		int N;
		cin >> N;
		adj = VVI(N);
		for(int i = 0; i < N-1; ++i)
		{
			int u,v;cin>>u>>v;u--;v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int mi = N;
		for(int i = 0; i < N; ++i)
		{
			memset(vis,0,sizeof(vis));
			int t = dfsSZ(i);
			mi = min( N - t , mi );
		}
		cout << "Case #" << tc << ": " << mi << endl;
	}
}





/*
15
1 15
2 5
2 14
2 15
3 9
3 15
4 11
4 14
6 10
6 12
6 15
7 8
8 12
10 13


1 - 15

 */

