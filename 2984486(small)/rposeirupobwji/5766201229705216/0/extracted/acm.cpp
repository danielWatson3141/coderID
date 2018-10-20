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

vector<vector<int> > arr;

int go(int a, int from)
{
    if (arr[a].empty())
        return 1;

    multiset<int, greater<int> > best;

    for (int kam : arr[a])
    {
        if (kam != from)
            best.insert(go(kam, a));
    }

    int res = 1;
    if (best.size() >= 2)
    {
        res = *best.begin() + *(++best.begin());
        ++res;
    }

    return res;
}

int main()
{
    srand(time(NULL));
    cout << setprecision(15);
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        arr.clear();
        int n;
        cin >> n;
        arr.resize(n+1);

        FOR(n-1)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        int res = 0;
        FOR(n+1)
        {
            res = max(res, go(i, 0));
        }

        printf("Case #%d: %d\n", CASE, n - res);
    }

    return 0;
}
