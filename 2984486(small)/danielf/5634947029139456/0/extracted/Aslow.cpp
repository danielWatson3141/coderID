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

char temp[150];
void read(int& x) {
	x = 0;
	scanf(" %s", temp);
	for (int i = 0; temp[i]; i++)
		x = 2*x + (temp[i] - '0');
}

int main() {
	int _42;
	scanf("%d", &_42);
	fu(_41, _42) {
		int N, L;
		scanf("%d %d", &N, &L);
		vi o(N), d(N);
		// read
		for (auto&x : o) read(x);
		for (auto&x : d) read(x);
		sort(all(d));
		int ans = L+1;
		fu(i, 1 << L) {
			if (__builtin_popcount(i) >= ans) continue;
			fu(j, L) if ( (i >> j) & 1) for (auto &x : o) x ^= (1 << j);
			sort(all(o));
			if (o == d) ans = __builtin_popcount(i);
			fu(j, L) if ( (i >> j) & 1) for (auto &x : o) x ^= (1 << j);
		}
		printf("Case #%d: ", _41+1);
		if (ans == L+1) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}
