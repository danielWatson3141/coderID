#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int nxt,x;
};

int tt;
int n,m;
edge e[2010];
int g[1010];
bool used[1010];

void makeedge(int st,int ed) {
	m++;
	e[m].nxt=g[st]; e[m].x=ed; g[st]=m;
}

int dfs(int x) {
	used[x]=true;
	vector<int> f;
	f.clear();
	for (int i=g[x];i!=0;i=e[i].nxt)
		if (!used[e[i].x]) {
			int p=dfs(e[i].x);
			f.push_back(p);
		}
	sort(f.begin(),f.end(),greater<int>());
	if (f.size()>=2) return f[0]+f[1]+1;
	return 1;
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d",&n);

		memset(g,0,sizeof(g));
		m=0;

		for (int i=0;i<n-1;++i) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			makeedge(x,y); makeedge(y,x);
		}
		int res=1000000;
		for (int i=0;i<n;++i) {
			memset(used,false,sizeof(used));
			int p=dfs(i);
			if (n-p<res) res=n-p;
		}
		printf("Case #%d: %d\n",ii,res);
	}
}


