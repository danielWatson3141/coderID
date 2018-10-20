#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

typedef long long            int64;
typedef pair<double, double> pdd;
typedef pair<int,  int>      pii;
typedef pair<int64, int64>   pii64;
typedef unsigned long long   uint64;
typedef vector<double>       vd;
typedef vector<int64>        vi64;
typedef vector<int>          vi;
typedef vector<vi>           vvi;

const double eps = 1e-11;
const double pi  = acos(-1.0);
const int    p   = 1000000007;

vector<vector<pii>> g;
vector<int> visited;

int dfs_cnt(int from) {
    int result = 1;
    visited[from] = true;
    for (int i = 0; i < g[from].size(); ++i) {
        if (!visited[g[from][i].first]) {
            result += dfs_cnt(g[from][i].first);
        }
    }
    return result;
}

int dfs_cost(int from, int parent) {
    auto children = g[from];
    children.erase(std::remove_if(children.begin(), children.end(),
            [&](pii edge) { return edge.first == parent; }),
            children.end());

    if (children.size() == 0) return 0;
    if (children.size() == 1) return children.front().second;
    vi costs(children.size());
    for (int i = 0; i < children.size(); ++i) {
        costs[i] = dfs_cost(children[i].first, from) - children[i].second;
    }
    int a = min_element(costs.begin(), costs.end()) - costs.begin();
    costs[a] = INT_MAX;
    int b = min_element(costs.begin(), costs.end()) - costs.begin();
    int result = 0;
    for (int i = 0; i < children.size(); ++i) {
        if (i != a && i != b) {
            result += children[i].second;
        } else {
            result += dfs_cost(children[i].first, from);
        }
    }
    return result;
}

void solve() {
    int N;
    cin >> N;
    g.clear();
    g.resize(N);
    for (int i = 0 ; i < N - 1; ++i) {
        int from, to;
        cin >> from >> to;
        from --, to --;
        g[from].push_back(pii(to, 0));
        g[to].push_back(pii(from, 0));
    }
    for (int i = 0; i < N; ++i) {
        for (auto& edge: g[i]) {
            visited.assign(N, false);
            visited[i] = true;
            edge.second = dfs_cnt(edge.first);
          //  cout << i <<" <-> " <<edge.first << ": " << edge.second<< endl;
        }
    }
    int result = INT_MAX;
    for (int root = 0; root < N; ++root) {
        int cost = dfs_cost(root, INT_MAX);
        result = min(result, cost);
       // cout << " For rt: " <<root << ' ' << cost << endl;
    }
    cout << result << endl;
}
/*
1
7
4 5
4 2
1 2
3 1
6 4
3 7
 */
int main() {
    int nTests;
    cin >> nTests;

    for(unsigned int testNumber = 0; testNumber < nTests; ++testNumber) {
        printf("Case #%d: ", testNumber + 1);
        solve();
    }
    return 0;
}
