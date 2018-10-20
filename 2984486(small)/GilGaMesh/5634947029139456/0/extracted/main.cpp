/*
ID: craig042
PROG: fence4
LANG: C++
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include <cmath>
#include <cstdio>
#include <cstdarg>
#include <cstring>

using namespace std;

int main()
{
    //    freopen("fence4.in", "r", stdin);
        freopen("fence4.out", "w", stdout);
    ios::sync_with_stdio(false);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif

    const int K = 16;

    int rev;
    char chQ[K];
    int m, v, w, k, i;
    int test, t, n, l;
    int dev[K], otl[K];

    cin >> test;
    for (t = 1; t <= test; t++)
    {
        cin >> n >> l;

        for (i = 0; i < n; i++)
        {
            cin >> chQ;
            otl[i] = 0;
            for (v = 0; v < l; v++)
                if (chQ[v] == 49)
                    otl[i] += (1 << v);
        }
        for (i = 0; i < n; i++)
        {
            cin >> chQ;
            dev[i] = 0;
            for (v = 0; v < l; v++)
                if (chQ[v] == 49)
                    dev[i] += (1 << v);
        }

        sort(dev, dev + n);

        k = 1 << 9;
        m = 1 << l;
        for (i = 0; i < m; i++)
        {
            w = rev = 0;
            for (v = 0; v < l; v++)
            {
                rev += (i & (1 << v));
                w += (i & (1 << v)) != 0;
            }

            for (v = 0; v < n; v++)
                otl[v] ^= rev;

            sort(otl, otl + n);
            if (memcmp(dev, otl, n << 2) == 0)
                k = min(k, w);

            for (v = 0; v < n; v++)
                otl[v] ^= rev;
        }

        cout << "Case #" << t << ": ";
        if (k == (1 << 9))
            cout << "NOT POSSIBLE";
        else
            cout << k;
        cout << endl;
    }

    return 0;
}
