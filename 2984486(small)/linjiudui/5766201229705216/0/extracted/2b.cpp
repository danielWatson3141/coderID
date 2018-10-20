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
const int MAXN = 1051;
const int MOD = 1000000007;
const double eps = 1e-8;
int N;

int ans;

VI tree[MAXN];
int del[MAXN], cnt[MAXN];
//int total = 0;

int dfs(int p, int t)
{
	//cout << p << t << endl;
	int child = 0;
	cnt[t] = 0;
	VI tmp;
	REP(i, SIZE(tree[t])) {
		int ed = tree[t][i];
		if(ed != p) {
			child++;
			int cs = dfs(t, ed);
			cnt[t] += cs;
			tmp.push_back(-cs);
		}
	}
	if(child != 2) {
		del[t] = 0;
		sort(tmp.begin(), tmp.end());
		if(tmp.size() > 1)
			del[t] = cnt[t]+tmp[1]+tmp[0]; 
		else del[t] = cnt[t];
	}
	return cnt[t]+1;
}

void dfs2(int p, int t, int &total)
{
	//cout << p << t << endl;
	int child = 0;
	if(del[t]) { 
		total += del[t];
		return; 
	}
	REP(i, SIZE(tree[t])) {
		int ed = tree[t][i];
		if(ed != p) {
			dfs2(t, ed, total);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	freopen("b-small.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);
	cin >> T;
	FOR(_, 1, T+1) {
		cin >> N;
		REP(i, N) tree[i].clear();
		REP(i, N-1) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		int ans = N;
		REP(i, N) {
			memset(del, 0, sizeof(del));
			dfs(-1, i);
			int total = 0;
			dfs2(-1, i, total);
			ans = min(ans, total);
		}
		cout << "Case #" << _ << ": ";
		cout << ans << endl;
		//cout << t << endl;
	}
	return 0;
}

/*
3
3
1 2
1 3
1 4
8
1 2
1 3
1 4
1 5
1 6
2 7 
2 8
4
1 2
2 3
3 4

*/