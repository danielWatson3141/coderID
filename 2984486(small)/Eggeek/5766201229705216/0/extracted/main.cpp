#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 20
vector<int>e[maxn];
bool isd[maxn];
int n,root,vis[maxn];

int dfs(int cur,int pa) {
	vis[cur] = 1;
	int son=0, res=1;
	for (int i=0 ; i<(int)e[cur].size() ; i++ ) {
		if (e[cur][i]!=pa && !isd[e[cur][i]]) {
			son++;
			res = dfs(e[cur][i],cur);
			if (!res) return 0;
		}
	}
	if (son!=0 && son!=2) return 0;
	return 1;
}

int cntb(int msk) {
	int res=0;
	while (msk) {
		if (msk&1) res++;
		msk>>=1;
	}
	return res;
}



int check(int msk) {
	memset(isd, 0, sizeof(isd));
	for (int i=0 ; i<n ; i++ ) if ((msk>>i)&1) isd[i+1]=1;

	for ( root=1; root<=n ; root++ ) {
		memset(vis,0,sizeof(vis));
		if (dfs(root,-1)) {
			int flg = 1;
			for (int i=1 ; i<=n ; i++ ) {
				if (!isd[i] && !vis[i]) {
					flg=0;
					continue;
				}
			}
			if (flg) return cntb(msk);
		}
	}
	return -1;
}

void work() {
	scanf("%d",&n);
	for (int i=0 ; i<=n ; i++ ) if (e[i].size()) e[i].clear();
	for (int i=0 ; i<n-1 ; i++ ) {
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int ans = n;
	for (int i=0 ; i<(1<<n) ; i++ ) {
		int tmp = check(i);
		if (tmp != -1) ans = min(ans,tmp);
	}
	printf("%d\n", ans);
}

int main() {
	int cas;
	freopen("test.txt", "r", stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&cas);
	for (int t=1 ; t<=cas ; t++ ) {
		printf("Case #%d: ",t);
		work();
	}
	return 0;
}
