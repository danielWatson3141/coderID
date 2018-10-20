#include <cstdio>
#include <vector>

const int MAXN = 1000;

std :: vector <int> graph[MAXN];

int dfs(int u, int fu) {
    int max1 = -1, max2 = -2;
    for (int v : graph[u]) 
        if (v != fu) {
            int temp = dfs(v, u);
            if (temp > max1) {
                max2 = max1;
                max1 = temp;
            } else if (temp > max2)
                max2 = temp;
        }
    if (max2 > 0)
        return 1 + max1 + max2;
    else
        return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++ cas) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i)
            graph[i].clear();
        for (int i = 1; i < n; ++ i) {
            int u, v;
            scanf("%d%d", &u, &v);
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        int ans = n;
        for (int i = 0; i < n; ++ i)
            ans = std :: min(ans, n - dfs(i, i));
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
