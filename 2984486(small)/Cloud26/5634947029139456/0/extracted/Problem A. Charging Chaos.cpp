#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;


typedef long long LL;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define lson (pos << 1)
#define rson (pos << 1 | 1)

template<class T> void checkMax(T &a, T b){a = max(a, b);}
template<class T> void checkMin(T &a, T b){a = min(a, b);}
const int N = 155;
int n, l;
LL x[N], y[N];
map<LL, int> cnt;
LL strToLL(char str[])
{
    LL ret = 1;
    int j;
    for(j = 0; j < l; j++)
        ret = ret * 2 + str[j] - '0';
    return ret;
}
LL flip(LL val, LL mask)
{
    int i;
    for(i = 0; i < l; i++)
    {
        if((1LL << i) & mask)
        {
            if((1LL << i) & val)    val ^= (1LL << i);
            else                    val |= (1LL << i);
        }
    }
    return val;
}
int bitCount(LL val)
{
    int ret = 0;
    while(val)
    {
        val &= (val - 1);
        ret++;
    }
    return ret;
}
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, cas = 1, i, j;
    char str[N];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &l);
        for(i = 1; i <= n; i++)
        {
            scanf("%s", str);
            x[i] = strToLL(str);
        }
        for(i = 1; i <= n; i++)
        {
            scanf("%s", str);
            y[i] = strToLL(str);
        }
        int ans = INF;
        for(i = 1; i <= n; i++)
        {
            cnt.clear();
            for(j = 1; j <= n; j++)
                cnt[y[j]] = 1;
            LL val = x[1] ^ y[i];
            cnt[y[i]]--;
            for(j = 2; j <= n; j++)
            {
                LL fv = flip(x[j], val);
                if(cnt[fv] == 0)    break;
                    cnt[fv]--;
            }
            if(j == n + 1)
                checkMin(ans, bitCount(val));
        }
        if(ans == INF)  printf("Case #%d: NOT POSSIBLE\n", cas++);
        else            printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
