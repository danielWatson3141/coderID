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
typedef pair<string,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int n, l;
string s[155];
string t[155];
int ans, cnt;

void dfs(int d){
	//printf("%d %d\n",d,cnt);
	//rep(i,n) cout << s[i] << " "; cout << endl;
	//rep(i,n) cout << t[i] << " "; cout << endl;
	if(d == l){ mins(ans,cnt); return;}
	map<string,int> tm0, tm1, sm0, sm1;
	rep(i,n) if(t[i][d] == '0') tm0[t[i].substr(0,d)]++;
	rep(i,n) if(t[i][d] == '1') tm1[t[i].substr(0,d)]++;
	rep(i,n) if(s[i][d] == '0') sm0[s[i].substr(0,d)]++;
	rep(i,n) if(s[i][d] == '1') sm1[s[i].substr(0,d)]++;
	bool ok = true;
	for(P p : tm0){
		if(!ok) break;
		auto jt = sm0.find(p.fi);
		if(jt == sm0.end() || jt->se != p.se) ok = false;
	}
	for(P p : tm1){
		if(!ok) break;
		auto jt = sm1.find(p.fi);
		if(jt == sm1.end() || jt->se != p.se) ok = false;
	}
	if(ok) dfs(d+1);
	ok = true;
	for(P p : tm1){
		if(!ok) break;
		auto jt = sm0.find(p.fi);
		if(jt == sm0.end() || jt->se != p.se) ok = false;
	}
	for(P p : tm0){
		if(!ok) break;
		auto jt = sm1.find(p.fi);
		if(jt == sm1.end() || jt->se != p.se) ok = false;
	}
	if(ok){
		cnt++;
		rep(i,n) s[i][d] = (s[i][d]-'0'^1)+'0';
		dfs(d+1);
		rep(i,n) s[i][d] = (s[i][d]-'0'^1)+'0';
		cnt--;
	}
}

int main(){
	int ts;
	cin >> ts;
	rrep(ti,ts){
		cin >> n >> l;
		rep(i,n) cin >> s[i];
		rep(i,n) cin >> t[i];
		sort(s, s+n);
		sort(t, t+n);
		ans = 1<<30; cnt = 0;
		dfs(0);
		printf("Case #%d: ",ti);
		if(ans == (1<<30)) puts("NOT POSSIBLE");
		else printf("%d\n",ans);
	}
	
	return 0;
}





