#include <cstdio>

const int MAXN = 1010;

int adj[MAXN][MAXN], deg[MAXN];

int dfs(int root, int prev) {
    int first = 0, second = 0;
    
    for (int i = 0; i < deg[root]; i++) {
        int v = adj[root][i];
        if (v == prev) continue;
        int d = dfs(v, root);
        if (d > first) {
            second = first;
            first = d;
        } else if (d > second) {
            second = d;
        }
    }
    
    if (second == 0) return 1;
    
    return first + second + 1;
}

int main() {
    int ntests;
    scanf("%d", &ntests);
    
    for (int test = 1; test <= ntests; test++) {
        int N;
        scanf("%d", &N);
        
        for (int i = 1; i <= N; i++) deg[i] = 0;

        int a, b;
        for (int i = 0; i < N - 1; i++) {
            scanf("%d %d", &a, &b);
            adj[a][deg[a]++] = b;
            adj[b][deg[b]++] = a;
        }
        
        int m = 0;
        for (int i = 1; i <= N; i++) {
            int d = dfs(i, -1);
            if (d > m) m = d;
        }
        
        printf("Case #%d: %d\n", test, N - m);
    }
    
    return 0;
}
