#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = 111;

void solve(int test)
{
    int n, l;
    cin >> n >> l;
    vector<string> a(n);
    vector<string> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b.begin(), b.end());
    vector<set<int> > s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            set<int> v;
            for (int k = 0; k < l; k++)
                if (a[i][k] != b[j][k])
                    v.insert(k);
            s.push_back(v);
        }
    int res = N;
    for (set<int> cur : s) {
        vector<string> have;
        for (int i = 0; i < n; i++) {
            string val = a[i];
            for (int k = 0; k < l; k++)
                if (cur.count(k))
                    if (val[k] == '1')
                        val[k] = '0';
                    else
                        val[k] = '1';
            have.push_back(val);
        }
        sort(have.begin(), have.end());
        if (have == b)
            res = min(res, (int)cur.size());
    }
    cout << "Case #" << test << ": ";
    if (res == N)
        cout << "NOT POSSIBLE\n";
    else
        cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
        solve(q);

    return 0;
}
