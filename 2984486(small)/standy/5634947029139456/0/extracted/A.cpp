#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <sstream>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VL;
typedef vector <string> VS;

const int MAXN = 200;

int N, L;
string A[MAXN], B[MAXN];
int status[MAXN];

int dfs (int k, const vector <VI> &x, const vector <VI> &y)
{
	if (k == L || x.empty())	return 0;
	
	int res = MAXN;
	for (int v = 0; v < 2; ++ v)
	{
		vector <VI> nx, ny;
		for (int i = 0; i < x.size(); ++ i)
		{
			VI a[2], b[2];
			for (int j = 0; j < x[i].size(); ++ j)
			{
				a[v ^ (A[x[i][j]][k] - '0')].PB (x[i][j]);
				b[B[y[i][j]][k] - '0'].PB (y[i][j]);
			}	
			
			if (a[0].size() != b[0].size())	goto out;
			
			if (!a[0].empty())	nx.PB (a[0]), ny.PB (b[0]);
			if (!a[1].empty())	nx.PB (a[1]), ny.PB (b[1]);
		}
		
		res = min (res, dfs (k + 1, nx, ny) + v);
		
		out: ;	
	}
	
	return res;
}

int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);



	
	
	int T;	cin >> T;
	
	for (int cas = 1; cas <= T; ++ cas)
	{
		cin >> N >> L;
		for (int i = 0; i < N; ++ i)	cin >> A[i];
		for (int i = 0; i < N; ++ i)	cin >> B[i];
		VI t;
		for (int i = 0; i < N; ++ i)	t.PB (i);
		vector <VI> x, y;
		x.PB (t), y.PB (t);
		
		int res = dfs (0, x, y);
		
		cout << "Case #" << cas << ": ";
		if (res <= L)	cout << res << endl;
		else	cout << "NOT POSSIBLE" << endl;
			
	}
	
	
	return 0;	
}
