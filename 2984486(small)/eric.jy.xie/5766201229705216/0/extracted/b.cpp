#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int dfs(vector< vector<int> > &adj, int x, int p) {
    int m1 = 0, m2 = 0;
    for (vector<int>::iterator i = adj[x].begin(); i != adj[x].end(); ++i) {
        if (*i == p) continue;
        int c = dfs(adj, *i, x);
        if (c > m2) {
            m1 = m2;
            m2 = c;
        }else if (c > m1) {
            m1 = c;
        }
    }

    //printf("%d %d %d\n", x, m1, m2);
    if (m1 && m2) 
        return m1 + m2 + 1;
    else
        return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);
        vector< vector<int> > adj(N, vector<int>(0));
        for (int i = 0; i < N-1; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int best = 0;
        for (int i = 0; i < N; i++) {
            //printf("root %d\n", i);
            int c = dfs(adj, i, -1);
            if ( c > best ) {
                best = c;
            }
        }
        printf("Case #%d: %d\n", t+1, N-best);
    }
    return 0;
}
