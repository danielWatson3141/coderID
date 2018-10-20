#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int f[1010][2];
vector<int> g[1010], ch[1010];
int use[1010];
int num[1010];
int n;
int T;

void dfs( int x ){
	use[x]=1;
	num[x]=1;
	ch[x].clear();
	for (int i=0; i<g[x].size(); ++i)
		if (! use[g[x][i]]){
			dfs(g[x][i]); num[x]+=num[g[x][i]];
			ch[x].push_back(g[x][i]);
		}
	f[x][0]=num[x];
	if (ch[x].size()==0)
		f[x][1]=0;
	else
		if (ch[x].size()==1)
			f[x][1]=f[ch[x][0]][0];
		else {
			int tot=f[ch[x][0]][0];
			int m1=ch[x][0], m2=-1;
			for (int i=1; i<ch[x].size(); ++i){
				int tt=f[ch[x][i]][1]-f[ch[x][i]][0];
				if (tt<f[m1][1]-f[m1][0]){
					m2=m1; m1=ch[x][i];
				} else
					if (tt<f[m2][1]-f[m2][0] || m2==-1) m2=ch[x][i];
				tot+=f[ch[x][i]][0];
			}
			f[x][1]=tot+f[m1][1]+f[m2][1]-f[m1][0]-f[m2][0];
			//if (f[x][1]<0)
				//printf("%d %d %d %d %d %d %d %d %d\n", tot,f[m1][1],f[m2][1],f[m1][0],f[m2][0], m1, m2, ch[x][0], ch[x][1]);
		}
}

int calc( int root ){
	memset(use,0,sizeof(use));
	memset(f,0,sizeof(f));
	dfs(root);
	//printf("%d %d\n", root, f[root][1]);
	return f[root][1];
}

int main(){
	int test=0;
	scanf("%d", &test);
	for (T=1; T<=test; ++T){
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			g[i].clear();
		for (int i=0; i<n-1; ++i){
			int x,y;
			scanf("%d %d", &x, &y);
			--x; --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans=-1;
		for (int i=0; i<n; ++i){
			int ret=calc(i);
			if (ans==-1 || ret<ans) ans=ret;
		}
		printf("Case #%d: %d\n", T, ans);
	}
}
