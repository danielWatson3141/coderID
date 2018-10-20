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
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int d[1005];
ll a, b;
int n, cor;

inline int f(int i){ return n-i-1;}

int main(){
	int ts = 120; n = 1000;
	cin >> ts;
	rrep(ti,ts){
		cin >> n;
		rep(i,n) cin >> d[i];
		int x = 0;
		rep(i,n) x += max(0,d[i]-i)*max(0,d[i]-i);
		//printf("%d\n",x);
		//if(ti == 59) puts("");
		if(ti <= 60) b += x; else a += x;
		printf("Case #%d: ",ti);
		int vl = 79309529;
		if(x < vl) puts("Bad"); else puts("Good");
		if(x < vl && ti <= 60) cor++;
		if(x >= vl && ti > 60) cor++;
	}
	//cout << a << " " << b << endl;
	//cout << cor << endl;
	return 0;
}





