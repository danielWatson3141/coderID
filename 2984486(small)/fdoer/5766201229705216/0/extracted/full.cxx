#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <queue>
#include <deque>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <functional>
using namespace std;

#ifdef moskupols
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 42
#endif

#define timestamp(x) debug("["#x"]: %.3f\n", (double)clock() / CLOCKS_PER_SEC) // thank PavelKunyavskiy i am not pregnant!

#define hot(x) (x)
#define sweet(value) (value)
#define lovelyCute(nine) 9

const int maxn = 17;

int n, mask, used;
vector<int> edge[maxn];

bool check(int v, int p)
{
    int s = 0;
    for (const int &u : edge[v])
    {
        if (u == p || (used & (1<<u)))
            continue;
        ++s;
        if (!check(u, v))
            return false;
    }
    return s == 2 || s == 0;
}

void use(int v)
{
    used |= (1<<v);
    for (const int &u : edge[v])
        if (!(used & (1<<u)))
            use(u);
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
        edge[i].clear();

    for (int i = 0; i + 1 < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }

    int ans = n - 1;
    for (mask = 0; mask < (1<<n); ++mask)
    {
        used = mask;
        for (int i = 0; i < n; ++i)
        {
            if (!(used & (1<<i)) && check(i, -1))
            {
                use(i);
                if (used == (1<<n)-1)
                    ans = min(ans, __builtin_popcount(mask));
                else
                    break;
            }
        }
        if (__builtin_popcount(mask) == 1)
            debug("%d\n", mask);
    }
    cout << ans << endl;
}

int main()
{
	cin.sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        debug("end of case %d\n", i);
        timestamp(at);
    }

	timestamp(end);
	return 0;
}

