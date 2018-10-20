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
// BEGIN CUT HERE
#define DEBUG(var) { cout << #var << ": " << (var) << endl; }
template <class T> ostream& operator << (ostream &os, const vector<T> &temp) { os << "[ "; for (unsigned int i=0; i<temp.size(); ++i) os << (i?", ":"") << temp[i]; os << " ]"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const set<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const multiset<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const pair<S,T> &a) { os << "(" << a.first << "," << a.second << ")"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const map<S,T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (it->first) << "->" << it->second; os << " }"; return os; } // DEBUG
// END CUT HERE
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int N, L;
vector<long long> spot, zast;

long long decode(const string &S) {
    long long answer = 0;
    for (int l=0; l<L; ++l) if (S[l]=='1') answer |= 1LL << l;
    return answer;
}

int solve(vector<long long> S, vector<long long> Z, int bits_fixed) {
    // DEBUG(S); DEBUG(Z); DEBUG(bits_fixed);

    if (bits_fixed==L) {
        sort( S.begin(), S.end() );
        sort( Z.begin(), Z.end() );
        if (S == Z) return 0;
        return 987654321;
    }
    
    long long mask = (1LL << bits_fixed) - 1;

    set< long long > Spref, Zpref;
    for (long long x : S) Spref.insert(x&mask);
    for (long long x : Z) Zpref.insert(x&mask);
    if (Spref != Zpref) {
        // cout << "unequal prefixes" << endl;
        return 987654321;
    }

    map< long long, int > Snula, Sjedna, Znula, Zjedna;
    for (long long x : S) { if (x & 1LL<<bits_fixed) ++Sjedna[x&mask]; else ++Snula[x&mask]; }
    for (long long x : Z) { if (x & 1LL<<bits_fixed) ++Zjedna[x&mask]; else ++Znula[x&mask]; }

    bool must_keep=false, must_flip=false;
    for (auto x : Spref) {
        if (Sjedna[x]==Snula[x]) {
            if (Zjedna[x]!=Znula[x]) return 987654321;
        } else {
            bool dasa = false;
            if (Sjedna[x]==Zjedna[x] && Snula[x]==Znula[x]) { dasa=true; must_keep=true; }
            if (Sjedna[x]==Znula[x] && Snula[x]==Zjedna[x]) { dasa=true; must_flip=true; }
            if (!dasa) return 987654321;
        }
    }
    if (must_flip && must_keep) return 987654321;
    int res = 987654321;
    if (!must_flip) res = min( res, solve(S,Z,bits_fixed+1) );
    if (!must_keep) {
        vector<long long> NZ(Z);
        for (long long &x:NZ) x ^= 1LL << bits_fixed;
        res = min( res, 1+solve(S,NZ,bits_fixed+1));
    }
    return res;
}

int main() {
    int TT; cin >> TT;
    for (int tt=1; tt<=TT; ++tt) {
        cin >> N >> L;
        spot.clear(); zast.clear();
        for (int n=0; n<N; ++n) { string S; cin >> S; spot.push_back(decode(S)); }
        for (int n=0; n<N; ++n) { string S; cin >> S; zast.push_back(decode(S)); }

        int answer = solve( spot, zast, 0 );

        if (answer == 987654321) {
            cout << "Case #" << tt << ": NOT POSSIBLE" << endl;
        } else {
            cout << "Case #" << tt << ": " << answer << endl;
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
