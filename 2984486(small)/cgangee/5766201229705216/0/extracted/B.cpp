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
#define N 1000

int i,j,k,m,n,l;
vi a[N+10];
int num[N+10];

int dfs(int i, int fa){
	int son = 0, ret=0;
	num[i] = 1;
	rep(k, sz(a[i])){
		int j=a[i][k];
		if (j!=fa){
			ret+=dfs(j, i);
			num[i] += num[j];
			son++;
		}
	}
	if (son==0 || son==2) return ret;
	return num[i]-1;
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B1.out", "w", stdout);
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
		scanf("%d", &n);
		repf(i, 1, n) a[i].clear();
		rep(i, n-1){
			scanf("%d%d", &j, &k);
			a[j].pb(k), a[k].pb(j);
		}
		int ans=-1;
		repf(i, 1, n){
			_checkmin(ans, dfs(i, 0));
		}
		printf("Case #%d: %d\n", te, ans);
    }
    return 0;
}
