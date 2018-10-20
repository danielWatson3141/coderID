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

const int Maxn = 150+10;
const int INF = 0x7f7f7f7f;
const int MOD = 1000000007;
const double eps = 1e-10;
const double pi = acos(-1.0);

inline void AddMod(int &x, int det) { x += det; if( x >= MOD ) x -= MOD; }
inline int CompareTo(double a, double b) { return (a>b+eps) ? 1 : ((a+eps<b)?-1:0); }
template<typename T> int sz(const T &a) { return a.size(); }
template<typename T> T str2num(string s) { istringstream i(s); T x; i>>x; return x; }
template<typename T> string x2str(T x) { ostringstream o; o<<x; return o.str(); }

llong s1[Maxn], s2[Maxn], tt[Maxn];

llong change(string s)
{
	llong ret = 0;
	for(int i=0; i<sz(s); i++)
		ret = ret*2+(s[i]=='1');
	return ret;
}
bool check(int N)
{
	for(int i=0; i<N; i++)
		if( s2[i] != tt[i] )
			return false;
	return true;
}
int main()
{
	int cas, N, L;
	ios::sync_with_stdio(0);
	freopen("aaa.in", "r", stdin);
	freopen("aaa.out", "w", stdout);

	cin>>cas;
	for(int c=1; c<=cas; c++)
	{
		cin>>N>>L;
		string tmp;
		for(int i=0; i<N; i++)
		{
			cin>>tmp;
			s1[i] = change(tmp);
		}
		for(int i=0; i<N; i++)
		{
			cin>>tmp;
			s2[i] = change(tmp);
		}
		sort(s2, s2+N);
		//for(int i=0; i<N; i++)
			//printf("%lld ", s2[i]);
		//puts("");
		int ans = INF;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				llong t1 = s1[i]^s2[j];
				//printf("%lld\n", t1);
				for(int k=0; k<N; k++)
					tt[k] = s1[k]^t1;
				sort(tt, tt+N);
				//for(int k=0; k<N; k++)
					//printf("%lld ", tt[k]);
				//puts("");
				if( check(N) )
					ans = min(ans, __builtin_popcount(t1));
			}
		printf("Case #%d: ", c);
		if( ans != INF )
			printf("%d\n", ans);
		else
			puts("NOT POSSIBLE");
	}

	return 0;
}
