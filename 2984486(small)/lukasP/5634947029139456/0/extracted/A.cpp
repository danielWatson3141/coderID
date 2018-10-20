#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef long long ll;
ll integ(bitset<40> b)
{
    ll res = 0;
    rep(i,0,40)
        res = res * 2 + b[39 - i];
    return res;
}
void solve()
{
    int n, l; scanf("%d %d", &n, &l);

    vector<ll> a(n), d(n);
    bitset<40> ba[n];
    bitset<40> bd[n];
    rep(i,0,n)
    {
        string s; cin >> s;
        bitset<40> b(s);
        ba[i] = b;
        a[i] = integ(b);
    }

    rep(i,0,n)
    {
        string s; cin >> s;
        bitset<40> b(s);
        bd[i] = b;
        d[i] = integ(b);
    }
    sort(d.begin(), d.end());

    int needs = l + 1;
    int s = 1 << l;
    rep(k,0,s)
    {
        vector<ll> c(n);
        rep(j,0,n)
            c[j] = k ^ a[j];

        sort(c.begin(), c.end());
        if (c == d)
            needs = min(needs, (int)(bitset<10>(k)).count());
    }

    if (needs == l + 1)
        cout << "NOT POSSIBLE" << endl;
    else
        cout << needs << endl;
}
int main()
{
    int tt; scanf("%d", &tt);
    rep(sd,0,tt)
    {
        printf("Case #%d: ", sd+1);
        solve();
    }
}
