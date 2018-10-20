#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define PRINT(x...) TRACE(printf(x))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define FU(i, a, b) for(decltype(a) i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)

#define mset(c, v) memset(c, v, sizeof(c))
#define mod(a, b) ((((a)%(b))+(b))%(b))
#define pb push_back
#define SZ(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-8;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef long long ll;


int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

long double matrix[1000][1000];

int main() {
	int _42;
	scanf("%d", &_42);
	// load the matrix:
	FILE *f = fopen("matrix", "r");
	fu(i, 1000) fu(j, 1000) fscanf(f, "%Le", &matrix[i][j]);
	fclose(f);

	// we want to beat:
	long double tobeat = 0.;
	long double one = 1.;
	for (long double i = 1.; i <= 1000; i += 1.) tobeat += logl(one/i);
	fu(_41, _42) {
		int N;
		scanf("%d", &N);
		long double prob = 0;
		fu(i, N) {
			int k;
			scanf("%d", &k);
			prob += logl(matrix[k][i]);
			long double s = 0.;
			FU(j, i, N) s += matrix[k][j];
			prob -= logl(s);
		}
		printf("Case #%d: %s\n", _41+1, (prob > tobeat)?"BAD":"GOOD");
	}
	return 0;
}
