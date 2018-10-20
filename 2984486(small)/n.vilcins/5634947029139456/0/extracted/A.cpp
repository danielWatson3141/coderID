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

int n, l;
vector<string> a, b;

int rec(int pos)
{
    if(pos == l) return 0;
    int res = l + 1;

    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool ok = true;
        FOR(i, 0, n) ok &= (a[i][pos] == b[i][pos]);
        if(ok) res = min(res, rec(pos + 1));
    }
    {
        FOR(i, 0, n) a[i][pos] = char('0' + (int(a[i][pos] - '0') ^ 1));
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool ok = true;
        FOR(i, 0, n) ok &= (a[i][pos] == b[i][pos]);
        if(ok) res = min(res, 1 + rec(pos + 1));
        FOR(i, 0, n) a[i][pos] = char('0' + (int(a[i][pos] - '0') ^ 1));
    }

    return res;
}

int solve()
{
    int res = rec(0);
    return res > l ? -1 : res;
}

//int brute()
//{
//    int res = l + 1;
//    FOR(bb, 0, (1<<l))
//    {
//        FOR(i, 0, l) if((bb>>i)&1) FOR(j, 0, a.size())
//        {
//            a[j][i] = char('0' + (int(a[j][i] - '0') ^ 1));
//        }
//        sort(a.begin(), a.end());
//        sort(b.begin(), b.end());
//        if(a == b) res = min(res, __builtin_popcount(bb));
//        FOR(i, 0, l) if((bb>>i)&1) FOR(j, 0, a.size())
//        {
//            a[j][i] = char('0' + (int(a[j][i] - '0') ^ 1));
//        }
//    }
//    return res > l ? -1 : res;
//}

int main()
{
    freopen("A-small.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int test_cnt;
    cin >> test_cnt;
    FOR(test_ind, 1, test_cnt + 1)
    {
        cin >> n >> l;
        a = vector<string>(n);
        b = vector<string>(n);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];
        printf("Case #%d: ", test_ind);
        //cout << solve() << " " << brute() << endl;
        int ans = solve();
        if(ans == -1) cout << "NOT POSSIBLE" << endl;
        else cout << ans << endl;
    }
}









