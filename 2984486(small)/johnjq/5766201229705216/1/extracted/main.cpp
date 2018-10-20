#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
#define MAX_N 1000

struct Info {
    int reachable_from;
    int deleted;
};
struct ChildInfo {
    int  vert;
    Info info;
    bool operator<(const ChildInfo rhs) const {
        const int t = info.reachable_from - info.deleted;
        const int r = rhs.info.reachable_from - rhs.info.deleted;
        return t > r;
    }
};

int n;
vector<int> adj[MAX_N+1];
Info dfs(int u, int v) {
    //printf("dfs: (%d, %d)\n", u, v);
    const int sz = adj[v].size() - (u == -1 ? 0 : 1);
    Info info;
    if (sz == 0) {
        info.reachable_from = 1;
        info.deleted = 0;
    } else {
        if (sz == 1) {
            for (const int w : adj[v]) if (w != u) {
                Info wi = dfs(v, w);
                info.reachable_from = 1 + wi.reachable_from;
                info.deleted = wi.reachable_from;
            }
        } else { // sz >= 2
            vector<ChildInfo> childs;
            for (const int w : adj[v]) if (w != u) {
                Info child_info = dfs(v, w);
                ChildInfo aaa;
                aaa.vert = w;
                aaa.info = child_info;
                childs.push_back(aaa);
            }

            info.reachable_from = 1;
            for (const ChildInfo& child : childs) {
                info.reachable_from += child.info.reachable_from;
            }

            sort(childs.begin(), childs.end());
            info.deleted = childs[0].info.deleted + childs[1].info.deleted;
            for (int i = 2; i < sz; ++i)
                info.deleted += childs[i].info.reachable_from;
        }
    }
    return info;
}

void solve_testcase()
{
    scanf("%d", &n);
    for (int v = 1; v <= n; ++v)
        adj[v].clear();
    for (int e = 0; e < n-1; ++e) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int best = n;
    for (int root = 1; root <= n; ++root) {
        int acc = dfs(-1, root).deleted;
        best = min(best, acc);
    }
    printf("%d\n", best);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("B-large.in", "r", stdin);
    //freopen("B-small.in", "r", stdin);
    freopen("B-large.out", "w+", stdout);
    #endif

    int testcases_count;
    scanf("%d", &testcases_count);
    for (int testcase = 1; testcase <= testcases_count; ++testcase) {
        printf("Case #%d:", testcase);
        putchar(' ');
        //putchar('\n');
        solve_testcase();
    }
}
