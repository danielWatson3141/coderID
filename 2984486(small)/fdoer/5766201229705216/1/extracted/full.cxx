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

const int maxn = 1005;

int n;
vector<int> edge[maxn];

int cnt[maxn];

void makeCnt(int v, int p)
{
    cnt[v] = 1;
    for (int u : edge[v])
        if (u != p)
        {
            makeCnt(u, v);
            cnt[v] += cnt[u];
        }
}

int dp[maxn];

void makeDP(int v, int p)
{
    vector<pair<int, int>> s;
    int sumcnt = 0;
    for (int u : edge[v])
        if (u != p)
        {
            makeDP(u, v);
            s.emplace_back(dp[u], cnt[u]);
            sumcnt += cnt[u];
        }
    if (s.empty())
        return (void)(dp[v] = 0);
    if (s.size() == 1)
        return (void)(dp[v] = s[0].second);
    dp[v] = 1 << 30;
    for (size_t i = 0; i < s.size(); ++i)
        for (size_t j = i + 1; j < s.size(); ++j)
            dp[v] = min(dp[v], s[i].first + s[j].first + sumcnt - s[i].second - s[j].second);
}

int score(int root)
{
    makeCnt(root, -1);
    makeDP(root, -1);
    return dp[root];
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
    for (int i = 0; i < n; ++i)
        ans = min(ans, score(i));
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

