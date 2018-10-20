// Jason Lau
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

void process(void);

int main(void) {
    process();
    return 0;
}

int processOne(void);

void process(void) {
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %d\n", i, processOne());
    }
}

const int MAXN = 2000;

struct link {
    int to;
    link *next;
} cache[2*(MAXN+1)];

link *newLink(int to, link *next, int &ce) {
    cache[ce].to = to; cache[ce].next = next;
    return &cache[ce++];
}

pair<int, int> fetchMinDelete(link *gr[], int root, int pre);

int processOne(void) {
    link *gr[MAXN] = {NULL};
    int n; scanf("%d", &n);
    int cacheEnd = 0;
    for (int i = 1; i < n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        gr[a] = newLink(b, gr[a], cacheEnd);
        gr[b] = newLink(a, gr[b], cacheEnd);
    }
    int minDelete = n;
    for (int i = 1; i <= n; i++) {
        minDelete = min(minDelete, fetchMinDelete(gr, i, -1).first);
    }
    return minDelete;
}

pair<int, int> fetchMinDelete(link *gr[], int root, int pre) {
    int DP[3] = {0, MAXN, MAXN};
    for (link *i = gr[root]; i; i = i->next) {
        if (i->to == pre) continue;
        pair<int, int> cost = fetchMinDelete(gr, i->to, root);
        int remainCost = cost.first;
        int deleteCost = cost.second;
        int newDP[3] = {MAXN, MAXN, MAXN};
        for (int i = 0; i < 3; i++) {
            newDP[i] = min(newDP[i], DP[i] + deleteCost);
            if (i) newDP[i] = min(newDP[i], DP[i - 1] + remainCost);
        }
        for (int i = 0; i < 3; i++) {
            DP[i] = newDP[i];
        }
    }
    return make_pair(min(DP[0], DP[2]), 1 + DP[0]);
}
