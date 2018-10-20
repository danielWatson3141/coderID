#include <cmath>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

inline int count_reverse_pairs(vector<int> &perm) {
    const int n = perm.size();
    int pairs = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (perm[i] > perm[j])
                ++pairs;
    return pairs;
}

inline void read_perm(vector<int> &perm, const int N) {
    int val;
    for (int i = 0; i < N; ++i) {
        cin >> val;
        perm[i] = val;
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0;i < T;++i) {
        int N;
        cin >> N;
        int expected_rev_pairs = N*(N-1)/4;
        vector<int> perm(N);
        read_perm(perm, N);
        /* cout << abs(count_reverse_pairs(perm) - expected_rev_pairs) << endl; */
        if (abs(count_reverse_pairs(perm) - expected_rev_pairs) > 6000)
            cout << "Case #" << (i+1) << ": BAD";
            /* cout << "BAD"; */
        else {
            /* if (rand()%2 == 1) */
                /* cout << "Case #" << (i+1) << ": BAD"; */
            /* else */
                cout << "Case #" << (i+1) << ": GOOD";
            /* cout << "GOOD"; */
        }
        cout << endl;
    }
}
