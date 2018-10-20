// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int N, L;
vector<long long> spot, zast;

long long decode(const string &S) {
    long long answer = 0;
    for (int l=0; l<L; ++l) if (S[l]=='1') answer |= 1LL << l;
    return answer;
}

int main() {
    int TT; cin >> TT;
    for (int tt=1; tt<=TT; ++tt) {
        cin >> N >> L;
        spot.clear(); zast.clear();
        for (int n=0; n<N; ++n) { string S; cin >> S; spot.push_back(decode(S)); }
        sort( spot.begin(), spot.end() );
        for (int n=0; n<N; ++n) { string S; cin >> S; zast.push_back(decode(S)); }

        int answer = 987654321;
        for (long long flip=0; flip<(1LL<<L); ++flip) {
            vector<long long> nz;
            for (long long x:zast) nz.push_back(x ^ flip);
            sort( nz.begin(), nz.end() );
            if (spot == nz) answer = min( answer, __builtin_popcountll(flip) );
        }

        if (answer == 987654321) {
            cout << "Case #" << tt << ": NOT POSSIBLE" << endl;
        } else {
            cout << "Case #" << tt << ": " << answer << endl;
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
