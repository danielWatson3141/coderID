#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <list>
#include <queue>
using namespace std;

#define LL long long
#define V vector
#define VD V<double>
#define VI V<int>
#define VII V<VI>
#define FOR(t,l,r) for (int t=l; t<(int)r; t++)
#define FORL(t,l,r) for (LL t=l; t<(LL)r; t++)
#define max(x,y) ((x>y)?x:y)
#define min(x,y) ((x<y)?x:y)
#define abs(x) (((x)<0)?-(x):(x))
const double mth_pi=2*acos(0.);
#define pi mth_pi
#define inf (1<<23)
#define eps 1e-10
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a) a.begin(),a.end()
#define mii map<int,int>
#define pii pair<int,int>
#define x first
#define y second

int main () {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T; cin >>T;
	FOR(tt,1,T+1) {
		int n, l; cin >>n>>l;
		V<string> out(n), dev(n);
		FOR(t,0,n) cin >>out[t];
		FOR(t,0,n) cin >>dev[t];
		sort(all(out)), sort(all(dev));
		int mx=(1<<l), f=0;
		FOR(mask,0,mx) {
			int x=mask;
			VI a; int t=0;
			while (x) {
				if (x&1) a.pb(t);
				x>>=1, ++t;
			}
			V<string> s=out;
			FOR(t,0,a.sz) {
				int j=a[t];
				FOR(i,0,n)
					s[i][j]=((s[i][j]=='1')?'0':'1');
			}
			sort(all(s));
			if (s==dev) {
				cout <<"Case #"<<tt<<": "<<a.sz<<endl;
				f=1;
			}
			if (f) break;
		}
		if (!f) cout <<"Case #"<<tt<<": NOT POSSIBLE\n";
	}
return 0;
}








