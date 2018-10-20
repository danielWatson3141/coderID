#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        int n, l; cin >> n >> l;

        string x[n], y[n];
        for(int i = 0; i < n; ++i) cin >> x[i];
        for(int i = 0; i < n; ++i) cin >> y[i];

        int ret = 0x7fffffff;
        for(int msk = 0; msk < (1 << l); ++msk)
        {
            string xx[n], yy[n];
            for(int i = 0; i < n; ++i)
                xx[i] = x[i], yy[i] = y[i];

            for(int i = 0; i < l; ++i)
                if(msk & (1 << i))
                    for(int j = 0; j < n; ++j)
                        yy[j][i] = ((yy[j][i] == '0') ? '1' : '0');

            bool can = true;
            sort(xx, xx + n); sort(yy, yy + n);
            for(int i = 0; i < n; ++i) can &= xx[i] == yy[i];

            if(can) ret = min(ret, __builtin_popcountll(msk));
        }
        if(ret < 0x7fffffff) printf("Case #%d: %d\n", tt, ret);
        else printf("Case #%d: NOT POSSIBLE\n", tt);
    }
    return 0;
}