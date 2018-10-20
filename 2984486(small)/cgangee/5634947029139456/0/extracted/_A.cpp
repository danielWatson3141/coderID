#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>
 
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define L 40

int i,j,k,m,n,l;
vi a, b;
char s[L+10];

void read(vi &a){
	a.clear();
	rep(i, n){
		scanf("%s", s);
		int k=0;
		rep(i, m)
			k=(k<<1)+(s[i]=='1'?1:0);
		a.pb(k);
	}
}

bool equal(vi a, vi b){
	rep(i, sz(a)) if (a[i]!=b[i]) return false;
	return true;
}

int num(int k){
	int ret=0;
	rep(i, m) ret+=(k&(1<<i))?1:0;
	return ret;
}

int gao(){
	int ret=-1;
	sort(all(b));
	rep(i, 1<<m){
		vi c;
		rep(j, sz(a)) c.pb(a[j]^i);
		sort(all(c));
		if (equal(b, c)){
			if ((ret==-1) || (num(i)<num(ret)))
				ret = i;
		}
	}
	return ret;
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
		scanf("%d%d", &n, &m);
		read(a), read(b);

		
		printf("Case #%d: ", te);
		int ans = gao();
		if (ans!=-1) printf("%d\n", num(ans));
		else puts("NOT POSSIBLE");
    }
    return 0;
}
