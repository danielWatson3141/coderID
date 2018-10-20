#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
const int MAX_N = 1000;
int edge[MAX_N][MAX_N];
int parent[MAX_N];
int nAdjChilds[MAX_N];
int nChilds[MAX_N];
int rem[MAX_N];

int calcChilds(int v)
{
	if (nChilds[v] != -1) return nChilds[v];
	nChilds[v] = 0;
	nAdjChilds[v] = 0;
	for (int w = 0; w < N; ++w) {
		//cout << v <<" " << w << " " << edge[v][w] << endl;
		if (edge[v][w] == 1 && w != parent[v]) {
			parent[w] = v;
			nAdjChilds[v]++;
			nChilds[v] += calcChilds(w) + 1;
			//cout << v << " " << w << endl;
		}
	}
	return nChilds[v];
}

int getRemove(int v)
{
	if (rem[v] != -1) return rem[v];
	if (nAdjChilds[v] == 0) {
		rem[v] = 0;
		// cout << v << "(0)" << 0 << endl;
		return 0;
	} else if (nAdjChilds[v] == 1) {
		rem[v] = nChilds[v];
		// cout << v << "(1)" << nChilds[v] << endl;
		return nChilds[v];
	} else if (nAdjChilds[v] == 2) {
		int res = 0;
		for (int w = 0; w < N; ++w) {
			if (parent[w] == v) {
				res += getRemove(w);
			}
		}
		rem[v] = res;
		// cout << v << "(2)" << res << endl;
		return res;
	} else {
		int res = 0;
		for (int w = 0; w < N; ++w) {
			if (parent[w] == v) {
				res += getRemove(w);
			}
		}
		rem[v] = res + (nAdjChilds[v] - 2);
		// cout << v << "(" << nAdjChilds[v] << ")" << res << endl;
		return res;
	}
}

void solve()
{
	int X, Y;
	scanf("%d", &N);
	// cout << "N:" << N << endl;
	memset(edge, 0, sizeof(edge));
	for (int i = 0; i < N - 1; ++i) {
		scanf("%d %d", &X, &Y);
		edge[X - 1][Y - 1] = 1;
		edge[Y - 1][X - 1] = 1;
	}

	// for (int i = 0; i < N; ++i) {
	// 	for (int j = 0; j < N; ++j) {
	// 		printf("%d", edge[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int res = INT_MAX;
	for (int i = 0; i < N; ++i) {
		// i:root
		memset(parent, -1, sizeof(parent));
		memset(nChilds, -1, sizeof(nChilds));
		memset(nAdjChilds, 0, sizeof(nAdjChilds));
		calcChilds(i);
		parent[i] = -2;

		// cout << i << endl;
		// for (int j = 0; j < N; ++j) {
		// 	cout << parent[j] << " " << nChilds[j] << endl;
		// }

		// search
		memset(rem, -1, sizeof(rem));
		res = min(res, getRemove(i));
		// cout << "res:" << res << ":" << i << endl;
	}

	printf("%d", res);
    return;
}

int main()
{
    int nCases = 0;
    scanf("%d", &nCases);
    for (int i = 1; i <= nCases; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
