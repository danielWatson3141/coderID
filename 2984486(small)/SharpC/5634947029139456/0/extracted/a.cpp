#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int bitcount(long long x)
{
    int result = 0;
    while (x) {
        if (x & 1) {
            ++result;
        }
        x /= 2;
    }
    return result;
}

int main()
{
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n, l;
        cin >> n >> l;
        vector<long long> have(n), need(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < l; ++j) {
                have[i] = have[i] * 2 + (s[j] == '1');
            }
        }
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < l; ++j) {
                need[i] = need[i] * 2 + (s[j] == '1');
            }
        }

        int bestx = l + 1;
        vector<long long> need_sorted = need;
        sort(need_sorted.begin(), need_sorted.end());
        for (int i = 0; i < n; ++i) {
            long long x = need[0] ^ have[i];
            vector<long long> got = have;
            for (int j = 0; j < n; ++j) {
                got[j] ^= x;
            }
            sort(got.begin(), got.end());
            if (got == need_sorted) {
                bestx = min(bestx, bitcount(x));
            }
        }

        if (bestx > l) {
            cout << "Case #" << test << ": NOT POSSIBLE" << endl;
        } else {
            cout << "Case #" << test << ": " << bestx << endl;
        }
    }
}
