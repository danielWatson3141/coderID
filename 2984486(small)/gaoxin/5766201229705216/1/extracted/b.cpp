#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl
#define sqr(x) ((x)*(x))

int tests,n,ans;

vector<int> son[1010];
int v[1010],sz[1010];

void dfs(int now)
{
	//printf("dfs %d\n",now);
	v[now] = 100000;
	sz[now] = 1;
	vector<int> f;
	for (int i=0;i<son[now].size();i++) if (v[son[now][i]]==-1)
	{
		dfs(son[now][i]);
		f.push_back(v[son[now][i]]-sz[son[now][i]]);
		sz[now] += sz[son[now][i]];
	}
	if (f.size()==0)
		v[now] = 0;
	else if (f.size()==1)
		v[now] = sz[now]-1;
	else {
		sort(f.begin(),f.end());
		v[now] = sz[now] - 1 + f[0] + f[1];
	}
}

int main()
{
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);

	scanf("%d",&tests);
	for (int test=1;test<=tests;test++)
	{
		scanf("%d",&n);
		
		for (int i=1;i<=n;i++) son[i].clear();
		for (int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			son[x].push_back(y);
			son[y].push_back(x);
		}
		
		ans = n;
		
		for (int root=1;root<=n;root++)
		{
			for (int i=1;i<=n;i++) v[i] = -1;
			dfs(root);
			//printf("root = %d   v = %d\n",root, v[root]);
			//for (int i=1;i<=n;i++) printf("%d ",v[i]); printf("\n");
			//for (int i=1;i<=n;i++) printf("%d ",sz[i]); printf("\n");
			ans = min(ans, v[root]);
		}
		
		printf("Case #%d: %d\n", test, ans);
	}
	
	return 0;
}
