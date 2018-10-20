#include <cstdio>
#include <algorithm>
using namespace std;
int T, n, len, ans, c[55];
char a[222][55], b[222][55];
long long u[222], v[222];


bool check()
{
    for (int j = 0; j < len; j++)
        if (c[j])
        {
            for (int i = 0; i < n; i++)
                a[i][j] += (a[i][j] == '0') - (a[i][j] == '1');
        }
    for (int i = 0; i < n; i++)
    {
        u[i] = 0;
        for (int j = 0; j <len; j++)
            u[i] = u[i] * 2 + (a[i][j] == '1');
    }
    sort(u, u + n);
    for (int j = 0; j < len; j++)
        if (c[j])
        {
            for (int i = 0; i < n; i++)
                a[i][j] += (a[i][j] == '0') - (a[i][j] == '1');
        }
    for (int i = 0; i < n; i++)
        if (u[i] != v[i])
            return false;
    return true;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++)
    {
        scanf("%d%d", &n, &len);
        for (int i = 0; i < n; i++)
            scanf("%s", a[i]);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", b[i]);
            v[i] = 0;
            for (int j = 0; j < len; j++)
                v[i] = v[i] * 2 + (b[i][j] == '1');
        }
        sort(v, v + n);
        ans = len + 1;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < len; j++)
            {
                c[j] = (a[0][j] != b[i][j]);
                sum += c[j];
            }
            if (sum < ans && check())
                ans = sum;
        }
        printf("Case #%d: ", tt + 1);
        printf(ans > len ? "NOT POSSIBLE\n" : "%d\n", ans);
    }
    return 0;
}
