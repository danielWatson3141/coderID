#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define NUM 155
#define LEN 45

char a[NUM][LEN], b[NUM][LEN], c[NUM][LEN];
bool u[NUM];
int T, N, L, ans;

int cmp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

void dfs(int d, int w)
{
    if (w >= ans)
        return;
    if (d >= L)
    {
        for (int i = 1; i <= N; i++)
        {
            strcpy(c[i], a[i]);
            for (int j = 0; j < L; j++)
                if (u[j])
                    c[i][j] = (c[i][j] == '0') ? '1' : '0';
        }
        qsort(c + 1, N, sizeof(c[1]), cmp);
        bool ok = true;
        for (int i = 1; i <= N; i++)
            if (strcmp(c[i], b[i]))
            {
                ok = false;
                break;
            }
        if (ok)
            ans = w;
        return;
    }
    u[d] = false;
    dfs(d + 1, w);
    u[d] = true;
    dfs(d + 1, w + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int x = 1; x <= T; x++)
    {
        scanf("%d%d", &N, &L);
        for (int i = 1; i <= N; i++)
            scanf("%s", a[i]);
        for (int i = 1; i <= N; i++)
            scanf("%s", b[i]);
        qsort(b + 1, N, sizeof(b[1]), cmp);
        ans = L + 1;
        memset(u, false, sizeof(u));
        dfs(0, 0);
        printf("Case #%d: ", x);
        if (ans > L)
            puts("NOT POSSIBLE");
        else
            printf("%d\n", ans);
    }
    return 0;
}

