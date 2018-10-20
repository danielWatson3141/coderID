
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

#define MAXN 1010

int n;
int p[MAXN];

inline void input()
{
	scanf("%d", &n);
	REP(i, 0, n-1) scanf("%d", p+i);
}

inline void solve(int __)
{
	int stays = 0;
	REP(i, 0, n-1) stays += p[i] == i;
	if((stays+1) * (n*n-n) > (n*n+n-1))
		printf("Case #%d: BAD\n", __);
	else 
		printf("Case #%d: GOOD\n", __);
}

void dfs(int step, vector<int> per)
{
	if(step == 3)
	{
		REP(i, 0, 2) printf("%d ", per[i]);
		puts("");
		return ;
	}
	swap(per[step], per[0]);
	dfs(step+1, per);
	swap(per[step], per[0]);
	swap(per[step], per[1]);
	dfs(step+1, per);
	swap(per[step], per[1]);
	swap(per[step], per[2]);
	dfs(step+1, per);
	swap(per[step], per[2]);
}

int main()
{
	vector<int> tmp(3);
	REP(i, 0, 2) tmp[i] = i;
//	dfs(0, tmp);
	int t;
	cin>>t;//scanf("%d", &t);
	REP(__, 1, t)
	{
		input();
		solve(__);
	}
}
