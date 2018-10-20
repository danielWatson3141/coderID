#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int n;
vector<int> E[MAXN];
int sub[MAXN];

int rek (int x, int dad) {
    sub[x] = 1;
    vector<int> v;
    int ch;
    for (int to : E[x]) if (to != dad) {
        v.push_back(rek(to, x) - sub[to]);
        sub[x] += sub[to];
        ch = to;
    }
    sort (v.begin(), v.end());
    if (v.size() == 0) return 0;
    if (v.size() == 1) return sub[ch];
    return v[0] + v[1] + sub[x] - 1;
}

void solve ()
{
    scanf ("%d", &n);
    for (int i = 0; i < MAXN; ++i) E[i].clear();

    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf ("%d%d", &x, &y);
        --x; --y;
        E[x].push_back(y);
        E[y].push_back(x);
    }

    int ans = 2000;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, rek(i, -1));
    }

    printf ("%d\n", ans);

}

int main ()
{
    int No; scanf ("%d", &No);
    for (int i = 0; i < No; ++i) {
        printf ("Case #%d: ", i + 1);
        solve();
    }

    return 0;
}

