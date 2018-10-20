#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
//#include <unordered_set>
//#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
typedef unsigned long long ullong;
#define mp make_pair
#define sqr(x) ((x)*(x))
const double PI = 3.14159265359;
#define y1 Y1
#define y0 alalal1231
using namespace std;

int main()
{
#ifdef MYLOCAL
    freopen("/home/vladimir/code/pain/input.txt", "rt", stdin);
    freopen("/home/vladimir/code/pain/output.txt", "wt", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int _i = 1; _i <= t; ++_i)
    {
        int n, l, ans = INT_MAX;
        scanf("%d %d", &n, &l);
        vector<string> in(n), out(n);
        for (int i = 0; i < n; ++i)
            cin >> in[i];
        for (int i = 0; i < n; ++i)
            cin >> out[i];
        sort(in.begin(), in.end());
        do
        {
            bool ok = true;
            int cnt = 0;
            for (int j = 0; j < l; ++j)
            {
                bool flip = false;
                for (int k = 0; k < n; ++k)
                {
                    if (k == 0)
                        flip = in[k][j] != out[k][j];
                    else if ((in[k][j] != out[k][j]) != flip)
                        ok = false;
                }
                if (flip)
                    ++cnt;
                if (!ok)
                    break;
            }
            if (ok)
                ans = min(ans, cnt);
        } while(next_permutation(in.begin(), in.end()));
        printf("Case #%d: ", _i);
        if (ans == INT_MAX)
            puts("NOT POSSIBLE");
        else
            printf("%d\n", ans);
    }

    return 0;
}

