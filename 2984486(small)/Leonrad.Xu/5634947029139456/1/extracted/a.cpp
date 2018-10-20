#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int n, l;
long long a[200], b[200], c[200];

void insert(long long &x, string &s){
    x = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            x = x * 2 + 1;
        else
            x = x * 2;
}

int check(long long mask) {
    int value = 0;
    for (int i = 0; i < l; i ++) 
        if (mask & (1ll << i)) value++;
    for (int i = 0; i < n; i++)
        c[i] = a[i] ^ mask;
    sort(c, c + n);
    for (int i = 0; i < n; i++)
        if (c[i] != b[i])
            return INF;
    return value;
}

void solve() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(a[i], s);
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(b[i], s);
    }
    sort(b, b + n);

    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, check(a[0] ^ b[i]));
    if (ans == INF) 
        cout << "NOT POSSIBLE" << endl;
    else
        cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
