#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1024;

vector<int> G[maxn];
int f[maxn][maxn];
int s[maxn][maxn];
int n;

int size(int node, int father) {
    if (father != -1 && s[node][father] > 0) {
        return s[node][father];
    }

    int ans = 1;
    for (int t : G[node])
        if (t != father)
            ans += size(t, node);
    
    if (father != -1) {
        s[node][father] = ans;
    }
    return ans;
}

int dfs(int node, int father) {
    if (father != -1 && f[node][father] >= 0) {
        return f[node][father];
    }

    int child_cnt = 0;
    int child_cost_most = 0;
    int child_cost_s =  0;
    int size_total = 0;
    for (int t : G[node]) {
        if (t != father) {
            child_cnt ++;
            int cost = dfs(t, node);
            int si = size(t, node);
            size_total += si;
            int red = si - cost; 
            if (red > child_cost_most) {
                child_cost_s = child_cost_most;
                child_cost_most = red;
            } else if (red > child_cost_s) {
                child_cost_s = red;
            }
        }
    }

    int ans = size_total; // make it leaf
    if (child_cnt >= 2) {
        ans -= child_cost_most + child_cost_s;
    }

    if (father != -1) {
        f[node][father] = ans;
    }
    return ans;
}

int solve() {
    memset(f, 255, sizeof(f));
    memset(s, 0, sizeof(s));
    for (auto& g : G) g.clear();
    
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans = n;
    for (int i = 0; i < n; ++i) {
        int nans = dfs(i, -1);
        cerr << nans << endl;
        ans = min(ans, nans);
    }

    return ans;
}

int main() {
//    freopen("B.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int cc = 1; cc <= T; ++cc) {
        printf("Case #%d: %d\n", cc, solve());
    }
    return 0;
}
