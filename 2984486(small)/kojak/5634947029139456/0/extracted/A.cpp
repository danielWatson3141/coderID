#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define GCD(a,b) __gcd(a, b)
#define mp make_pair
#define DEBUG(x) cout << x << "\n"

int T, N, L;
vector<string> outs, devs;

bool done(vector<string>& o1, vector<string>& o2) {
    sort(o1.begin(), o1.end());
    sort(o2.begin(), o2.end());
    for (int i = 0; i < N; ++i) {
        if (o1[i] != o2[i])
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    // 100 * 2^10 * 10 * 10
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": ";
        outs.clear(); devs.clear();
        cin >> N >> L;
        for (int i = 0; i < N; ++i) {
            string tmp; cin >> tmp;
            outs.push_back(tmp);
        }
        for (int i = 0; i < N; ++i) {
            string tmp; cin >> tmp;
            devs.push_back(tmp);
        }
        if (done(outs, devs)) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 10000;
        for (int i = 0; i < (1 << L); ++i) {
            int cnt = 0;
            vector<string> outC = outs;
            for (int j = 0; j < L; ++j) {
                if (i & (1 << j)) {
                    cnt++;
                    for (int k = 0; k < N; ++k) {
                        outC[k][j] = outC[k][j] == '1'? '0' : '1';
                    }
                }
            }
            if (done(outC, devs)) {
                ans = min(ans, cnt);
            }
        }
        if (ans == 10000) {
            cout << "NOT POSSIBLE\n";
        }
        else cout << ans << '\n';
    }
}