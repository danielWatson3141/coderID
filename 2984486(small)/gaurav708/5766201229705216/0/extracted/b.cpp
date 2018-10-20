#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define forup(i,a,b) for(int i=(a);i<(b);i++)
#define fordn(i,a,b) for(int i=(a);i>(b);i--)
#define all(x) x.begin(),x.end()
#define permute(x) next_permutation(all(x))
#define gi(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int inv=int(1e9);
const int max_n=1010;
int T;
int n,u,v;
vi adjl[max_n];

pii dfs(int s, int par) {
	vector<pii> child;
	rep(i,(int)adjl[s].size()) {
		if(adjl[s][i]==par) continue;
		child.pb(dfs(adjl[s][i],s));
	}
	int cc=(int)child.size();
	//printf("%d %d %d\n",s,par,cc);
	if(cc==0) return pii(0,1);
	else if(cc==1) return pii(child[0].sc,1+child[0].sc);
	else if(cc==2) return pii(child[0].fs+child[1].fs,1+child[0].sc+child[1].sc);
	else {
		int scnt=0;
		rep(i,cc) scnt+=child[i].sc;
		vi tmp;
		rep(i,cc) tmp.pb(child[i].fs-child[i].sc);
		sort(all(tmp));
		return pii(scnt+tmp[0]+tmp[1],1+scnt);
	}
}

int main() {
	gi(T);
	for(int z=1;z<=T;z++) {
		fprintf(stderr, "Solving Case #%d...\n", z);
		gi(n);
		rep(i,n) adjl[i].clear();
		rep(i,n-1) {
			gi(u); gi(v);
			--u; --v;
			adjl[u].pb(v);
			adjl[v].pb(u);
		}
		int ans=inv;
		rep(i,n)
			ans=min(ans,dfs(i,-1).fs);
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}
