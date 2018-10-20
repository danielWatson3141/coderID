#include<cstdio>
#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C&a4, C b4) { a4 = max(a4, b4); }
#define maxn 1005
VI t[maxn];

P dfs(int act, int papa) {
	vector<P> child;
	FORE(it, t[act]) if (*it != papa) {
		child.PB(dfs(*it, act));	
	}
	//cout << "FFFF " << act << endl;
//	FORE(it, child) cout << it -> FI << " " << it -> SE << endl;
//	cout << endl;
	if (siz(child) == 0) {
		return MP(1, 0);
	} else {
		int sum = 0;
		int sum2 = 0;
		VI uu;
		FORE(it, child) {
			sum += it -> FI;
			sum2 += it -> SE;
			uu.PB(-it -> FI + it -> SE);
		}
		sort(ALL(uu));

		if (siz(child) == 1) {
			return MP(1 + sum, child[0].FI);
		} else {
			if (siz(child) == 2) {
				return MP(1 + sum, min(sum, child[0].SE + child[1].SE));
			} else {
				return MP(1 + sum, 	min(sum, sum + uu[0] + uu[1]));
			}
		}

	}
}

int main(){
	int cas;
	cin >> cas;
	fup(c, 1, cas) {
		int n;
		cin >> n;
		fup(i, 1, n) t[i].clear();
		fup(i, 1, n - 1) { int a, b; cin >> a >> b;
			t[a].PB(b); t[b].PB(a); }

		int best = INF;
		fup(i, 1, n) {
			P x = dfs(i, -1);
		//	cout << i << " " << x.FI << " " << x.SE << endl;
//			break;
			mini(best, x.SE);
		}
		printf("Case #%d: %d\n", c, best);

	}

    return 0;
}

