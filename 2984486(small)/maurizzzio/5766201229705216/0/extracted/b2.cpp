#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> graph(2344);
int total;
int theRoot;		

void solve(int root, int p) {
	if (graph[root].size() == 2 && root != theRoot)  {
		total++;
	}
	for(int i = 0; i < graph[root].size(); i += 1) {
		int dest = graph[root][i];
		if (dest != p) {
			solve(dest, root);
		}
	}
}

int main() {
	int cas, n;
	int from, to;
	cin >> cas;
	F(z, cas) {
		cin >> n;
		F(i, 1005) graph[i].clear();
		F(i, n - 1) {
			cin >> from >> to;
			from--; to--;
			// printf(">> %d %d\n", from, to);
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		int best = INF;
		// F(i, n) {
		// 	printf("%d = ", i);
		// 	F(j, graph[i].size()) printf("%d ", graph[i][j]);
		// 	NL;
		// }
		F(i, n) {
			total = 0;
			theRoot = i;
			solve(i, -1);			
			// printf("%d %d\n", i, total);
			best = min(best, total);
		}
		printf("Case #%d: %d\n", z + 1, best);
	}
	return 0;
}