#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()
#define CLR(X) memset((X),0,sizeof(X))

#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////
int T,n,l;
string a;
//bitset s1[155],s2[155];
vector< bitset<10> > v1,v2;
vector<ll> f,e;
int ans;
ll change(bitset<10> &b){
	ll tmp=1,ret=0;
	rep(i,l) {
		if(b[i]) ret+=tmp;
		tmp<<=1;
	}
	return ret;
}
int geshu(ll t){
	int ret=0;
	while(t) { if(t&1) ret++; t>>=1;}
	return ret;
}
bool ok(){
	rep(i,n) if(f[i]!=e[i]) return false;
	return true;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>T;
	fer(t,1,T+1){
		cin>>n>>l;
		v1.clear();v2.clear();
		rep(i,n) cin>>a,v1.pb(bitset<10> (a));
		rep(i,n) cin>>a,v2.pb(bitset<10> (a));
		e.clear();
		rep(i,n) e.pb( change(v2[i]) ); sort(e.begin(),e.end());
		//rep(i,n) cout<<v2[i]<<endl;
		ans = 1000;

		rep(k,(1<<l)){
			int tmp=k,tl=0; while(tmp) {  if(tmp&1) rep(j,n) v1[j][tl]=v1[j][tl]^1;  tmp>>=1,tl++;  }
			f.clear();
			rep(i,n) f.pb( change(v1[i]) ); sort(f.begin(),f.end()); if(ok()) smin(ans,geshu(k));
			tmp=k,tl=0; while(tmp) {  if(tmp&1) rep(j,n) v1[j][tl]=v1[j][tl]^1;  tmp>>=1,tl++;  }		
		}
		if(ans!=1000) {cout<<"Case #"<<t<<": "<<ans<<endl;	continue;}
		else cout<<"Case #"<<t<<": NOT POSSIBLE\n";		
	}
	return 0;
}