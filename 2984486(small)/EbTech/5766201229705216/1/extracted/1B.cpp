#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define MINF 0xc0c0c0c0
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

int T, N;
int first[1000]; // first[node] is the first edge in the adjacency list of node
int nxt[2000];  // nxt[i] is the nxt edge in the same adjacency list as edge i
int ep[2000];    // ep[i] and ep[i^1] are the start and end nodes of edge i

int dfs(int u, int p)
{
	int n1 = -1, n2 = -1;
	for (int e = first[u]; e != -1; e = nxt[e])
	{
		int v = ep[e^1];
		if (v == p)
			continue;
		n2 = max(n2, dfs(v, u));
		if (n1 < n2)
			swap(n1, n2);
	}
	if (n2 == -1)
		return 1;
	return 1 + n1 + n2;
}

int main()
{
    ios::sync_with_stdio(0);
    //cout << fixed << setprecision(9);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
    	memset(first, -1, sizeof first);
    	cin >> N;
    	for (int i = 0; i < 2*(N-1); ++i)
    	{
    		cin >> ep[i], --ep[i];
    		nxt[i] = first[ep[i]];
    		first[ep[i]] = i;
    	}
    	int ans = 0;
    	for (int i = 0; i < N; ++i)
    	{
    		ans = max(ans, dfs(i, -1));
    	}
    	cout << "Case #" << z << ": ";
    	cout << (N - ans) << endl;
    }
}
