#include <cstdio>
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <queue>
#include <utility>

using namespace std;

#define whole(xs) xs.begin(), xs.end()
typedef long long ll;

int T;

int N, L;
vector<ll> A, B;

ll to_b(const string& s) {
    ll ret = 0;
    for (int i = 0; i < s.size(); i++) {
        ret = ret * 2 + (s[i] - '0');
    }
    return ret;
}

void input() {
    cin >> N >> L;
    A.clear(); B.clear();
    A.resize(N); B.resize(N);
    for (int i = 0; i < N; i++) {
        string x; cin >> x;
        A[i] = to_b(x);
    }
    for (int i = 0; i < N; i++) {
        string x; cin >> x;
        B[i] = to_b(x);
    }
}

bool check(vector<ll> x, vector<ll> y) {
    sort(whole(x));
    sort(whole(y));
    return x == y;
}

void dump(const vector<ll> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        int ans = 10000;
        for (int i = 0; i < N; i++) {
            ll x = A[0] ^ B[i];
            vector<ll> v(N);
            for (int j = 0; j < N; j++) {
                v[j] = B[j] ^ x;
            }
            if (check(A, v)) {
                ans = min(ans, __builtin_popcount(x));
            }
        }

        cout << "Case #" << t << ": ";
        if (ans == 10000) {
            cout << "NOT POSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
