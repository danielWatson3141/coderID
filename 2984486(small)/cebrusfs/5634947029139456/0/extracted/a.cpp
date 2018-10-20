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

#define MAX 55

ll strToLL(char str[], int m)
{
    ll val = 0;
    for (int i = 0; i < m; ++i)
        val |= (str[i] - '0') * (1LL << i);
    return val;
}
int main()
{
    int z;
    scanf("%d", &z);

    for (int zi = 1; zi <= z; ++zi)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        vector<ll> va, vb; 
        for (int i = 0; i < n; ++i)
        {
            char str[MAX];
            scanf("%s", str);
            ll val = strToLL(str, m);
            va.PB(val);
        }
        for (int i = 0; i < n; ++i)
        {
            char str[MAX];
            scanf("%s", str);
            ll val = strToLL(str, m);
            vb.PB(val);
        }

        unordered_map<ll, int> mp;
        for (ll a : va)
            for (ll b : vb)
                mp[a ^ b]++;

        int ans = INT_MAX;
        for (const auto& p : mp)
        {
            if (p.second != n) continue;

            ll mask = p.first;
            int ct = 0;
            for (int i = 0; i < m; ++i)
                if (mask & (1LL << i)) ct++;

            ans = min(ans, ct);
        }
        printf("Case #%d: ", zi);
        if (ans == INT_MAX)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", ans);
    }
}

