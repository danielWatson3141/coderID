#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char g[205][505], cg[205][505], used[205][505];
int n, m, white_space;
void wdfs(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m)
        return;
    if(g[x][y] != 0 || used[x][y])
        return;
    used[x][y] = 1, cg[x][y] = 3;
    wdfs(x+1, y);
    wdfs(x-1, y);
    wdfs(x, y+1);
    wdfs(x, y-1);
}
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dfs(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m)
        return;
    if(g[x][y] != 1 || used[x][y])
        return;
    used[x][y] = 1, cg[x][y] = 2;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
    int i, tx, ty;
    for(i = 0; i < 4; i++) {
        tx = x+dx[i], ty = y+dy[i];
        if(tx < 0 || ty < 0 || tx >= n || ty >= m)
            continue;
        if(g[tx][ty] == 0 && used[tx][ty] == 0) {
            white_space++;
            wdfs(tx, ty);
        }
    }
}
void bdfs(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m)
        return;
    if(g[x][y] != 0 || used[x][y])
        return;
    used[x][y] = 1, cg[x][y] = 1;
    bdfs(x, y+1);
    bdfs(x, y-1);
    bdfs(x+1, y+1);
    bdfs(x+1, y);
    bdfs(x+1, y-1);
    bdfs(x-1, y+1);
    bdfs(x-1, y);
    bdfs(x-1, y-1);
}
int main() {
	freopen("in", "r", stdin);
	freopen("out2", "w", stdout);
    int cases = 0, h, w;
    char s[205];
    while(scanf("%d %d", &h, &w) == 2 && w) {
        int i, j, k;
        memset(g, 0, sizeof(g));
        memset(cg, 0, sizeof(cg));
        memset(used, 0, sizeof(used));
        for(i = 1; i <= h; i++) {
            scanf("%s", s+1);
            int idx = 0;
            s[0] = '0';
            s[strlen(s)] = '0';
            s[strlen(s)+1] = '\0';
            for(j = 0; s[j]; j++) {
                int v = s[j] <= '9' ? (s[j]-'0') : (s[j]-'a'+10);
                for(k = 3; k >= 0; k--)
                    g[i][idx++] = (v>>k)&1;
            }
        }
        n = h+2, m = w*4+8;
        bdfs(0, 0);//bound color
        char ret[1005];
        int retidx = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(g[i][j] == 1 && used[i][j] == 0) {
                    white_space = 0;
                    dfs(i, j);
                    switch(white_space) {
                        case 0:ret[retidx++] = 'W';break;
                        case 1:ret[retidx++] = 'A';break;
                        case 2:ret[retidx++] = 'K';break;
                        case 3:ret[retidx++] = 'J';break;
                        case 4:ret[retidx++] = 'S';break;
                        case 5:ret[retidx++] = 'D';break;
                    }
                }
            }
        }
        sort(ret, ret+retidx);
        printf("Case %d: ", ++cases);
        for(i = 0; i < retidx; i++)
            putchar(ret[i]);
        puts("");
        /*for(i = 0; i < h; i++, puts("")) {
            for(j = 0; j < 4*w+4; j++)
                printf("%d", g[i][j]);
        }*/
    }
    return 0;
}
 