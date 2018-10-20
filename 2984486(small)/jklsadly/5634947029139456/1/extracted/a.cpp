#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
const int maxn = 200;
ll data[maxn], data2[maxn];
char s[100];
int n;
int L;

ll get()
{
    scanf("%s", s);
    //puts(s);
    //return 0;
    ll ans = 0;
    for(int i = 0; s[i]; i++)
        ans = ans * 2 + (s[i] - '0');

    return ans;
}

ll tmp[maxn];
int mycount(ll tp)
{
    int ans = 0;
    while(tp)
        ans += tp & 1, tp>>=1;
    return ans;
}
bool check(ll tp)
{
    for(int i = 0; i < n; i++)
        tmp[i] = tp ^ data[i];
    sort(tmp, tmp + n);
    for(int i = 0; i < n; i++)
        if(tmp[i] != data2[i])
            return false;

    return true;
}
int solve()
{
    int ans = L + 10;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            ll tp = data[i] ^ data2[j];
            int tc = mycount(tp);
            if(tc < ans && check(tp))
                ans = tc;
        }

    if(ans > L) return -1;
    return ans;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("a.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &n, &L);
        for(int i = 0; i < n; i++)
            data[i] = get();
        for(int i = 0; i < n; i++)
            data2[i] = get();

        //printf("{%d}\n", n);
        //continue;
        sort(data2, data2 + n);
        printf("Case #%d: ", cas);
        int ans = solve();
        if(ans < 0)
            puts("NOT POSSIBLE");
        else
            printf("%d\n", ans);
    }
    return 0;
}
