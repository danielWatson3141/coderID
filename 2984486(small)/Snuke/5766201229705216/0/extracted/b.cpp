#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<complex>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 1005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int n;
vi to[MX];

int dfs(int v, int p=-1){
	vi d;
	for(int u : to[v]){
		if(u == p) continue;
		d.pb(dfs(u,v));
	}
	sort(rng(d)); reverse(rng(d));
	if(sz(d) < 2) return 1;
	return d[0]+d[1]+1;
}

int main(){
	int ts;
	cin >> ts;
	rrep(ti,ts){
		cin >> n;
		int a, b;
		rep(i,n) to[i].clear();
		rep(i,n-1){
			cin >> a >> b; a--; b--;
			to[a].pb(b);
			to[b].pb(a);
		}
		int ans = 0;
		rep(i,n) maxs(ans,dfs(i));
		printf("Case #%d: %d\n",ti,n-ans);
	}
	
	return 0;
}





