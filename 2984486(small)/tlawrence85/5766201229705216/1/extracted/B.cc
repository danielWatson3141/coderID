#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>
#include <functional>

using namespace std;

int nodes;

vector<int> edges[1000];
int degree[1000];
int ans[1000][1001];
int cost[1000][1001];

int getCost(int root, int from) {
    if (cost[root][from] != -1) return cost[root][from];

    if (degree[root] == 1) cost[root][from] = 1;
    else {
        cost[root][from] = 1;
        for (int other : edges[root]) {
            if (other == from) continue;
            cost[root][from] += getCost(other, root);
        }
    }

    //printf("cost %d %d = %d\n", root, from, cost[root][from]);
    return cost[root][from];
}

int solver(int root, int from) {
    if (ans[root][from] != -1) return ans[root][from];

    ans[root][from] = 1000;

    if (from == 1000) {
        if (degree[root] == 1) {
            ans[root][from] = getCost(edges[root][0], root);
        } else if (degree[root] == 2) {
            int cost1 = 0;  // cost to fix child
            int cost2 = 0;  // cost to prune children
            for (int other : edges[root]) {
                cost1 += solver(other, root);
                cost2 += getCost(other, root);
            }
            ans[root][from] = cost1 < cost2 ? cost1 : cost2;
        } else if (degree[root] >= 3) {
            int totalCost = 0;
            vector<int> diffs;

            for (int other : edges[root]) {
                int solveCost = solver(other, root);
                int pruneCost = getCost(other, root);

                totalCost += pruneCost;
                diffs.push_back(pruneCost - solveCost);
            }

            std::sort(diffs.begin(), diffs.end(), std::greater<int>());

            ans[root][from] = totalCost - diffs[0] - diffs[1];
        }
    } else if (degree[root] == 2) {
        for (int other : edges[root]) {
            if (other == from) continue;
            ans[root][from] = getCost(other, root);
        }
    } else if (degree[root] == 3) {
        int cost1 = 0;  // cost to fix child
        int cost2 = 0;  // cost to prune children
        for (int other : edges[root]) {
            if (other == from) continue;
            cost1 += solver(other, root);
            cost2 += getCost(other, root);
        }
        ans[root][from] = cost1 < cost2 ? cost1 : cost2;
    } else if (degree[root] > 3) {
        int totalCost = 0;
        vector<int> diffs;

        for (int other : edges[root]) {
            if (other == from) continue;
            int solveCost = solver(other, root);
            int pruneCost = getCost(other, root);

            totalCost += pruneCost;
            diffs.push_back(pruneCost - solveCost);
        }

        std::sort(diffs.begin(), diffs.end(), std::greater<int>());

        ans[root][from] = totalCost - diffs[0] - diffs[1];
    } else if (degree[root] == 1) {
        ans[root][from] = 0;
    }

    //printf("ans %d %d %d\n", root, from, ans[root][from]);
    return ans[root][from];
}

void solve(int caseN)
{
    for (int i = 0; i < 1000; ++i) edges[i].clear();
    memset(ans, -1, sizeof(ans));
    memset(cost, -1, sizeof(cost));
    memset(degree, 0, sizeof(degree));

    scanf("%d", &nodes);
    for (int i = 0; i < nodes - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    int best = nodes - 1;
    
    for (int root = 0; root < nodes; ++root) {
        int soln = solver(root, 1000);
        if (soln < best) {
            best = soln;
            //printf("best %d %d\n", best, root);
        }
    }

    printf("Case #%d: %d\n", caseN, best);
}

int main(void)
{
    int nC;
    scanf("%d", &nC);
    for (int cC = 0; cC < nC; ++cC) {
        solve(cC + 1);
    }

    return 0;
}
