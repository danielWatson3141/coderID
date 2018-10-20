// TwT514 {{{
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset(x,0,(n)*sizeof(*x))
#define MS1(x,n) memset(x,-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}
#define N 1010
int n;
VI e[N];

void input(){
	RI(n);
	REP(i,n) e[i].clear();
	REP(i,n-1){
		int x,y;
		RII(x,y);
		e[x-1].PB(y-1);
		e[y-1].PB(x-1);
	}
}

int dfs(int x, int pre){
	int mx = -1, mx2 = -1;	
	REP(i, SZ(e[x])){	
		int b = e[x][i];
		if(b==pre) continue;
		int res = dfs(b,x);
		if(mx>res && res>mx2) mx2 = res;
		else if(res>=mx){mx2 = mx; mx = res;}
	}
	if(mx2==-1) return 1;
	else return mx+mx2+1;
}

int solve(int root){
	return dfs(root, -1);
}

void solve(){
	int ans = -1;
	REP(i,n){
		ans = max(ans, solve(i));
		//cout << solve(i) << endl;
	}	
	static int zi = 0;
	printf("Case #%d: %d\n", ++zi, n-ans);
	
}

int main() {
	int zn;
	RI(zn);
	while(zn--){
		input();
		solve();
	}
    return 0;
}

