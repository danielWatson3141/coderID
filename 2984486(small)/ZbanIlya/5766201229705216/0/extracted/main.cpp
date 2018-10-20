#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#define y1 _dfdfdfd


const int maxn = 1010;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
vector<int> e[maxn];
int cnt[maxn], dp[maxn];

void dfs(int v, int p = -1) {
    cnt[v] = 1;
    dp[v] = 0;
    for (int i = 0; i < (int)e[v].size(); i++) {
        if (e[v][i] == p) continue;
        dfs(e[v][i], v);
        cnt[v] += cnt[e[v][i]];
    }
    if (e[v].size() == 1 && p != -1) return;
    if (e[v].size() == 2 && p != -1 || e[v].size() == 1 && p == -1) {
        for (int i = 0; i < (int)e[v].size(); i++) if (e[v][i] != p) dp[v] += cnt[e[v][i]];
        return;
    }
    vector<int> vct;
    for (int i = 0; i < (int)e[v].size(); i++) {
        if (e[v][i] == p) continue;
        dp[v] += cnt[e[v][i]];
        // не += cnt[e[v][i]]
        // а += dp[e[v][i]]
        // значит += dp[e[v][i]] - cnt[e[v][i]]
        vct.push_back(dp[e[v][i]] - cnt[e[v][i]]);
    }
    sort(vct.begin(), vct.end());
    dp[v] += vct[0] + vct[1];
}
 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        
        cin >> n;
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            dfs(i);
            ans = min(ans, dp[i]);
        }
        cout << ans << endl;
    }

	return 0;
}
