#include <cstdio>

const int maxL = 100;
const int maxN = 200;

typedef long long ll;

ll str2ll(char *s)
{
    ll r = 0;
    while (*s) {
        r *= 2;
        r += *s - '0';
        ++s;
    }
    return r;
}

char tmp[maxL];
ll a[maxN];
ll b[maxN];

const int inf = 1000000000;

int testCase()
{
    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; ++i) {
        scanf("%s", tmp);
        a[i] = str2ll(tmp);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", tmp);
        b[i] = str2ll(tmp);
    }
    //printf("DATA READ\n");
    int best = inf;
    for (int i = 0; i < n; ++i) {
        ll x = a[0] ^ b[i];
        int hereBest = __builtin_popcountll(x);
        for (int j = 1; j < n; ++j) {
            ll d = a[j] ^ x;
            bool ok = false;
            for (int k = 0; k < n; ++k) {
                if (d == b[k]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                hereBest = inf;
                break;
            }
        }
        if (hereBest < best)
            best = hereBest;
    }
    return best;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int r = testCase();
        printf("Case #%d: ", i);
        if (r == inf)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", r);
    }
}