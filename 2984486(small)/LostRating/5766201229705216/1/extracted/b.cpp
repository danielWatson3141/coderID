#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long int64;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

#define x first
#define y second

const int N = 100005;
const double eps = 1e-8;
const int mod = 1000000007;

int n, m, ans, v[1005];
vector<int> edge[1005];

int dfs(int a)
{
    v[a] = true;
    vector<int> son;
    for (int i = 0; i < sz(edge[a]); ++i)
    {
        int j = edge[a][i];
        if (v[j]) continue;
        son.pb(dfs(j));
    }
    sort(son.begin(), son.end());
    reverse(son.begin(), son.end());
    if (sz(son) < 2) return 1;
    return son[0] + son[1] + 1;
}

void work()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        edge[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int j, k;
        cin >> j >> k;
        edge[j].pb(k);
        edge[k].pb(j);
    }
    ans = 0;
    for (int rt = 1; rt <= n; ++rt)
    {
        for (int i = 1; i <= n; ++i)
            v[i] = 0;
        ans = max(ans, dfs(rt));
    }
    cout << n - ans << endl;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
		freopen("c.out","w",stdout);
	#endif
	int task;
	cin >> task;
	for (int i = 1; i <= task; ++i)
	{
	    cout << "Case #";
	    cout << i;
	    cout << ": ";
	    work();
	}
	return 0;
}
