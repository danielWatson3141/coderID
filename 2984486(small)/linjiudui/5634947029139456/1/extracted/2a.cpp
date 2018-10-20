#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<iostream>
#include<map>
#include<string>
#include<set>
#include<bitset>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
using namespace std;

#define PB push_back
#define MP make_pair
#define SIZE(X) (int)(X).size()

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, l, h) for(int i = (l); i < (h); i++)
#define RREP(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define FORD(i, l, h) for(int i = (int)(h-1); i >= (l); i--)

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string>VS;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef long long ll;

const ll oo = (1LL)<<40;
const int MAXN = 151;
const int MOD = 1000000007;
const double eps = 1e-8;
int N, L;
typedef struct{
	char f[42];
}Flow;

Flow src[MAXN], req[MAXN], mid[MAXN];
int sc[MAXN], rc[MAXN];

int ans;
int LL = 0;
bool cmp(const Flow &a, const Flow &b)
{
	REP(i, LL) if(a.f[i] != b.f[i]) return a.f[i] < b.f[i];
	return false;
}

int check(int t, int l)
{
	memcpy(mid, src, sizeof(src));
	int ptr = 0;
	while(t && ptr < l) {
		if(t&1) {
			REP(i, N){
				int tmp = mid[i].f[ptr]-'0';
				mid[i].f[ptr] = (tmp^1)+'0';
			}
		}
		t >>= 1;
		ptr++;
	}
	LL = l;
	sort(mid, mid+N, cmp);
	REP(i, N) if(strncmp(mid[i].f, req[i].f, l)) return false;
	return true;
}

int dfs(int d, int cs, int stat)
{
	if((d > 10 || d == L) && !check(stat, d)) return 0;
	if(d == L) {
		if(ans == -1 || ans > cs)
			ans = cs;
		return 0;
	}
	int cur = sc[d];
	if(cur == rc[d]) {
		dfs(d+1, cs, stat);
	}
	if(N-cur == rc[d]) {
		dfs(d+1, cs+1, (1<<d)|stat);
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	//freopen("a-small.in", "r", stdin);
	//freopen("a-small2.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	cin >> T;
	FOR(_, 1, T+1) {
		cin >> N >> L;
		memset(src, 0, sizeof(src));
		memset(req, 0, sizeof(req));
		memset(sc, 0, sizeof(sc));
		memset(rc, 0, sizeof(rc));
		REP(i, N){
			cin >> src[i].f;
			REP(j, L) {
				sc[j] += src[i].f[j]-'0';
			}
		}
		REP(i, N) {
			cin >> req[i].f;
			REP(j, L) {
				rc[j] += req[i].f[j]-'0';
			}
		}
		LL = L;
		sort(req, req+N, cmp);
		ans = -1;
		dfs(0, 0, 0);
		cout << "Case #" << _ << ": ";
		if(ans == -1)  cout << "NOT POSSIBLE" << endl;
		else cout << ans << endl;
		//cout << t << endl;
	}
	return 0;
}

/*
4
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01
4 4
0000 0001 0010 0011
1111 1110 1101 1100
*/