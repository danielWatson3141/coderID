#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <complex>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define foreach(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define all(c) begin(c),end(c)
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int INFTY=1<<29;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

ll toll(string s)
{
	ll res=0;
	rep(i,s.size())
		res|=s[i]-'0'<<i;
	return res;
}

void solve()
{
	int n,l; cin>>n>>l;
	vl a(n),b(n);
	{
		string s;
		rep(i,n){cin>>s; a[i]=toll(s);}
		rep(i,n){cin>>s; b[i]=toll(s);}
	}
	sort(all(b));
	
	int res=INFTY;
	rep(i,n) rep(j,n){
		ll x=a[i]^b[j];
		vl t(n);
		rep(k,n) t[k]=a[k]^x;
		sort(all(t));
		if(t==b)
			res=min(res,__builtin_popcountll(x));
	}
	
	if(res==INFTY)
		cout<<"NOT POSSIBLE"<<endl;
	else
		cout<<res<<endl;
}

int main()
{
	int T; scanf("%d",&T);
	rep(i,T){
		printf("Case #%d: ",i+1);
		solve();
	}
	
	return 0;
}
