#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 200;

typedef long long llong;

char buf[N];
llong msk1[N], msk2[N];
llong u[N];

void solve(int cs)
{
    int n, l;
    scanf("%d %d", &n, &l);
    memset(msk1, 0, sizeof(msk1));
    memset(msk2, 0, sizeof(msk2));
    for (int i = 0; i < n; i++)
    {
        scanf(" %s ", buf);
        for (int j = 0; j < l; j++)
            msk1[i] = msk1[i] * 2LL + (buf[j] == '1');
    }
    for (int i = 0; i < n; i++)
    {
        scanf(" %s ", buf);
        for (int j = 0; j < l; j++)
            msk2[i] = msk2[i] * 2LL + (buf[j] == '1');
    }
    sort(msk2, msk2 + n);
    int ans = N;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            llong msk = msk1[i] ^ msk2[j];
            for (int k = 0; k < n; k++)
                u[k] = msk1[k] ^ msk;
            sort(u, u + n);
            bool eq = true;
            for (int k = 0; k < n; k++)
                eq &= msk2[k] == u[k];
            if (eq)
                ans = min(ans, __builtin_popcountl(msk));
        }
    if (ans == N)
        printf("Case #%d: NOT POSSIBLE\n", cs);
    else
        printf("Case #%d: %d\n", cs, ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i + 1);
}
