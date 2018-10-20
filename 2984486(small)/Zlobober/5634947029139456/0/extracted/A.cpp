#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 200;

char buf[N];
int msk1[N], msk2[N];
int q[N];

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
            msk1[i] = msk1[i] * 2 + (buf[j] == '1');
    }
    for (int i = 0; i < n; i++)
    {
        scanf(" %s ", buf);
        for (int j = 0; j < l; j++)
            msk2[i] = msk2[i] * 2 + (buf[j] == '1');
    }
    sort(msk2, msk2 + n);
    int ans = N;
    for (int msk = 0; msk < (1 << l); msk++)
    {
        for (int i = 0; i < n; i++)
            q[i] = msk1[i] ^ msk;
        sort(q, q + n);
        bool eq = true;
        for (int i = 0; i < n; i++)
            eq &= q[i] == msk2[i];
        if (eq)
            ans = min(ans, __builtin_popcount(msk));
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
