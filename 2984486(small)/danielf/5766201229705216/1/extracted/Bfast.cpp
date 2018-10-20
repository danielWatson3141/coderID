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

vvi graph;
vi s;
vi DP;

void computeSize(int node, int parent) {
	s[node] = 1;
	for (int x : graph[node]) if (x != parent) {
		computeSize(x, node);
		s[node] += s[x];
	}
}

void doit(int node, int parent) {
	vi temp;
	int sum = 0;
	for (int x : graph[node]) if (x != parent) {
		doit(x, node);
		sum += s[x];
		temp.push_back(DP[x] - s[x]);
	}
	sort(all(temp));
	if (temp.size() < 2) DP[node] = s[node]-1;
	else DP[node] = sum + temp[0] + temp[1];
}

int main() {
	int _42;
	scanf("%d", &_42);
	fu(_41, _42) {
		int N;
		scanf("%d", &N);
		graph = vvi(N);
		fu(i, N-1) {
			int a,b;
			scanf("%d %d", &a, &b); a--; b--;
			graph[a].pb(b);
			graph[b].pb(a);
		}
		int ans = N-1;
		fu(r, N) {
			s = vi(N, -1);
			DP = vi(N, -1);
			computeSize(r, -1);
			doit(r, -1);
			ans = min(ans, DP[r]);
		}
		printf("Case #%d: %d\n", _41+1, ans);
	}
	return 0;
}

