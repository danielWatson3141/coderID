#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = 1111;

int dp[N];
bool u[N];
int cnt[N];
vector<int> g[N];

void dfs1(int v)
{
    u[v] = true;
    cnt[v] = 1;
    for (int to : g[v])
        if (!u[to])
        {
            dfs1(to);
            cnt[v] += cnt[to];
        }
}

void dfs2(int v)
{
    u[v] = true;
    dp[v] = cnt[v] - 1;
    int min1, min2;
    min1 = N;
    min2 = N;
    for (int to : g[v])
    {
        if (u[to])
            continue;
        dfs2(to);
        int c = dp[to] - cnt[to];
        if (c < min1) {
            min2 = min1;
            min1 = c;
        }
        else if (c < min2)
        {
            min2 = c;
        }
    }
    dp[v] = min(dp[v], cnt[v] - 1 + min1 + min2);
}

void solve(int test)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res = N;
    for (int v = 0; v < n; v++)
    {
        fill(u, u + n, false);
        dfs1(v);
        fill(u, u + n, false);
        dfs2(v);
        res = min(res, dp[v]);
    }
    cerr << test << endl;
    cout << "Case #" << test << ": ";
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
        solve(q);

    return 0;
}
