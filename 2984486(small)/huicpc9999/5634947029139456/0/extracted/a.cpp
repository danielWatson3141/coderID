#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, l;
unsigned int init[200], want[200];

unsigned int getNum()
{
    char line[50]; scanf("%s", line);
    unsigned int res = 0;
    int len = strlen(line);
    for (int i = 0; i < len; ++i)
    {
        res <<= 1;
        if (line[i] == '1') res |= 1;
    }
    return res;
}

bool flag[2000];
int judge(unsigned int mask)
{
    for (int i = 0; i < n; ++i)
    {
        unsigned int tmp = init[i] ^ mask;
        if (flag[tmp] == false) return l + 1;
    }
    int res = 0;
    while (mask)
    {
        if (mask & 1) res++;
        mask >>= 1;
    }
    return res;
}
int solve()
{
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; ++i) init[i] = getNum();
    for (int i = 0; i < n; ++i) want[i] = getNum();
    int ed = 1 << l;
    int ans = l + 1;
    for (int i = 0; i < ed; ++i) flag[i] = false;
    for (int i = 0; i < n; ++i) flag[want[i]] = true;
    for (unsigned int i = 0; i < ed; ++i)
    {
        ans = min(ans, judge(i));
    }
    return ans;
}
int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    //cout << "hello world" << endl;
    int T; scanf("%d", &T);
    int cas = 1;

    while (T--)
    {
        int res = solve();
        if (res <= l)
            printf("Case #%d: %d\n", cas++, res);
        else
            printf("Case #%d: NOT POSSIBLE\n", cas++);
    }
    return 0;
}




























