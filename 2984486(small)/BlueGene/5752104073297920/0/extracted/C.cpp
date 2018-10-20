#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int n;
vector<int> a[150];

int main()
{
    freopen("C-small-attempt1.in.txt", "r", stdin);
    freopen("C-small-attempt1.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        a[Test].push_back(0);
        cin >> n;
        for (int i = 1, x; i <= n; ++i)
        {
            cin >> x;
            a[Test].push_back(x);
        }
        a[Test].push_back(Test);
    }
    sort(a+1, a+TestCase+1);
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        if (Test <= TestCase/2)
            a[Test][0] = 0;
        else
            a[Test][0] = 1;
        swap(a[Test].front(), a[Test].back());
    }
    sort(a+1, a+TestCase+1);
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ": " << (a[Test].back() ? "GOOD" : "BAD") << endl;
    }
    return 0;
}
