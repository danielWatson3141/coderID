#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

#define N 160
#define M 50

int n, l;
int a[N][M], b[N][M];

void readInput()
{
    cin >> n >> l;
    string t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        for (int j = 0; j < l; j++)
            a[i][j] = t[j] - '0';
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        for (int j = 0; j < l; j++)
            b[i][j] = t[j] - '0';
    }
}

int solve()
{
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        vector<int> fl(l, 0);
        vector<char> used(n, false);
        used[i] = true;
        int cur_ans = 0;
        for (int j = 0; j < l; j++)
            if (a[0][j] != b[i][j])
            {
                fl[j] = 1;
                cur_ans++;
            }
            else
            {
                fl[j] = 0;
            }
        bool everyone_matched = true;
        for (int j = 1; j < n; j++)
        {
            bool pair_found = false;
            for (int e = 0; e < n; e++)
                if (!used[e])
                {
                    bool ok = true;
                    for (int o = 0; o < l; o++)
                        if ((a[j][o] ^ fl[o]) != b[e][o])
                        {
                            ok = false;
                            break;
                        }
                    if (ok)
                    {
                        used[e] = true;
                        pair_found = true;
                        break;
                    }
                }
            if (!pair_found)
            {
                everyone_matched = false;
                break;
            }
        }
        if (everyone_matched)
        {
            ans = min(ans, cur_ans);
        }
    }
    return ans;
}

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        readInput();
        int ans = solve();
        if (ans == INT_MAX)
            cout << "NOT POSSIBLE";
        else cout << ans;
        cout << endl;
    }
    return 0;
}
