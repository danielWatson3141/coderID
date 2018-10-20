#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

#define MAX 1024
#define INF 1000000
#define X first
#define Y second

using namespace std;

typedef pair<int, int> Pii;

struct Edge {
    int ed, nxt;
} edge[MAX << 1];

int head[MAX], nEdge;
int dp[MAX][3], sum[MAX];

void init() {
    memset(head, -1, sizeof(head));
    nEdge = 0;
}

void addEdge(int a, int b) {
    edge[nEdge].ed = b; edge[nEdge].nxt = head[a]; head[a] = nEdge++;
    edge[nEdge].ed = a; edge[nEdge].nxt = head[b]; head[b] = nEdge++;
}

void dfs(int x, int pre) {
    int i, j, y, deg = 0, d, cnt, *vx = new int[MAX];
    Pii *cur = new Pii[MAX];

    sum[x] = 1; dp[x][0] = 0; dp[x][1] = INF; dp[x][2] = INF;
    for (i = head[x]; ~i; i = edge[i].nxt) {
        if ((y = edge[i].ed) != pre) {
            dfs(y, x); sum[x] += sum[y];
            vx[deg] = y; cur[deg++] = make_pair(dp[y][0] - sum[y], y);
        }
    }

    sort(cur, cur + deg);

    dp[x][0] = sum[x] - 1;
    if (deg > 1) dp[x][0] += cur[0].X + cur[1].X;

    if (deg > 0) dp[x][1] = min(dp[x][1], sum[x] - 1 + cur[0].X);
    if (deg > 1) {
        for (i = 0; i < deg; ++i) {
            d = sum[x] - 1 - sum[vx[i]] + dp[vx[i]][1];
            d += (cur[0].Y == vx[i] ? cur[1].X : cur[0].X);
            dp[x][1] = min(dp[x][1], d);
        }
    }
    dp[x][2] = sum[x] - 1;
    if (deg > 0) {
        for (i = 0; i < deg; ++i) {
            dp[x][2] = min(dp[x][2], sum[x] - 1 + dp[vx[i]][1] - sum[vx[i]]);
        }
    }
    if (deg > 1) dp[x][2] = min(dp[x][2], sum[x] - 1 + cur[0].X + cur[1].X);
    if (deg > 2) {
        for (i = 0; i < deg; ++i) {
            d = sum[x] - 1 - sum[vx[i]] + dp[vx[i]][1];
            for (cnt = j = 0; j < deg && cnt < 2; ++j) {
                if (cur[j].Y == vx[i]) continue;
                d += cur[j].X; ++cnt;
            }
            dp[x][2] = min(dp[x][2], d);
        }
    }

    delete[] cur;
    delete[] vx;

    //printf("x = %d, deg = %d, sum = %d, dp = [%d, %d, %d]\n", x + 1, deg, sum[x], dp[x][0], dp[x][1], dp[x][2]);

    //getchar();
}

int main() {
    int t, ct = 0, n, x, y, i, ans;

    freopen("B-large.in", "r", stdin);
    freopen("B-large1.out", "w", stdout);

    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d", &n);
        for (i = 1; i < n; ++i) {
            scanf("%d%d", &x, &y);
            addEdge(x - 1, y - 1);
        }
        dfs(0, -1);
        for (ans = n, i = 0; i < n; ++i) {
            ans = min(ans, dp[i][2] + sum[0] - sum[i]);
        }
        printf("Case #%d: %d\n", ++ct, ans);
    }

    return 0;
}
