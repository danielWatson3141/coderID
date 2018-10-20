
// default code for competitive programming
// c2251393 ver 3.141 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define DEBUG 1
#define fst first
#define snd second

using namespace std;

// Typedefs
typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);

// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

// }}}
// start ~~QAQ~~

#define MAXN 160
#define MAXL 50
#define INF 100000010

int n, l;
string outlet[MAXN], device[MAXN];

inline void input()
{
	cin>>n>>l;//scanf("%d%d", &n, &l);
	REP(i, 1, n) cin>>outlet[i];//scanf("%s", outlet[i].c_str());
	REP(i, 1, n) cin>>device[i];//scanf("%s", device[i].c_str());
}

inline string key(string& a1, string& a2)
{
	string tmp;
	tmp = a1;
	REP(i, 0, l-1)
		if(a1[i] != a2[i]) tmp[i] = '1';
		else tmp[i] = '0';
	return tmp;
}

inline int cnt(string& str)
{
	int res = 0;
	FOR(it, str) if(*it == '1') 
		res++;
	return res;
}

vector<string> possible[MAXN];
int vis[MAXN];

inline void solve(int __)
{
//	cout << n << endl;
	int ans = l+1;
	REP(i, 1, n) possible[i].clear();

	REP(i, 1, n) REP(j, 1, n)
		possible[i].push_back(key(device[i], outlet[j]));

//	for(int k = 0; k < n; k++)
	REP(k, 0, n-1)
	{// choose possible[1][k]
//		cout << k << endl;
		fill(vis, vis+n+1, 0);
		vis[k]++;
		string pattern = possible[1][k];
//		cout << pattern << endl;
		REP(i, 2, n)REP(j, 0, n-1)if(pattern == possible[i][j])
			vis[j]++;
		bool flag = 1;
		REP(i, 0, n-1) if(vis[i] != 1)
			flag = 0;
		if(!flag) continue ;
		ans = min(ans, cnt(pattern));
	}

	if(ans > l)
		printf("Case #%d: NOT POSSIBLE\n", __);
	else
		printf("Case #%d: %d\n", __, ans);
}

int main()
{
	int t;
	cin>>t;//scanf("%d", &t);
	REP(__, 1, t)
	{
		input();
		solve(__);
	}
}
