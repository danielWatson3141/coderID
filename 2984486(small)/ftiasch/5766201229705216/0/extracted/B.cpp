#include <cstdio>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>

const int N = 1000;

int n;
std::vector <int> tree[N];

int solve(int p, int u) {
    std::vector <int> children;
    for (int v : tree[u]) {
        if (v != p) {
            children.push_back(solve(u, v));
        }
    }
    std::sort(children.begin(), children.end(), std::greater <int>());
    if ((int)children.size() < 2) {
        return 1;
    }
    return 1 + children[0] + children[1];
}

int main() {
    int tests;
    scanf("%d", &tests);
    for (int t = 1; t <= tests; ++ t) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) {
            tree[i].clear();
        }
        for (int i = 0; i < n - 1; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        int result = 0;
        for (int root = 0; root < n; ++ root) {
            result = std::max(result, solve(-1, root));
        }
        printf("Case #%d: %d\n", t, n - result);
    }
    return 0;
}
