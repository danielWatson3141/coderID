#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define CLR(x, a) memset(x, a, sizeof(x))
//#define L(x) ((x) << 1)
#define R(x) (((x) << 1) + 1)
#define LB(x) ((x)&(-(x)))
#define SL(x) (1 << (x))
#define X first
#define Y second
const int MAXN = 1000 + 20;

int n;
vector<int> e[MAXN];
int dp[MAXN][MAXN];

int root(int rt, int par) {
	if (dp[rt][par] != -1) {
		return dp[rt][par];
	}
	vector<int> candi;
	for (int i = 0; i < e[rt].size(); i++) {
		int ch = e[rt][i];
		if (ch == par) continue;
		candi.PB(root(ch, rt));
	}
	sort(candi.begin(), candi.end());
	if (candi.size() < 2) {
		return (dp[rt][par] = 1);
	} else {
		return (dp[rt][par] = 1 + candi[candi.size() - 1] + candi[candi.size() - 2]);
	}
}

int main(){
    
	int T; cin >> T;
	FOR(cas, T){
		printf("Case #%d: ", cas + 1);
		cin >> n;
		FOR(i, n + 1) e[i].clear();
		FOR(i, n + 1) {
			FOR(j, n + 1) {
				dp[i][j] = -1;
			}
		}
		FOR(i, n - 1) {
            int a, b;
			cin >> a >> b;
			e[b].PB(a);
			e[a].PB(b);
		}
		int res = 1;
		FOR(i, n) {
			int tmp = root(i + 1, 0);
			if (tmp > res) {
				res = tmp;
			}
		}
		cout << n - res << endl;
	}
}