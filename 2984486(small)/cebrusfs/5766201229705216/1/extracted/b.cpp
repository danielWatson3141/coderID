// macros {{{
#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define BIT(n) ((1LL) << (long long)(n))
#define FOR(i,c) for (auto i=(c).begin(); i != (c).end(); ++i)
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define REP1(i,a,b) for (int i=(int)(a); i <= (int)(b); ++i)
#define MP make_pair
#define PB push_back

#define Fst first
#define Snd second

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define MAX 1005

int n;
vector<int> e[MAX];

int sum[MAX];
int cost[MAX];
bool vis[MAX];


int dfs(int now)
{
    vis[now] = true;

    sum[now] = 1;

    vector<int> vec;

    int ans = 0;
    for (int b : e[now])
    {
        if (vis[b]) continue;

        int ca = dfs(b);
        int cb = sum[b];

        sum[now] += sum[b];

        vec.PB(ca - cb);
        ans += cb;
    }

    // 2
    if (SZ(vec) >= 2)
    {
        sort(ALL(vec));
        ans += vec[0];
        ans += vec[1];
    }
    return ans;
}

int solve(int root)
{
    memset(vis, 0, sizeof(vis));
    return dfs(root);
}



int main()
{
    int z;
    scanf("%d", &z);
    for (int zi = 1; zi <= z; ++zi)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
            e[i].clear();

        for (int i = 1; i < n; ++i)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            --a, --b;

            e[a].PB(b);
            e[b].PB(a);
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
            ans = min(ans,solve(i));

        printf("Case #%d: %d\n", zi, ans);
    }
}

