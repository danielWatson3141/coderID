#include <cstdio>
#include <vector>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
const int MAXN = 1005;
const int INF = 1e9;

std::vector<int> adj[MAXN];
int visited[MAXN], cast;
int subtree[MAXN];

bool cmp(std::pair<int, int> p1, std::pair<int, int> p2) {
    return p1.first-p1.second < p2.first-p2.second;
}

int dfs(int u) {
    visited[u] = cast;
    subtree[u] = 1;
    
    std::vector< std::pair<int, int> > res;
    for (int v: adj[u]) {
        if (visited[v] != cast) {
            int r = dfs(v);
            //printf("wynik dla syna %d: %d\n", v, r);
            res.push_back({r, subtree[v]});
            subtree[u] += subtree[v];
        }
    }

    std::sort(res.begin(), res.end(), cmp);
    if (res.size() == 1)
        return res[0].second;
    if (res.size() == 0)
        return 0;
    return res[0].first+res[1].first+subtree[u]-res[0].second-res[1].second-1;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        int n;
        scanf("%d", &n);

        for (int i=0; i<n; i++)
            adj[i].clear();

        for (int i=0; i<n-1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int res = n;
        for (int i=0; i<n; i++) {
            cast++;
            //printf("ukorzeniam w %d\n", i);
            res = std::min(res, dfs(i));
            //printf("res = %d\n", res);
        }

        printf("Case #%d: %d\n", test, res);
    }
}
