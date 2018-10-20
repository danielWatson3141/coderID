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
void solve()
{
    int n, l; scanf("%d %d", &n, &l);

    vector<ll> a(n), d(n);
    rep(i,0,n)
    {
        string s; cin >> s;
        bitset<40> b(s);
        a[i] = b.to_ullong();
    }

    rep(i,0,n)
    {
        string s; cin >> s;
        bitset<40> b(s);
        d[i] = b.to_ullong();
    }
    sort(d.begin(), d.end());

    int needs = l + 1;
    rep(i,0,n)
    {
        ll swit = (d[i] ^ a[0]);
        vector<ll> c(n);
        rep(j,0,n)
            c[j] = swit ^ a[j];

        sort(c.begin(), c.end());
        if (c == d)
            needs = min(needs, (int)bitset<40>(swit).count());
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
