#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

int T, N;
int g[1100][1100];
int child[1100][1100];
bool used[1100];

int dfs(int x)
{
    used[x] = true;
    child[x][0] = 0;
    for (int i = 1; i <= g[x][0]; i++) {
        int y = g[x][i];
        if (!used[y]) {
            child[x][++child[x][0]] = dfs(y);
       //     printf("%d ", child[x][child[x][0]]);
        }
    }
  //  printf("\n");
    if (child[x][0] == 0) return 1;
    if (child[x][0] == 1) return 1;
    if (child[x][0] == 2) return child[x][1] + child[x][2] + 1;
    int m1 = 0, m2 = 0;
    for (int i = 1; i <= child[x][0]; i++) {
        if (child[x][i] > m1) {
            if (m1 > m2) {
                m2 = m1;
                m1 = child[x][i];
            }
            else {
                m1 = child[x][i];
            }
        }
        else if (child[x][i] > m2) {
            m2 = child[x][i];
        }
    }
  //  printf("m1 %d m2 %d\n", m1, m2);
    return m1 + m2 + 1;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt1.in", "r", stdin);
    //freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);
    
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d", &N);
        memset(g, 0, sizeof(g));
       // printf("N = %d\n", n);
        int a, b;
        for (int i = 0; i < N - 1; i++) {
            scanf("%d %d", &a, &b);
            a--; b--;
            g[a][++g[a][0]] = b;
            g[b][++g[b][0]] = a;
        }
        
            int ans = 0;
            for (int i = 0; i < N; i++) {
                memset(used, false, sizeof(used));
     //           printf("root: %d\n", i);
                int cur = dfs(i);
                
                ans = max(ans, cur);
            }
        printf("%d\n", N - ans);
    }
    return 0;
}