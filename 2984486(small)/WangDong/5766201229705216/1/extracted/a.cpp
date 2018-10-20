#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int n;
vector<int> a[1010];
int ans;

void init() {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    int x, y;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &x, &y);
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }
    ans = n - 1;
}

vector<int> b[1010];
int c[1010];
int d[1010];
int s[1010];
vector<int> tree[1010];

void dfs(int x, int fa) {
    for (int i = 0; i < a[x].size(); ++i)
        if (a[x][i] != fa) {
            dfs(a[x][i], x);
            c[x] += c[a[x][i]];
            d[x]++;
        }
    c[x] += 1;
}

int solve(int x, int fa) {
    if (d[x] == 0)
        return 0;
    else if (d[x] == 1)
        return c[x] - 1;
    
    for (int i = 0; i < a[x].size(); ++i) {
        int u = a[x][i];
        if (u != fa) {
            s[u] = solve(u, x);
            tree[x].push_back(c[u] - s[u]);
        }
    }
    sort(tree[x].begin(), tree[x].end());
    
    int last = tree[x].size();
    int left = tree[x][last - 1] + tree[x][last - 2];
    
    return c[x] - left - 1;
}

void work() {
    for (int i = 0; i < n; ++i) {
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        memset(s, 0, sizeof(s));
        memset(tree, 0, sizeof(tree));
        dfs(i, -1);
        int cur = solve(i, -1);
        if (cur < ans)
            ans = cur;
    }
}

void output(int k) {
    printf("Case #%d: %d\n", k, ans);
}

int main() {
    freopen("/Users/dong/Dropbox/Coding/Topcoder/Topcoder/B-large.in", "r", stdin);
    freopen("/Users/dong/Dropbox/Coding/Topcoder/Topcoder/out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        init();
        work();
        output(i + 1);
    }
    return 0;
}