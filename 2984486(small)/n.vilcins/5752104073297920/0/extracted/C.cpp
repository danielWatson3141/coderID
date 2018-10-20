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

int n, a[1005];

bool solve()
{
    int cnt = 0;
    FOR(i, 0, n) cnt += (a[i] < i and a[i] > i - n/2);
    return cnt / double(n) < 0.36;
}

int main()
{
    freopen("C-small.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int test_cnt, good_cnt = 0;
    cin >> test_cnt;
    FOR(test_ind, 1, test_cnt + 1)
    {
        cin >> n;
        FOR(i, 0, n) cin >> a[i];
        printf("Case #%d: ", test_ind);
        bool good = solve();
        cout << (good ? "GOOD" : "BAD") << endl;
        good_cnt += good;
    }
    cerr << good_cnt << " " << test_cnt << " " << good_cnt / double(test_cnt) << endl;
}









