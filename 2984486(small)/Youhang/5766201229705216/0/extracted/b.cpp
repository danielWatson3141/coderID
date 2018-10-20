#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i ++)
#define mem(s, v) memset(s, v, sizeof(s))
#define sz(v) (int)v.size()
#define pb push_back
#define mp make_pair

vector<vector<int> > g;
int table[1001][1001];

int getres(int from, int to) {
    if (table[from][to] >= 0) return table[from][to];
    
    int res;
    if (sz(g[to]) < 3) res = 1;
    else {
        vector<int> v;
        for (int next: g[to]) if (next != from) {
            int res2 = getres(to, next);
            v.pb(res2);
        }
        sort(v.begin(), v.end(), greater<int>());
        res = v[0] + v[1] + 1;
    }
    
    table[from][to] = res;
    return res;
}

int main() {
    freopen("/Users/youhangtian/Downloads/B-small-attempt3.in", "r", stdin);
    freopen("/Users/youhangtian/Downloads/output.txt", "w", stdout);

    int T;
    cin >> T;
    
    for (int ca = 1; ca <= T; ca ++) {
        int n;
        cin >> n;
        
        g.clear();
        rep(i, n + 1) g.pb(vector<int>(0));
        rep(i, n - 1) {
            int a, b;
            cin >> a >> b;
            
            g[a].pb(b);
            g[b].pb(a);
        }
        
        mem(table, -1);
        
        int res = 1;
        for (int root = 1; root <= n; root ++) {
            if (sz(g[root]) < 2) continue;
            
            vector<int> v;
            for (int to: g[root]) {
                int r2 = getres(root, to);
                v.pb(r2);
            }
            sort(v.begin(), v.end(), greater<int>());
            
            int res2 = v[0] + v[1] + 1;
            res = max(res, res2);
        }
        
        cout << "Case #" << ca << ": " << n - res << endl;
    }
    
    return 0;
}