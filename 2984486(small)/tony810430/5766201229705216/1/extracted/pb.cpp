#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<map>
#include<string>
#include<set>

#define lson L,M,now<<1
#define rson M+1,R,now<<1|1
using namespace std;


int T;
int N;
vector<int> adj[1004];

int cut[1004];
int chi[1004];

void dfs(int v,int p)
{
	int cnt = 0;
	for( int i = 0; i < int(adj[v].size()); i++ ){
		int nxt = adj[v][i];
		if( nxt != p ){
			cnt++;
			dfs(nxt,v);
			chi[v] += chi[nxt];
			cut[v] += cut[nxt];
		}
	}
	chi[v]++;

	if( cnt == 1 ){
		cut[v] = chi[v]-1;
	}else if( cnt > 2 ){
		cut[v] = chi[v]-1;
		int res = -1;
		for( int i = 0; i < int(adj[v].size()); i++ ){
			int a = adj[v][i];
			if( a == p )continue;
			for( int j = i+1; j < int(adj[v].size()); j++ ){
				int b = adj[v][j];
				if( b == p )continue;
				if( res == -1 || res > cut[v]+(cut[a]-chi[a])+(cut[b]-chi[b]) )
					res = cut[v]+(cut[a]-chi[a])+(cut[b]-chi[b]);
			}
		}
		cut[v] = res;
	}
}

int main()
{
	int a,b;
	scanf(" %d",&T);

	for( int cas = 1; cas <= T; cas++ ){
		scanf(" %d",&N);
		for( int i = 1; i <= N; i++ )
			adj[i].clear();
		for( int i = 0; i < N-1; i++ ){
			scanf(" %d %d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int ans = -1;
		for( int i = 1; i <= N; i++ ){
			memset(cut,0,sizeof(cut));
			memset(chi,0,sizeof(chi));
			dfs(i,-1);
			//printf("%d\n",cut[i]);
			if( ans == -1 || ans > cut[i] )
				ans = cut[i];
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	

	return 0;
}