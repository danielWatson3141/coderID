#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1024

int N, s[MAXN];

struct node {
    int p, val;
    vector<int> c;
} n[MAXN];

void dfs(int cur, int p) {
    n[cur].p = p;
    for (int i=0; i<(int)n[cur].c.size(); i++) {
        int next = n[cur].c[i];
        if (next == p) continue;
        dfs(next, cur);
    }
}

void dfs2(int cur) {
    int i, next, best[2];

    best[0] = best[1] = 0;
    for (i=0; i<(int)n[cur].c.size(); i++) {
        next = n[cur].c[i];
        if (next == n[cur].p) continue;

        dfs2(next);
        if (n[next].val > best[0]) { swap(best[0], best[1]); best[0] = n[next].val; }
        else best[1] = max(best[1], n[next].val);
    }
    if (best[0] && best[1]) n[cur].val = best[0]+best[1]+1;
    else n[cur].val = 1;
}

int main() {
    int T, t, i, a, b, BEST;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> N;
        for (i=1; i<=N; i++) n[i].c.clear();

        for (i=0; i<N-1; i++) {
            cin >> a >> b;
            n[a].c.push_back(b);
            n[b].c.push_back(a);
        }

        BEST = N-1;
        for (i=1; i<=N; i++) {
            dfs(i, -1); dfs2(i);
            BEST = min(BEST, N-n[i].val);
        }
        cout << "Case #" << t << ": " << BEST << endl;
    }

    return 0;
}
