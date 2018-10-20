#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 200
#define MAXL 50
#define INF 0x3f3f3f3f

int T, N, L;
char s1[MAXN][MAXL], s2[MAXN][MAXL];
bool marked[MAXL], flag[MAXN];

void change() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < L; j++)
            if (marked[j])
                s1[i][j] = s1[i][j] == '0' ? '1' : '0';
}

bool check(int i) {
    memset(flag, 0, sizeof(flag));
    flag[i] = 1;
    for (int k = 1; k < N; k++) {
        bool ok = 0;
        for (int l = 0; l < N; l++) {
            if (!flag[l] && strcmp(s2[k], s1[l]) == 0) {
                flag[l] = 1;
                ok = 1;
                break;
            }
        }
        if (!ok)
            return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &L);
        for (int i = 0; i < N; i++)
            scanf("%s", s1[i]);
        for (int i = 0; i < N; i++)
            scanf("%s", s2[i]);

        int ans = INF;
        for (int i = 0; i < N; i++) {
            int cnt = 0;
            memset(marked, 0, sizeof(marked));
            for (int j = 0; j < L; j++)
                if (s2[0][j] != s1[i][j])
                    marked[j] = 1, cnt++;
            change();
            if (check(i))
                ans = min(ans, cnt);
            change();
        }

        if (ans != INF)
            printf("Case #%d: %d\n", t, ans);
        else
            printf("Case #%d: NOT POSSIBLE\n", t);
    }
}
