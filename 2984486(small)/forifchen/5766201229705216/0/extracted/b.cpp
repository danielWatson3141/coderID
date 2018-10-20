#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 1005
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}


int tc;
int n;
vint E[N];
int b[N];

void dfs(int u, int p) {
	int deg = 0;
	f(i,0,E[u].size()) if (E[u][i] != p) deg++;
	if (deg < 2) {
		b[u] = 1; return;
	}
	vint aux;
	f(i,0,E[u].size()) if (E[u][i] != p) {
		int v = E[u][i];
		dfs(v, u);
		aux.pb( b[v] );
	}
	sort(rall(aux));
	b[u] = 1 + aux[0] + aux[1];
}
int caso;

int main(){
	iostream::sync_with_stdio(0);
	cin >> tc;
	while(tc--) {
		cin >> n;
		f(i,0,n) E[i].clear();
		f(i,1,n) {
			int u,v; 
			cin >> u >> v;
			u--; v--;
			E[u].pb(v); E[v].pb(u);
		}
		int mn = oo;
		f(i,0,n) {
			dfs(i,i);
			mini(mn, n-b[i]);
		}
		cout << "Case #" << ++caso << ": " << mn << endl;
	}
}


