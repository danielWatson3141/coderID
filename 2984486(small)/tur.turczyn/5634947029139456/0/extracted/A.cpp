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
typedef vector<string> vstring;
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

int solve(vllong &A, vllong &B, int N, int shift)
{
	llong x = A[0] ^ B[shift];

	vllong C(N);
	REP(i, N)
		C[i] = B[i] ^ x;
	sort(ALL(C));
	
	REP(i, N)
		if(A[i] != C[i])
			return INF;
	
	int out = 0;
	while(x)
	{
		if(x % 2)
			out++;
		x >>= 1;
	}
	
	return out;
}

llong convert(string &x)
{
	llong out = 0LL;
	REP(i, SIZE(x))
		if(x[i] == '1')
			out ^= (1 << i);
	
	return out;
}

int main()
{
	int T;
	
	cin >> T;
	REP(t, T)
	{
		int N, L;
		cin >> N >> L;
		
		string x;
		vllong A(N), B(N);
		REP(i, N)
			cin >> x, A[i] = convert(x);
		REP(i, N)
			cin >> x, B[i] = convert(x);
		
		sort(ALL(A));
		int out = INF;
		REP(i, N)
			out = min(out, solve(A, B, N, i));
		
		printf("Case #%d: ", t + 1);
		if(out <= L)
			cout << out << endl;
		else
			cout <<	"NOT POSSIBLE" << endl;
	}
	
	return 0;
}
