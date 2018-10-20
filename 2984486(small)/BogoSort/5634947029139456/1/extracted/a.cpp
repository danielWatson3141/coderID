#include <iostream>
#include <string>
using namespace std;

int solve()
{
    int n, l;
    cin >> n >> l;
    long long init[n + 10];
    long long targ[n + 10];
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        init[i] = 0;
        for (int j = 0; j < l; ++j)
        {
            init[i] = init[i] * 2 + (s[j] - '0');
        }
    }
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        targ[i] = 0;
        for (int j = 0; j < l; ++j)
        {
            targ[i] = targ[i] * 2 + (s[j] - '0');
        }
    }
    long long diff[n + 10][n + 10];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            diff[i][j] = targ[i] ^ init[j];
        }
    }
    int ans = l + 1;
    for (int i = 0; i < n; ++i)
    {
        int p = diff[0][i];
        bool f[n + 10];
        for (int j = 0; j < n; ++j)
        {
            f[j] = false;
        }
        bool flag = false;
        for (int j = 0; j < n; ++j)
        {
            flag = false;
            for (int k = 0; k < n; ++k)
            {
                if (diff[j][k] == p)
                {
                    flag = true;
                    f[k] = true;
                    break;
                }
            }
            if (!flag) break;
        }
        if (!flag) continue;
        int cnt = 0;
        while (p)
        {
            cnt += p % 2;
            p /= 2;
        }
        if (cnt < ans) ans = cnt;
    }
    if (ans > l) cout << "NOT POSSIBLE" << endl;
    else cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
