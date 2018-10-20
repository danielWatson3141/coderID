#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define FI first
#define SE second

const int INF = 1000000001;
const double EPS = 10e-9;


const int MAXN = 1010;
map<PII, PII> M;
VI g[MAXN];
int testCases, n, x, y;


bool cmp(PII A, PII B) {
	return (A.FI-A.SE > B.FI-B.SE);
}


PII take_val(PII p) {

	if(M.find(p) == M.end()) {
		
		PII result;
		VPII f; f.clear();

		FOREACH(it, g[p.SE]) {
			if((*it) != p.FI) {
				f.PB(take_val(MP(p.SE, *it)));
			}
		}


		sort(f.begin(), f.end(), cmp);


		int r = 0;
		FOREACH(it, f) r+=(*it).FI;

		result.FI = r+1;

		if(SIZE(f)>=2) {
			r-=(f[0].FI-f[0].SE);
			r-=(f[1].FI-f[1].SE);
		}

		result.SE = r;

		M[p] = result;
	}

	return M[p];
}


int main() {

	scanf("%d", &testCases);

	FOR(testCase, 1, testCases) {
		scanf("%d", &n);

		FOR(i,1,n) g[i].clear();
		M.clear();

		REP(i,n-1) {
			scanf("%d%d", &x, &y);
			g[x].PB(y); g[y].PB(x);
		}


		int result = INF;

		FOR(i,1,n) {
			PII p = take_val(MP(0,i));

			// printf("%d %d/%d\n", i, p.FI, p.SE);

			result = min(result, p.SE);
		}

		printf("Case #%d: %d\n", testCase, result);
	}

	return 0;
}
