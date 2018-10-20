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
#define N 3
#define NN 100000


int p[130][1010], n, m;
void input(){
	RI(m);
	REP(i,m){
		RI(n);
		REP(j,n) RI(p[i][j]);
	}
}
bool cmp(int x, int y){
	REP(i,n){
		if(p[x][i]==p[y][i])continue;
		return p[x][i]<p[y][i];
	}
}
int t[130], ans[130];
void solve(){
	REP(i, m) t[i] = i;
	sort(t, t+m, cmp);
	for(int i=0; i<m; i++) ans[t[i]] = i<m/2?1:0;
	REP(i, m){
		printf("Case #%d: %s\n", i+1, ans[i]?"GOOD":"BAD");
	}
}

int main() {
	input();
	solve();
	return 0;
}

