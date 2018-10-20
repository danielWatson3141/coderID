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

int n, m, edge[205][205], ans;
string s[205], t[205];

void dfs(int dep, int tot)
{
    if (tot >= ans) return;
    if (dep == m)
    {
        ans = tot;
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        bool flag = false;
        for (int j = 0; j < n; ++j)
            if (s[i][dep] == t[j][dep])
            {
                ++edge[i][j];
                if (edge[i][j] == dep + 1)
                    flag = true;
            }
        if (flag) ++cnt;
    }

    if (cnt == n)
        dfs(dep + 1, tot);

    cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        bool flag = false;
        for (int j = 0; j < n; ++j)
        {
            if (s[i][dep] == t[j][dep])
                --edge[i][j];
            if (s[i][dep] != t[j][dep])
            {
                ++edge[i][j];
                if (edge[i][j] == dep + 1)
                    flag = true;
            }
        }
        if (flag) ++cnt;
    }

    if (cnt == n)
        dfs(dep + 1, tot + 1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][dep] != t[j][dep])
                --edge[i][j];
}

void work()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            edge[i][j] = 0;
    ans = m + 1;
    dfs(0, 0);
    if (ans == m + 1) cout << "NOT POSSIBLE" << endl;
    else cout << ans << endl;
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
