#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
#include<queue>
#include<sstream>
#include<ctime>
using namespace std;

typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())
const int inf = 1000000000;
const int MOD = 1000000007;
const double pi = acos(-1.0);

int a[1111][1111];
bool used[1111];
string ans[1111];
int f[1111];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;cin>>t;
	FOR(i,1,t) {
		int n;cin>>n;
		FOR(j,1,n) cin>>a[i][j];
		int mx=0;
		FOR(j,1,n) if(a[i][j]==j) ++mx;
		f[i]=mx;
	}
	vector<pair<int,int> >g;
	FOR(i,1,t) g.pb(mp(f[i], i));
	sort(g.begin(), g.end());
	FOR(i,1,t) ans[i]="GOOD";
	FOR(i,0,t/2-1) ans[g[i].second]="BAD";
	FOR(i,1,t) cout<<"Case #"<<i<<": "<<ans[i]<<endl;
}
