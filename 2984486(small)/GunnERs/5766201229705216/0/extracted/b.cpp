#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1001;

int task, CASE=0, n, ret;
int g[maxn][maxn], sum[maxn], full[maxn];
bool vis[maxn];

void dfs( int x ){
	vis[x] = true;
	sum[x] = 0;
	int a=-1, b=-1;
	for (int i=1; i<=g[x][0]; i++){
		int y = g[x][i];
		if ( !vis[y] ){
			dfs( y );
			sum[x] += sum[y];
			b = max( b, sum[y]-full[y] );
			if ( b>a ) swap( a, b );
		}
	}
	//cout<<x<<' '<<sum[x]<<' '<<a<<' '<<b<<endl;
	if ( a==-1 || b==-1 ){
		full[x] = sum[x];
	}else{
		full[x] = sum[x]-a-b;
	}
	sum[x]++;
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &task); task--;){
		scanf("%d", &n);
		memset(g, 0, sizeof(g));
		for (int i=0; i<n-1; i++){
			int x, y;
			scanf("%d%d", &x, &y);
			g[x][++g[x][0]] = y;
			g[y][++g[y][0]] = x;
		}
		ret = n-1;
		for (int root = 1; root<=n; root++){
			memset( vis, 0, sizeof(vis) );
			memset( sum, 0, sizeof(sum) );
			memset( full, 0, sizeof(full) );
			dfs( root );
			//cout<<root<<' '<<full[root]<<endl;
			ret = min( ret, full[root] );
		}
		printf("Case #%d: %d\n", ++CASE, ret);
	}
	return 0;
}
