#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) cout<<"Case #"<<++__<<": "<<x<<endl 
#define POP(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int _,__,n,l,ans;
char p1[160][50],p2[160][50];
string P1[160],P2[160];
bool flip[50];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&l);
		rep(i,0,n) scanf("%s",p1[i]);
		rep(i,0,n) scanf("%s",p2[i]);
		ans=l+1;
		rep(i,0,n) {
			rep(j,0,l) flip[j]=(p1[0][j]!=p2[i][j]);
			rep(i,0,n) {
				P1[i]=p1[i];
				P2[i]=p2[i];
				rep(j,0,l) if (flip[j]) P2[i][j]^=1;
			}
			sort(P1,P1+n);
			sort(P2,P2+n);
			bool fg=0;
			rep(i,0,n) if (P1[i]!=P2[i]) { fg=1;break;}
			if (!fg) {
				ans=min(ans,ACCU(flip,flip+l,0));
			}
		}
		if (ans>=l+1) PRINTC("NOT POSSIBLE");
		else PRINTC(ans); 
	}
}
