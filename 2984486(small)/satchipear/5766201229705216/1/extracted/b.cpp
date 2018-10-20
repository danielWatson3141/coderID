#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
const int k_maxn = 1111;
vector<int> nxt[k_maxn];
int ans;
int n;
int cut_cost[k_maxn];
int pick_cost[k_maxn];
bool mark[k_maxn];

void dfs(int x) {
    int best1 = -1;
    int best2 = -1;

    mark[x] = true;
    for (int y : nxt[x]) {
        if (!mark[y]) {
            dfs(y);

            cut_cost[x] += cut_cost[y];
            int gain =  cut_cost[y] - pick_cost[y];
            if (gain > best1) {
                best2 = best1;
                best1 = gain;
            } else if (gain > best2) {
                best2 = gain;
            }
        }
    }

    pick_cost[x] = cut_cost[x];
    if (best1 > -1 && best2 > -1) {
        pick_cost[x] -= best1 + best2;
    }

    cut_cost[x]++;
}

void print_debug() {
    printf("\n---begin------\n");
    for (int i = 0; i < n; i++) {
        printf("%d: pick: %d, cut: %d\n", i, pick_cost[i], cut_cost[i]);
    }
    printf("---end------\n");
}

void try_it(int root) {
    memset(mark, false, sizeof(mark));
    memset(cut_cost, 0, sizeof(cut_cost));
    memset(pick_cost, 0, sizeof(pick_cost));
    dfs(root);
    if (pick_cost[root] < ans) {
        //print_debug();
        ans = pick_cost[root];
    }
}

int main() {
    int tn;
    scanf("%d", &tn);
    for (int cn = 1; cn <= tn; cn++) {
        printf("Case #%d: ", cn);

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            nxt[i].clear();
        }
        
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            nxt[x].push_back(y);
            nxt[y].push_back(x);
        }

        ans = n - 1;
        for (int i = 0; i < n; i++) {
            try_it(i);
        }

        printf("%d\n", ans);
    }
    return 0;
}
