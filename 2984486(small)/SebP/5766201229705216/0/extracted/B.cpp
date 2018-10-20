///SACAR FREOPEN.
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<list>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<sstream>
#include<assert.h>

using namespace std;

#define all(c) (c).begin(),(c).end()
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define formn(i,m,n) for(int i=m;i<(int)n;i++)
#define dformn(i,m,n) for(int i=n-1;i>=m;i--)
#define mp make_pair
#define pb push_back

const double PI=acos(-1.0);

typedef long long tint;
typedef pair<int,int> pint;

int n;
vector<int> g[1010];

int dfs(int p, int v){
	///tengo que hallar las mayor cantidad de vertices que puede tener mi subarbol
//cerr << p << " -> " << v << endl;
	vector<int> values;
	forn(i,g[v].size()){
		int u = g[v][i];
		if(u != p){
			///pregunto por este subarbol
			int subr = dfs(v,u);
			values.pb(subr);
		}
	}
	sort(all(values));
	if(values.size() < 2){
		///no tengo suficientes hijos
		return 1;
	}
	else{
		int cant = values.size();
		return values[cant - 1] + values[cant - 2] + 1;
	}
}

int main(){
freopen("Bsmall.in","r",stdin);
freopen("Bsmall.out","w",stdout);
	int TC; cin >> TC;
	for(int tc = 1; tc <= TC; tc++){
		cin >> n;
		forn(i,n)
			g[i].clear();
		forn(i,n - 1){
			int u,v;
			cin >> u >> v;
			u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		int res = n;
		forn(v,n){
//cerr << v << endl;
			int keep = dfs(-1,v);
			res = min(res,n - keep);
		}
//cerr << " " << endl;
		cout << "Case #" << tc << ": ";
		cout << res << endl;
	}
    return 0;
}
