#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int n, m;
        cin >> n >> m;
        vector<string> a(n), b(n), c(n);
        int ans = m+1;

        for (int i=0; i<n; i++)
            cin >> a[i];
        for (int i=0; i<n; i++)
            cin >> b[i];

        sort(a.begin(), a.end());

        c = a;

        for (int i=0; i<n; i++)
        {
            int cur = 0;
            for (int j=0; j<m; j++)
                cur += a[0][j] != b[i][j];
            if (cur >= ans)
                continue;

            for (int k=0; k<n; k++)
                for (int j=0; j<m; j++)
                    c[k][j] = b[k][j] ^ b[i][j] ^ a[0][j];

            sort(c.begin(), c.end());

            if (c == a)
                ans = cur;
        }

        cout << "Case #" << tt << ": ";

        if (ans > m)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
