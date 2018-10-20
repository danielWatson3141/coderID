#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int kMaxN = 1000 + 10;

int n;
vector<int> adj[kMaxN];

int solve(int x, int parent) {
    int ans = 1;  // delete every children
    int maxC1 = -1, maxC2 = -1;
    for (vector<int>::iterator iter = adj[x].begin(); iter != adj[x].end(); ++iter) {
        int y = *iter;
        if (y == parent)
            continue;
        int cCnt = solve(y, x);
        if (cCnt > maxC1) {
            maxC2 = maxC1;
            maxC1 = cCnt;
        } else if (cCnt > maxC2) {
            maxC2 = cCnt;
        }
    }
    if (maxC2 != -1)
        ans = max(ans, 1 + maxC1 + maxC2);
    return ans;
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        adj[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    int ans = n - 1;
    for (int i = 0; i < n; ++i)
        ans = min(ans, n - solve(i, -1));
    printf("%d\n", ans);
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    for (int caseNo = 1; caseNo <= numCases; ++caseNo) {
        printf("Case #%d: ", caseNo);
        solve();
    }
    return 0;
}
