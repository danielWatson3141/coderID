#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 222;

bool u[MAXN];
int cs;
string a[MAXN], b[MAXN], c[MAXN];

inline void work() {
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(b, b + n);
    int ans = l + 1;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < l; ++j)
            if (a[0][j] != b[i][j]) {
                u[j] = true;
                ++cnt;
            }
            else
                u[j] = false;
        for (int j = 0; j < n; ++j) {
            c[j] = a[j];
            for (int k = 0; k < l; ++k)
                if (u[k])
                    c[j][k] = '0' + '1' - c[j][k];
        }
        sort(c, c + n);
        bool f = true;
        for (int j = 0; f && j < n; ++j)
            if (c[j] != b[j])
                f = false;
        if (f && cnt < ans)
            ans = cnt;
    }
    cout << "Case #" << ++cs << ": ";
    if (ans == l + 1)
        cout << "NOT POSSIBLE" << endl;
    else
        cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        work();
    return 0;
}
