#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define FOR(i,a,n) for (int i = (a); i < (n); ++i)
#define FORE(i,a,n) for (int i = (a); i <= (n); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define LL long long
#define FIR(n) REP(i,n)
#define FJR(n) REP(j,n)
#define ALL(v) v.begin(), v.end()

#define FI FIR(n)
#define FJ FJR(n)
#define FR(i,a) FOR(i,a,n)
#define REPN(i) REP(i,n)

#define GI(n) scanf("%d", &n)
#define GI2(n,m) scanf("%d %d", &n, &m)

int n;
int L;

string cur[200];
int sw[50];

int solve() {
	GI2(n, L);
	vector<string> want(n), d;
	FI cin >> want[i];
	FI cin >> cur[i];

	sort(ALL(want));

	int res = 10000;
	FI {
		int rr = 0;
		FJR(L) if (want[0][j] == cur[i][j]) {
			sw[j] = 0;
		} else {
			sw[j] = 1;
			++rr;
		}

		d.clear();
		FJ {
			string s = cur[j];
			REP(k, L) if (sw[k]) s[k] = '0' + '1' - s[k];
			d.push_back(s);
		}
		sort(ALL(d));
		if (d == want)
			res=min(res, rr);

	}
		
	return res == 10000 ? -1 :res;
}

void prepare_input();
int main() {
	prepare_input();
	
	int ntc; GI(ntc);
	FORE(tc, 1, ntc) {
		int res = solve();
		if (res >= 0)
			printf("Case #%d: %d\n", tc, res);
		else
			printf("Case #%d: NOT POSSIBLE\n", tc, res);
	}
}


void prepare_input()  {
	bool LOCAL = false;
	char TASK = 'A';

	static char in_file[200], out_file[200];
	if (LOCAL) {
		freopen("input.txt", "rt", stdin);
	} else {

		int ATTEMPT = 0;
		bool LARGE = true;

		if (LARGE) {
			sprintf(in_file, "%c-large.in", TASK);
			sprintf(out_file, "%c-large.out", TASK);
		} else {
			sprintf(in_file, "%c-small-attempt%d.in", TASK,  ATTEMPT);
			sprintf(out_file, "%c-small-attempt%d.out", TASK,  ATTEMPT);
		}

		cerr << in_file <<  endl; freopen(in_file, "rt", stdin);
		cerr << out_file << endl; freopen(out_file, "w", stdout);
	}
}
