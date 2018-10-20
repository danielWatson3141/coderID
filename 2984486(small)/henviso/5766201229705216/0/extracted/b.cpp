#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);

vi g[1111];
bitset<11111> vis;
int n, t;

int dfs(int s){
	vis[s] = true;
	if(g[s].size() <= 2) return 1;
	
	int cnt = 1, x;
	int gt = 0, sgt = 0;
	REP(i, g[s].size()){
		if(!vis[g[s][i]]){
			x = dfs(g[s][i]);
			if(x > gt){
				sgt = gt;
				gt = x;
			}
			else{
				if(x > sgt) sgt = x;
			}
		}
	}
	cnt += gt+sgt;
	//cout << " S " << s  << "S.SIZE " << g[s].size() << " CNT " << cnt << " GT " << gt << " SGT " << sgt << endl;
	return cnt;
} 

int best(int r){
	vis.reset();
	vis[n+1] = true;
	g[r].push_back(n+1);
	
	int ans = dfs(r);
	g[r].pop_back();
	
	//cout << " SOBRARAM " << ans << " NOS NO ROOT " << r << endl;
	return (n - ans);
}

int main(){
	cin >> t;
	REPP(ca, 1, t+1){
		cin >> n;
		int u, v;
		
		REPP(i, 1, n+1) g[i].clear();
		REP(i, n-1){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = n-1;
		REPP(i, 1, n+1) ans = min(ans, best(i));
		cout << "Case #" << ca << ": " << ans << endl;
	}
}
