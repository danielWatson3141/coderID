#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

bool visited[16];
int t, n, counter, len[16], children[16], ar[16][16];

void dfs(int i, int bitmask){
    counter++;
    visited[i] = true;

    int j, x;
    for (j = 0; j < len[i]; j++){
        x = ar[i][j];
        if (!visited[x] && !(bitmask & (1 << x))){
            children[i]++;
            dfs(x, bitmask);
        }
    }
}

int main(){
    int T = 0, i, j, a, b, r, bitmask;

    scanf("%d", &t);
    while (t--){
        clr(len);
        scanf("%d", &n);
        for (i = 1; i < n; i++){
            scanf("%d %d", &a, &b);
            a--, b--;
            ar[a][len[a]++] = b;
            ar[b][len[b]++] = a;
        }

        int res = 10000, lim = (1 << n) - 1;
        for (bitmask = 0; bitmask <= lim; bitmask++){
            for (r = 0; r < n; r++){
                if (!(bitmask & (1 << r))){
                    counter = 0;
                    clr(visited), clr(children);
                    dfs(r, bitmask);
                    if (counter == (n - __builtin_popcount(bitmask))){
                        bool flag = true;
                        for (i = 0; i < n; i++){
                            if (visited[i]){
                                if (!(children[i] == 0 || children[i] == 2)){
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        if (flag && __builtin_popcount(bitmask) < res) res = __builtin_popcount(bitmask);
                    }
                }
            }
        }

        printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}
