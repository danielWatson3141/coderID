#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

#define N 1010

int n;
int a[N];

void readInput()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

string solve()
{
    double d1 = 0, d2 = 0;
    for (int i = 0; i < n / 2; i++)
        d1 += (a[i] - n / 2.0) * (a[i] - n / 2.0);
    d1 /= n / 2;
    for (int i = 0; i < n / 2; i++)
        d2 += (a[n - i - 1] - n / 2.0) * (a[n - i - 1] - n / 2.0);
    d2 /= n / 2;
    double c = 0.95;
    //dbg(d1);
    //dbg(d2);
    if (min(d1, d2) / max(d1, d2) < c)
        return "BAD";
    return "GOOD";
}

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        readInput();
        cout << solve();
        cout << endl;
    }
    return 0;
}
