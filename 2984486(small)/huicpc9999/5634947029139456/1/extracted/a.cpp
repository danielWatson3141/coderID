#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int cas = 1;
int n, l;
unsigned int init[2000], want[2000];
char line[500];
set<unsigned int> st;
unsigned int getNum()
{
    scanf("%s", line);
    unsigned int res = 0;
    int len = strlen(line);
    for (int i = 0; i < len; ++i)
    {
        res <<= 1;
        if (line[i] == '1') res |= 1;
    }
    return res;
}

bool flag[20000];
int judge(unsigned int mask)
{

    for (int i = 0; i < n; ++i)
    {
        unsigned int tmp = init[i] ^ mask;
        if (st.find(tmp) == st.end()) return l + 1;
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
    //printf("%d %d", n, l);
    for (int i = 0; i < n; ++i) init[i] = getNum();
    for (int i = 0; i < n; ++i) want[i] = getNum();
    st.clear();
    for (int i = 0; i < n; ++i) st.insert(want[i]);
    int ans = l + 1;
    for (int i = 0; i < n; ++i)
    {
        unsigned int mask = want[0] ^ init[i];
        ans = min(ans, judge(mask));
    }
    return ans;
}
int main()
{
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    int T; scanf("%d", &T);
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




























