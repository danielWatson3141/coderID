#include <bits/stdc++.h>
using namespace std;
#define TR(i,v) 		for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x) 		cout << #x << " = "; cout << x << endl;
#define SIZE(p) 		(int)(p).size()
#define MP(a, b)		make_pair((a), (b))
#define ALL(p)			(p).begin(), (p).end()
#define rep(i, n)		for(int (i)=0; (i)<(int)(n); ++(i))
#define REP(i, a, n)	for(int (i)=(a); (i)<(int)(n); ++(i))
#define FOR(i, a, b)   	for(int (i)=(int)(a); (i)<=(int)(b); ++(i))
#define FORD(i, b, a)  	for(int (i)=(int)(b); (i)>=(int)(a); --(i)) 
typedef long long LL;
typedef pair<int, int> pii;
const int maxn = 1015;
vector<int> g[maxn], G[maxn];
int n, size[maxn], deg[maxn], RES;
void dfs(int u, int fa)
{
	++size[u];
	rep(i, SIZE(G[u]))	if(G[u][i]!=fa) {
		dfs(G[u][i], u);		
		size[u] += size[G[u][i]];
	}
	deg[u]=SIZE(G[u])-1;
}
int build(int root)
{
	FOR(i, 1, n)	size[i]=deg[i]=0;
	G[root].push_back(-1);
	dfs(root, -1);	
	G[root].pop_back();	
	return 1;
}
bool cmp(int x, int y) {
	return size[x] > size[y];
}
void dfs1(int u, int fa)
{
	if(deg[u]==0)		return;
	if(deg[u]==2) {
		for(auto v: G[u])	if(v != fa)
			dfs1(v, u);
		return;
	}
	if(deg[u]==1) {
		for(auto v:G[u])	if(v != fa) {
			RES += size[v];		break;
		}
	}else{
		sort(ALL(G[u]), cmp);
		int cnt=0;
		for(auto v:G[u])	if(v != fa) {			
			if(++cnt<=2)
				dfs1(v, u);
			else
				RES += size[v];
		}
	}
}
int gao(int root)
{
	RES=0;
	dfs1(root, -1);
	return RES;
}
int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);	
    freopen("out", "w", stdout);
    #endif
	// ios::sync_with_stdio(false);    cin.tie(0);
	int T;		scanf("%d", &T);
	FOR(cs, 1, T) {
		printf("Case #%d: ", cs);
		scanf("%d", &n);
		FOR(i, 1, n)	G[i].clear();
		rep(i, n-1) {
			int u, v;	scanf("%d%d", &u, &v);
			G[u].push_back(v), G[v].push_back(u);
		}
		int res=-1, resi;
		FOR(root, 1, n) {
			int rr = build(root);
			if(rr == -1)		continue;
			int c = gao(root);
			if(res==-1 || res>c)	res=c, resi=root;
		}
		printf("%d\n", res);
		// DEBUG(resi);
	}
	return 0;
}