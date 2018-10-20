#include <iostream>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <iomanip>
#include <cstring>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define TR(i, a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)

int n;
vector<int> G[1005];
int f[1005];
bool used[1005];

void dfs(int ind)
{
    used[ind] = true;
    vector<int> fs;
    FOR(i, 0, G[ind].size())
    {
        int v = G[ind][i];
        if(!used[v])
        {
            dfs(v);
            fs.push_back(f[v]);
        }
    }
    if(fs.size() == 0) f[ind] = 1;
    else if(fs.size() == 1) f[ind] = 1;
    else
    {
        sort(fs.rbegin(), fs.rend());
        f[ind] = fs[0] + fs[1] + 1;
    }
}

int get(int root)
{
    memset(used, 0, sizeof(used));
    dfs(root);
    return n - f[root];
}

int solve()
{
    int res = n + 1;
    FOR(i, 1, n + 1) res = min(res, get(i));
    return res;
}

int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int test_cnt;
    cin >> test_cnt;
    FOR(test_ind, 1, test_cnt + 1)
    {
        cin >> n;
        FOR(i, 0, n + 1) G[i] = vector<int>();
        FOR(i, 0, n - 1)
        {
            int v, u;
            cin >> v >> u;
            G[v].push_back(u);
            G[u].push_back(v);
        }
        printf("Case #%d: ", test_ind);
        cout << solve() << endl;
    }
}









