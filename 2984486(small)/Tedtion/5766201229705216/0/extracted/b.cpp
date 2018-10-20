#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <vector>
using namespace std;
#define NN 1008
int adj[NN][NN];
int f[NN], v[NN]; // f, 最多节点个数 

void calf(int g)
{
	int i;
	vector<int> cf;
	v[g] = 1;
	for (i=1; i<=adj[g][0]; i++) if (v[adj[g][i]]==0) {
		int x = adj[g][i];
		calf(x);
		cf.push_back(f[x]);
	}
	if (cf.size()==2) f[g]=cf[0]+cf[1]+1;
	else if (cf.empty()) f[g]=1;
	else if (cf.size()==1) f[g]=1;
	else {
		sort(cf.begin(), cf.end());
		reverse(cf.begin(), cf.end());
		f[g]=cf[0]+cf[1]+1;
	}
}

int main()
{
	int T;
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	scanf("%d",&T);;
	for (int cas=1; cas<=T; cas++)
	{
		int n,x,y,i;
		scanf("%d",&n);
		for (i=1; i<=n; i++) adj[i][0]=0;
		for (i=1; i<n; i++) {
			scanf("%d%d",&x,&y);
			adj[x][0]++;
			adj[x][adj[x][0]] = y;
			adj[y][0]++;
			adj[y][adj[y][0]] = x;
		}
		int res = 1;
		for (i=1; i<=n; i++)
		{
	//		memset(f, 0, sizeof(f));
			memset(v, 0, sizeof(v));
			calf(i);
			if (f[i] > res) res = f[i];
		}
		printf("Case #%d: %d\n", cas, n - res);
	}
	return 0;
}

