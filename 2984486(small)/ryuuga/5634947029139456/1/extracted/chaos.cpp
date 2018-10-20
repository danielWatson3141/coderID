#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORI(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) FOR(i,0,b)
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vll;

static const int oo = 99999999;
ll read_bits(int L) {
    string bits;
    cin >> bits;
    assert(bits.length() == L);
    ll total = 0;
    for(char c: bits) {
        assert(c == '0' || c == '1');
        total = total * 2 + (c - '0');
    }
    return total;
}

int num_bits(ll bits) {
    return bits == 0 ? 0 : (1 + num_bits(bits & (bits-1)));
}

bool works(const vll& devices, const unordered_set<ll>& outletset, const int SWITCH) {
    for(ll d: devices) {
        if (outletset.count(d ^ SWITCH) == 0) {
            return false;
        }
    }
    return true;
}

int solve(const vll& devices, const vll& outlets) {
    unordered_set<ll> outletset;
    for(ll o: outlets) { outletset.insert(o); }

    int best = oo;
    for(ll A: devices) {
        for(ll B: outlets) {
            ll FLIP = A ^ B;
            const int bits = num_bits(FLIP);
            if (bits >= best) continue;

            if (works(devices, outletset, FLIP)) {
                best = bits;
            }
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, L;
        cin >> N >> L;
        assert(1 <= N && N <= 150);
        assert(2 <= L && L <= 40);

        vll devices(N);
        for(ll& d: devices) d = read_bits(L);
        vll outlets(N);
        for(ll& o: outlets) o = read_bits(L);

        int solution = solve(devices, outlets);
        cout << "Case #" << (i+1) << ": ";
        if (solution == oo) {
            cout << "NOT POSSIBLE";
        } else {
            cout << solution;
        }
        cout << endl;
    }
}
