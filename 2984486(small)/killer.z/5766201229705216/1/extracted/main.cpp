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

vector<vector<int> > adj;
set<int> visited;

int search(int root) {
    visited.insert(root);
    if (adj[root].empty() || adj[root].size() == 1) return 1;
    vector<int> cnt;
    FORZ(i, adj[root].size()) {
        int node = adj[root][i];
        if (visited.find(node) == visited.end())
            cnt.pb(search(node));
    }
    sort(cnt.begin(), cnt.end(), greater<int>());
    if (cnt.size() == 0 || cnt.size() == 1) return 1;
    return 1+cnt[0]+cnt[1];
}

void solve() {
    int n;
    scanf("%d", &n);
    adj.clear();
    adj.resize(n);
    FORZ(i,n-1) {
        int a,b; scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int res = -1;
    FORZ(i,n) {
        visited.clear();
        res = max(res, search(i));
    }
    printf("%d\n", n-res);
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

