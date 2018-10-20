#include <iostream>
#include <set>
using namespace std;

#define MAXN 256
#define MAXL 64

set<long long> s;

int main() {
    int T, t, N, L, i, j, k, score, BEST;
    long long n[2][MAXN], mask;
    char tmp[MAXL];

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> N >> L;
        for (i=0; i<2; i++) for (j=0; j<N; j++) {
            cin >> tmp; n[i][j] = 0;
            for (k=0; k<L; k++) if (tmp[k] == '1') n[i][j] ^= (1LL<<k);
        }

        BEST = L+1;
        for (i=0; i<N; i++) for (j=0; j<N; j++) {
            mask = n[0][i]^n[1][j]; s.clear();
            score = 0;
            for (k=0; k<L; k++) score += ((mask>>k)&1LL);
            if (score >= BEST) continue;

            for (k=0; k<N; k++) s.insert(mask^n[0][k]);
            for (k=0; k<N; k++) if (s.find(n[1][k]) == s.end()) break;
            if (k == N) BEST = min(BEST, score);
        }
        if (BEST < L+1) cout << "Case #" << t << ": " << BEST << endl;
        else cout << "Case #" << t << ": NOT POSSIBLE" << endl;
    }

    return 0;
}
