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

void depSearch(vector<pair<int, int> > &E, vector<bool> &used, int parent, int cur) {
    assert(!used[cur]);
    used[cur] = true;

    // count edge
    int ecount = 0;
    REPV(E, i) {
        if (E[i].first == cur && E[i].second != parent) {
            ecount++;
        }
        if (E[i].second == cur && E[i].first != parent) {
            ecount++;
        }
    }

    if (ecount == 0 || ecount == 2) {
        REPV(E, i) {
            if (E[i].first == cur && E[i].second != parent) {
                depSearch(E, used, cur, E[i].second);
            }
            if (E[i].second == cur && E[i].first != parent) {
                depSearch(E, used, cur, E[i].first);
            }
        }
    }
}

bool isBinTree(vector<pair<int, int> > E, int N, int emask) {
    if (E.empty())
        return true;

    if ((int)E.size() != N-__builtin_popcount(emask)-1) {
        return false;
    }

    set<int> nodes;

    REPV(E, i) {
        nodes.insert(E[i].first);
        nodes.insert(E[i].second);
        REPV(E, j) if (i != j) {
            pair<int, int> a = E[i];
            pair<int, int> b = E[j];
            if (a == b)
                return false;
            swap(a.first, a.second);
            if (a == b)
                return false;
        }
    }

    REP(k, N) if (((emask>>k)&1) == 0) {
    }
    
    return false;
}

int solve(void)
{
    int N;

    cin >> N;
    vector<pair<int, int> > E(N-1);
    REP(i, N-1) {
        cin >> E[i].first >> E[i].second;
        E[i].first--;
        E[i].second--;
    }

    int ret = INT_MAX;
    REP(k, N) {
        vector<bool> used(N, false);

        depSearch(E, used, -1, k);

        int eraseCount = 0;
        REP(i, N) if (!used[i]) {
            ++eraseCount;
        }

        ret = min(ret, eraseCount);
    }

    return ret;
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

