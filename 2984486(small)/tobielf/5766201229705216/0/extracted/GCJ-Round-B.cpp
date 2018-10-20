#include <stdio.h>
#include <string.h>

#define SIZE 1010

bool G[SIZE][SIZE];
int T;
int N;
int ans;
int max_nodes;

int make_tree(int root) {
    int cnt = 0;
    int res = 1;
    for (int i = 0; i < N; ++i) {
        if (G[root][i]) {
            G[root][i] = G[i][root] = 0;
            for (int j = i; j < N; ++j) {
                if (G[root][j]) {
                    G[root][j] = G[j][root] = 0;
                    cnt = make_tree(i) + make_tree(j) + 1;
                    if (cnt > res)
                        res = cnt;
                    G[root][j] = G[j][root] = 1;
                }
            }
            G[root][i] = G[i][root] = 1;
        }
    }
    return res;
}

int
main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int x, y;
        printf("Case #%d: ", t);
        scanf("%d", &N);
        memset(G, 0, sizeof(G));
        max_nodes = 0;
        for (int i = 0; i < N - 1; ++i) {
            scanf("%d %d", &x, &y);
            G[x-1][y-1] = G[y-1][x-1] = 1;
        }

        for (int i = 0; i < N; ++i) {
            ans = make_tree(i);
            if (ans > max_nodes)
                max_nodes = ans;
        }

        printf("%d\n", N - max_nodes);
    }
    return 0;
}
