#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <cstring>
#include <ext/rope>
#include <iterator>

using namespace std;
using namespace __gnu_cxx;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz size
#define scf scanf
#define prf printf
#define prev(x) (x/2)
#define left(x) (x*2)
#define right(x) (x*2+1)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define gcd(a,b) __gcd(a,b)
#define getBit(x,i) ((x&(1<<i))!=0 ? 1 : 0)
#define For(i,n) for (int i = 0; i < n; ++i)
#define FOR(i,begin,end,move) for (int i = begin; i <= end; i += move)

typedef long long ll;

const ll base = 1000000007LL;
const ll INF = 10000000000000LL;

int ans = 0;
int n, l;
vector < int > g[101];
bool used[1001] = {false};
bool visit[1001] = {false};
int st[1001] = {0};

void go(int ver, int prev)
{
    visit[ver] = true;
    For(i,g[ver].size())
    {
        int to = g[ver][i];
        if (to == prev || used[to] == true)
            continue;
        else{
            st[ver]++;
            go(to, ver);
        }
    }
}

bool check(int root, int all)
{
    fill(st, st + n, 0);
    fill(visit, visit + n, false);
    go(root, -1);
    int tr = 0;
    For(i,n)
        if (visit[i] == true)
            tr++;
    if (tr != all)
        return false;
    For(i,n)
        if (st[i] != 2 && st[i] != 0)
            return false;
    return true;
}

void dfs(int cnt, int del)
{
    if (cnt == n)
    {
        For(i,n)
            if (used[i] == false)
            {
                bool f = check(i, n - del);
                if (f)
                {
                    ans = min(ans, del);
                    break;
                }
            }
            return;
    }
    used[cnt] = true;
    dfs(cnt + 1, del + 1);
    used[cnt] = false;
    dfs(cnt + 1, del);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scf("%d", &t);
    For(q,t)
    {
        scanf("%d", &n);
        For(i,n)
            g[i].clear();
        For(i,n - 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            --x;--y;
            g[x].pb(y);
            g[y].pb(x);
        }
        ans = n + 1;
        dfs(0, 0);
        printf("Case #%d: %d\n", q + 1, ans);
    }
    return 0;
}
