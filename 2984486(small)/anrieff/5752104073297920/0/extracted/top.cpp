#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

int n;
double m[1010][1010];
int a[1010];

void prepareTable(void) {
	memset(m, 0, sizeof(m));
	FOR(i, n) m[i][i] = 1;
	// m[i][j] - the possibility that the number at position `i' is `j'.
	double m1 = 1.0 / n;
	double m2 = (n - 1.0) / n;
	for (int move = 0; move < n; move++) {
		double columns[1010] = {0};
		FOR(i, n)
			FOR(j, n)
				columns[j] += m[i][j];
		FOR(i, n) {
			if (i == move) continue;
			FOR(j, n)
				m[i][j] = m[i][j] * m2 + m[move][j] * m1;
		}
		FOR(j, n)
			m[move][j] = columns[j] * m1;
	}
	FOR(i, n)
		FOR(j, n)
			m[i][j] *= n;
}

double evalProb(void)
{
	double prob = 1.0;
	for (int i = 0; i < n; i++) prob *= m[i][a[i]];
	return prob;
}

int main(void)
{
// 	freopen("/home/vesko/gcj/c.in", "rt", stdin);
	int TC;
	scanf("%d", &TC);
	for (int T = 1; T <= TC; T++) {
		int new_n;
		scanf("%d", &new_n);
		if (new_n != n) {
			n = new_n;
			prepareTable();
		}
		FOR(i, n) scanf("%d", &a[i]);
		printf("Case #%d: %s\n", T, evalProb() > 1.001 ? "BAD" : "GOOD");
	}
}
