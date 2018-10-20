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

int to_b(const string& s) {
    int ret = 0;
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

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        ll M = 1 << L;
        int ans = 100;
        for (ll mask = 0; mask < M; mask++) {
            vector<ll> v(N);
            for (int i = 0; i < N; i++) {
                v[i] = B[i] ^ mask;
            }
            if (check(v, A)) {
                ans = min(ans, __builtin_popcount(mask));
            }
        }
        cout << "Case #" << t << ": ";
        if (ans == 100) {
            cout << "NOT POSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
