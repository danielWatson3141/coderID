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
typedef long long ll;

bool solve() {
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    ll rev = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (v[i] > v[j]) {
                rev += (v[i] - v[j]) * (j - i);
            }
        }
    }
    //cout << rev << endl;
    return rev > 26500000000;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << (solve() ? "GOOD" : "BAD") << endl;
    }
    return 0;
}
