#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define GCD(a,b) __gcd(a, b)
#define mp make_pair
#define DEBUG(x) cout << x << "\n"

int T, N;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        if (i % 2) {
            cout << "GOOD\n";
        }
        else cout << "BAD\n";
    }
}