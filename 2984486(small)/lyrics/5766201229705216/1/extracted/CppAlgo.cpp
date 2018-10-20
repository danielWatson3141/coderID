#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>  // File RW
#include <memory>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#define FILL(a, v) (memset(a, v, sizeof(a)))
#define foreach(i, Type, v) for(Type::iterator i=v.begin(); i!=v.end(); i++)
using namespace std;
typedef long long llong;
typedef pair<int, int> Int2;

const int Maxn = 1000+10;
const int INF = 0x7f7f7f7f;
const int MOD = 1000000007;
const double eps = 1e-10;
const double pi = acos(-1.0);

inline void AddMod(int &x, int det) { x += det; if( x >= MOD ) x -= MOD; }
inline int CompareTo(double a, double b) { return (a>b+eps) ? 1 : ((a+eps<b)?-1:0); }
template<typename T> int sz(const T &a) { return a.size(); }
template<typename T> T str2num(string s) { istringstream i(s); T x; i>>x; return x; }
template<typename T> string x2str(T x) { ostringstream o; o<<x; return o.str(); }

vector<int> g[Maxn];

int dfs(int p, int pre)
{
	int ret = 1;
	if( sz(g[p]) <= 2 )
		return ret;
	vector<int> tmp;
	for(int i=0; i<sz(g[p]); i++)
		if( g[p][i] != pre )
			tmp.push_back(dfs(g[p][i], p));
	sort(tmp.begin(), tmp.end(), greater<int>());
	ret += tmp[0]+tmp[1];
	return ret;
}
int main()
{
	int cas, N, t1, t2;
	ios::sync_with_stdio(0);
	freopen("aaa.in", "r", stdin);
	freopen("aaa.out", "w", stdout);

	cin>>cas;
	for(int c=1; c<=cas; c++)
	{
		cin>>N;
		for(int i=0; i<Maxn; i++)
			g[i].clear();
		for(int i=0; i<N-1; i++)
		{
			cin>>t1>>t2;
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		int ans = 0;
		for(int i=1; i<=N; i++)
		{
			int cnt = 1;
			if( sz(g[i]) >= 2 )
			{
				vector<int> tmp;
				for(int j=0; j<sz(g[i]); j++)
					tmp.push_back(dfs(g[i][j], i));
				sort(tmp.begin(), tmp.end(), greater<int>());
				cnt += tmp[0]+tmp[1];
			}
			//printf("%d %d\n", i, cnt);
			ans = max(ans, cnt);
		}
		printf("Case #%d: %d\n", c, N-ans);
		//printf("%d\n", N);
	}

	return 0;
}
