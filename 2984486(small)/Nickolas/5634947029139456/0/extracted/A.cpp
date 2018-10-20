#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string itos(int q) {
  stringstream A;
  A << q; 
  string s; 
  A >> s; 
  return s; 
}

void solve(int ind) {
    // input
    int N, L;
    cin >> N >> L;
    vector<string> outlet(N), device(N);
    for (int i = 0; i < N; ++i) {
        cin >> outlet[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> device[i];
    }
    sort(device.begin(), device.end());
    
    // try all combinations of flips
    int minbits = L + 1;
    for (int mask = 0; mask < (2 << L) - 1; ++mask) {
        vector<string> outlet_flip = outlet;
        int bits = 0;
        for (int j = 0; j < L; ++j)
            if (mask & (1 << j)) {
                ++bits;
                for (int i = 0; i < N; ++i) {
                    outlet_flip[i][j] = (char)('0'+'1'-outlet_flip[i][j]);
                }
            }
        sort(outlet_flip.begin(), outlet_flip.end());
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (device[i] != outlet_flip[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            minbits = min<int>(minbits, bits);
        }
    }

    // output
    if (minbits == L + 1) {
        cout << "Case #" << ind << ": " << "NOT POSSIBLE" << endl;
    } else {
        cout << "Case #" << ind << ": " << minbits << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
}