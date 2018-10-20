#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
string s[210], r[210], p[210];

vector<int> get (string A, string B) {
    vector<int> ret;
    for (int i = 0; i < (int)A.size(); ++i)
        if (A[i] != B[i]) ret.push_back(i);
    return ret;
}

string trans (string A, vector<int> v) {
    for (int x : v) A[x] = '1' - A[x] + '0';
    return A;
}

void solve ()
{
    scanf ("%d%d", &n, &l);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        cin >> r[i];

    sort (r, r + n);

    int ans = 1000;
    for (int i = 0; i < n; ++i) {
        vector<int> v = get(s[0], r[i]);
        for (int j = 0; j < n; ++j)
            p[j] = trans(s[j], v);
        sort (p, p + n);
        int ok = 1;
        for (int j = 0; j < n; ++j)
            if (p[j] != r[j]) ok = 0;
        if (ok) ans = min(ans, (int)v.size());
    }

    if (ans == 1000) printf ("NOT POSSIBLE\n");
    else printf ("%d\n", ans);
}

int main ()
{
    int No; scanf ("%d", &No);
    for (int i = 0; i < No; ++i) {
        printf ("Case #%d: ", i + 1);
        solve ();
    }

    return 0;
}

