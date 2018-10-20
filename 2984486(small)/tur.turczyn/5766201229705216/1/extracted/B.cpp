#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

typedef long long llong;
typedef long double ldouble;
typedef pair<int, int> pint;
typedef pair<double, double> pdouble;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<llong> vllong;

#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()

#define ST first
#define ND second
#define INF 1000000000
#define INFL 1000000000000000000LL
#define EPS 1e-5

int subtree(vector<vint> &G, int N, int index, int parent)
{
	if(SIZE(G[index]) <= 1)
		return 1;
	if(SIZE(G[index]) == 2 && parent >= 0)
		return 1;
	
	//suma dwoch najwiekszych poddrzew
	vint A;
	REP(i, SIZE(G[index]))
		if(G[index][i] != parent)
			A.push_back(subtree(G, N, G[index][i], index));

	sort(ALL(A), greater<int>());	
	return A[0] + A[1] + 1;
}

int solve(vector<vint> &G, int N)
{
	int out = 0;
	REP(i, N)
	{
		out = max(out, subtree(G, N, i, -1));
		if(out == N)
			return N;
	}	
	return out;
}

int main()
{
	int T;
	
	cin >> T;
	REP(t, T)
	{
		int N, u, v;
		cin >> N;
		
		vector<vint> G(N);
		REP(i, N - 1)
			cin >> u >> v, --u, --v, G[u].push_back(v), G[v].push_back(u);
		
		printf("Case #%d: ", t + 1);
		if(N > 2)
			cout << N - solve(G, N) << endl;
		else
			cout << 1 << endl;
	}
	
	return 0;
}
