#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int N, L;
vector<string> A, B, C;
bool flip[1000];

int check(int p) {
    for (int i = 0; i < L; i++) {
        flip[i] = A[0][i] != B[p][i];
    }
    C.clear();
    for (int i = 0; i < N; i++) {
        string s = A[i];
        for (int j = 0; j < L; j++) {
            if (flip[j]) {
                s[j] = s[j] == '0' ? '1' : '0';
            }
        }
        C.push_back(s);
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < N; i++) {
        // cout << "B " << B[i] << ", C " << C[i] << endl;
        if (B[i] != C[i])
            return L + 1;
    }
    int r = 0;
    for (int i = 0; i < L; i++)
        if (flip[i])
            r++;
    return r;
}

void solve() {
    cin >> N >> L;
    A.clear();
    B.clear();
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        A.push_back(s);
    }
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        B.push_back(s);
    }
    sort(B.begin(), B.end());

    int ans = L + 1;
    for (int i = 0; i < N; i++) {
        int r = check(i);
        ans = min(ans, r);
    }

    if (ans > L)
        cout << "NOT POSSIBLE" << endl;
    else
        cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }

    return 0;
}
