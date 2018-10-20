#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <climits> 
#include <cfloat> 
#include <map> 
#include <utility> 
#include <set> 
#include <iostream> 
#include <memory> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <sstream> 
#include <complex> 
#include <stack> 
#include <queue> 
#include <numeric>
#include <cassert>
#include <gmpxx.h>

#define FOR(i, min, max) for (int i = (min); i < (max); ++i) 
#define FORE(i, min, max) for (int i = (min); i <= (max); ++i) 
#define REP(i, n) for (int i = 0; i < (n); ++i) 
#define REPV(vec, i) for (int i = 0; i < (int)(vec.size()); ++i) 
#define FOR_EACH(vec, it) for (typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); ++it)

using namespace std; 
static const double EPS = 1e-12; 
typedef long long ll; 
typedef mpz_class bint;

vector<string> convert(vector<string> A, ll mask) {
    int L = A[0].size();
    int N = A.size();

    REP(i, L) if ((mask>>i) & 1) {
        REP(j, N) {
            if (A[j][i] == '0')
                A[j][i] = '1';
            else
                A[j][i] = '0';
        }
    }

    return A;
}

string solve_small(void)
{
    int N, L;
    cin >> N >> L;

    vector<string> A(N);
    vector<string> B(N);

    REP(i, N)
        cin >> A[i];

    REP(i, N)
        cin >> B[i];

    sort(B.begin(), B.end());

    int ret = INT_MAX;
    REP(s, (1<<L)) {
        vector<string> C = convert(A, s);
        sort(C.begin(), C.end());

        bool ok = true;
        REP(i, N) {
            if (C[i] != B[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ret = min(ret, __builtin_popcount(s));
        }
    }

    ostringstream oss;
    if (ret == INT_MAX) {
        oss << "NOT POSSIBLE";
    } else {
        oss << ret;
    }
    return oss.str();
}

ll getSwitch(string a, string b)
{
    int L = a.size();

    ll mask = 0;
    REP(i, L) if (a[i] != b[i]) {
        mask |= (1LL<<(ll)i);
    }

    return mask;
}

string solve(void)
{
    int N, L;
    cin >> N >> L;

    vector<string> A(N);
    vector<string> B(N);

    REP(i, N)
        cin >> A[i];

    REP(i, N)
        cin >> B[i];

    sort(B.begin(), B.end());

    int ret = INT_MAX;
    REP(i, N) REP(j, N) {
        ll s = getSwitch(A[i], B[j]);
        vector<string> C = convert(A, s);
        
        sort(C.begin(), C.end());
        bool ok = true;
        REP(k, N) {
            if (C[k] != B[k]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ret = min(ret, __builtin_popcountll(s));
        }
    }

    ostringstream oss;
    if (ret == INT_MAX) {
        oss << "NOT POSSIBLE";
    } else {
        oss << ret;
    }
    return oss.str();
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        //cerr << _t+1 << "/" << T << endl;
        cout << "Case #" << _t+1 << ": " << solve() << endl;
    }

    return 0;
}

