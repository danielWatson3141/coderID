#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <assert.h>
#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sz(x) (int)x.size()
#define inf (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define pii pair<int,int>
#define pll pair<i64,i64>
#define pmp make_pair
#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
#define uu first
#define vv second
using namespace std;
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef  long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
b.end(), *q ) ) q++;}return oot;
}

//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<(pos)))
#define off(n,pos)  n & ~(1<<pos)
#define ison(n,pos) (bool)(n & (1<<(pos)))
string toBin(int n){ string s; repv(i,32)s+=(ison(n,i)+'0');return s;}
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case #%d: ",++ks);

using namespace std;

vector<int>g[20];
int cnt[20];
int vis[22];
int mask,flag;
void call(int par,int u)
{
	int child=0;
	vis[u]=1;
	
	rep(i,sz(g[u]))
	{
		int v=g[u][i];
		if(v==par)continue;
		if(vis[v]) continue;
		if(ison(mask,(v-1)))continue;
		call(u,v);
		child++;
		
	}
	cnt[u]=child;
	//cout<<u<<">>>>"<<child<<endl;
	if(cnt[u]!=0 and cnt[u]!=2) flag=0;
	
	
}
int n;
int solve(int root)
{
		flag=1;
		mem(vis,0);
		mem(cnt,0);
		
		call(-1,root);
		repl(i,n)
		{
			if(!flag) break;
			if(vis[i]==0 and ison(mask,(i-1))==false) 
			{
				flag=0;
			}
		}
		if(!flag) return 1<<28;
		return __builtin_popcount(mask);
		
}
int main() {
	READ("in");
	WRITE("Boutsmall22222");
	///WRITE("Boutsmall1");
	int t,ks=0;
	cin>>t;
	while(t--)
	{
		rep(i,n+1)g[i].clear();
		cin>>n;
		rep(i,n-1)
		{
			int u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		
		int ans=1<<28;
		rep(i,1<<n)//if(i==0)
		{
			//cout<<i<<endl;
			mask=i;
			repl(root,n)//if(root==1)
			{
				int ret=solve(root);
				//cout<<i<<" "<<ret<<endl;
				ans=min(ans,ret);
			}
		}
		pks;
		cout<<ans<<endl;
	}
	return 0;
}
