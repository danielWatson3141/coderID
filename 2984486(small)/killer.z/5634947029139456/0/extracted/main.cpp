#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cstring>
#include <string>
using namespace std;

#define pairii pair<int, int>
#define llong long long
#define pb push_back
#define sortall(x) sort((x).begin(), (x).end())
#define INFI  numeric_limits<int>::max()
#define INFLL numeric_limits<llong>::max()
#define INFD  numeric_limits<double>::max()
#define FOR(i,s,n) for (int (i) = (s); (i) < (n); (i)++)
#define FORZ(i,n) FOR((i),0,(n))

int n,l;

int bfs(vector<string> outlet, const vector<string>& dev) {
    set<vector<string> > visited;
    queue<vector<string> > q;
    queue<int> d;
    q.push(outlet);
    d.push(0);
    visited.insert(outlet);
    while (!q.empty()) {
        vector<string> t = q.front();
        q.pop();
        int tmpd = d.front();
        d.pop();
        if (t == dev) return tmpd;
        FORZ(i,l) {
            vector<string> g = t;
            FORZ(j,n) {
                char& ch = g[j][i];
                ch = (ch == '1') ? '0' : '1';
            }
            sortall(g);
            if (visited.find(g) == visited.end()) {
                visited.insert(g);
                q.push(g);
                d.push(tmpd+1);
            }
        }
    }
    return -1;
}

void solve() {
    scanf("%d %d", &n, &l);
    vector<string> outlet(n);
    vector<string> dev(n);
    FORZ(i,n) cin >> outlet[i];
    FORZ(i,n) cin >> dev[i];
    sortall(outlet);
    sortall(dev);
    int res = bfs(outlet, dev);
    if (res >= 0) printf("%d\n", res);
    else printf("NOT POSSIBLE\n");
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    int t;
    scanf("%d", &t);
    FOR(i,1,t+1) {
        printf("Case #%d: ", i);
        solve();
    }
    
    return 0;
}

