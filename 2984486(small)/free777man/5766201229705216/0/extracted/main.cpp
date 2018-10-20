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
#include <cstring> 
using namespace std; 
#define ALL(a) (a).begin(), (a).end() 
#define SZ(a) (int)(a).size() 
#define FOR(i,s,n) for(int i=(s);i<(n);++i) 
#define REP(i,n) FOR(i,0,(n)) 
#define PB(x) push_back((x)) 
#define CLR(a,v) memset((a),(v),sizeof((a))) 
typedef long long ll; 

char gused[1010], used[1010];
vector<vector<int> > g;
int n;

int getsize(int r)
{
	used[r]=1;
	int res=1;
	REP(i,SZ(g[r]))
	{
		int j = g[r][i];
		if (!used[j])res += getsize(j);
	}
	return res;
}

int f(int r)
{
	gused[r]=1;

	int tot = 0;
	vector<int> res;
	REP(i,SZ(g[r]))
	{
		int j = g[r][i];
		if (!gused[j])
		{
			int d = f(j);
			CLR(used,0);
			used[r]=1;
			int sz = getsize(j);
			tot += sz;
			res.push_back(sz-d);
		}
	}

	int m = SZ(res), ret = tot;
	REP(i,m)FOR(j,i+1,m)
	{
		int d = tot - res[i] - res[j];
		if(d<ret)
			ret=d;
	}
	return ret;
}

int main()
{
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int T;
	scanf("%d", &T);

	FOR(ttt,1,T+1)
	{
		cin>>n;
		g.assign(n, vector<int>());
		
		REP(i,n-1)
		{
			int x, y;
			cin>>x>>y;
			--x,--y;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		int res = n-1;
		REP(i,n)
		{
			CLR(gused, 0);
			int r = f(i);
			if(r < res)
			{
				res = r;
				//cout<<i<<" "<<res<<endl;
			}
		}

		printf("Case #%d: %d\n",ttt, res);
	}

	return 0;
}