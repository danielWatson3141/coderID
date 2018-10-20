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

void bucket_sort(vi& a)
{
	int mn=*min_element(all(a)),mx=*max_element(all(a));
	vi b(mx-mn+1);
	rep(i,a.size()) b[a[i]-mn]++;
	rep(i,b.size()-1) b[i+1]+=b[i];
	vi t=a;
	per(i,a.size()) a[--b[t[i]-mn]]=t[i];
}

int dfs(const vvi& g,int u,int p)
{
	vi a;
	for(int v:g[u]) if(v!=p)
		a.push_back(dfs(g,v,u));
	int sum=1;
	if(a.size()>=2){
		bucket_sort(a);
		sum+=a[a.size()-1]+a[a.size()-2];
	}
	return sum;
}

void solve()
{
	int n; cin>>n;
	vvi g(n);
	rep(i,n-1){
		int u,v; cin>>u>>v; u--,v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int mx=0;
	rep(i,n) mx=max(mx,dfs(g,i,-1));
	cout<<n-mx<<endl;
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
