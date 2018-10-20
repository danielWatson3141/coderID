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

const int maxn = 205;

typedef long long ll;

ll dev[maxn], let[maxn];
int n, l;

int score(int a, int b)
{
    ll chg = dev[a] ^ let[b];

    map<ll, int> avail;
    for (int i = 0; i < n; ++i)
        ++avail[let[i] ^ chg];

    for (int i = 0; i < n; ++i)
    {
        if (avail[dev[i]])
            --avail[dev[i]];
        else
            return 1<<30;
    }
    int ans = 0;
    for (int i = 0; i < l; ++i)
        ans += (chg>>i)&1;
    return ans;
}

void solve()
{
    cin >> n >> l;

    memset(let, 0, sizeof let);
    memset(dev, 0, sizeof dev);

    for (int e = 0; e < 2; ++e)
    {
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            for (size_t j = 0; j < s.size(); ++j)
            {
                (e ? let : dev)[i] *= 2;
                (e ? let : dev)[i] += s[j] - '0';
            }

        }
    }

    int ans = 1<<30;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans = min(ans, score(i, j));
    if (ans == 1<<30)
        cout << "NOT POSSIBLE\n";
    else
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
    }

	timestamp(end);
	return 0;
}

