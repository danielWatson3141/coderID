#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < a; ++i)
#define mp(a, b) make_pair(a, b)
#define D(a) #a << ": " << a << "\n"

int toInt(string& s)
{
    int res = 0;
    FOR(s.size())
        if (s[i] == '1')
            res |= 1 << i;

    return res;
}

int popcount(int a)
{
    int res = 0;
    while (a > 0)
    {
        ++res;
        a &= a - 1;
    }

    return res;
}

int transform(int a, int mask)
{
    for (int i = 0; i < 32; ++i)
        if (mask & (1 << i))
            if (a & (1 << i))
                a &= ~(1 << i);
            else
                a |= 1 << i;

    return a;
}

int main()
{
    srand(time(NULL));
    cout << setprecision(15);
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        int n, l;
        cin >> n >> l;
        vector<int> init;
        set<int> req;
        string s;
        FOR(n) cin >> s, init.push_back(toInt(s));
        FOR(n) cin >> s, req.insert(toInt(s));

        int res = 12345;

        for (int mask = 0; mask < (1 << l); ++mask)
        {
            set<int> tmp;
            tmp.clear();

            FOR(n) tmp.insert(transform(init[i], mask));

            if (tmp == req)
                res = min(res, popcount(mask));
        }

        if (res == 12345)
            printf("Case #%d: NOT POSSIBLE\n", CASE);
        else
            printf("Case #%d: %d\n", CASE, res);
    }

    return 0;
}
