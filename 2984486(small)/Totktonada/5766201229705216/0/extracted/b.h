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
	freopen("B-small-attempt3.in","r",stdin);
	freopen("B-small-attempt3.out","w",stdout);
	int T; cin >>T;
	FOR(tt,1,T+1) {
		int ans=100000000, n; cin >>n;
		if (n<4) {printf("Case #%d: 0\n",tt); continue;}
		VI d(n,0); VII a(n,d);
		FOR(t,0,n-1) {
			int x, y; scanf("%d%d",&x,&y);
			--x, --y; a[x][y]=a[y][x]=1;
		}
		int mx=(1<<n);
		FOR(mask,0,mx-1) {
			int x=mask, k=0; VI v;
			while (x) {
				if (x&1) v.pb(k);
				x>>=1, ++k;
			}
			VII b=a; set<int> ss;
			FOR(i,0,v.sz) {
				int x=v[i]; ss.insert(x);
				FOR(j,0,n) b[x][j]=b[j][x]=0;
			}
			k=0;
			FOR(i,0,n) FOR(j,0,n) k+=b[i][j];
			if (k/2+1!=n-v.sz) continue;
			VI c(n,0);
			FOR(i,0,n) FOR(j,0,n) c[i]+=b[i][j];
			sort(all(c));
			if (c[n-1]>3) continue;
			k=0;
			FOR(t,0,n) k+=(c[t]==2);
			if (k!=1) continue;
			FOR(t,0,n) if (!c[t] && ss.find(t)==ss.end()) continue;
			ans=min(ans,(int)v.sz);
		}
		printf("Case #%d: %d\n",tt,ans);
	}
return 0;
}







