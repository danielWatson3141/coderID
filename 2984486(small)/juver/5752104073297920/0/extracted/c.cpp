#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <float.h>

using namespace std;

#define REP(i, from, to) for (int i = (from); i < (to); ++i)
#define FOR(i, n) REP(i, 0, (n))
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)x.size()
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef pair<int, int> PII;

void perm1(VI& a) {
    FOR (i, SIZE(a)) {
        int const j = rand() % (SIZE(a) - i) + i;
        swap(a[i], a[j]);
    }
}

void perm2(VI& a) {
    FOR (i, SIZE(a)) {
        int const j = rand() % SIZE(a);
        swap(a[i], a[j]);
    }
}

void run(VI const& a, void (*perm)(VI&)) {
    map<VI, int> fr;
    FOR (ttt, 10000) {
        VI b = a;
        perm(b);
        ++fr[b];
    }

    vector<pair<VI, int> > c(ALL(fr));
    sort(ALL(c), [](pair<VI, int> const& p1, pair<VI, int> const& p2) {
        return p1.second < p2.second;
    });

    long double avg = 0;
    for (auto x : c) {
        cout << "count = " << x.second << ", permutation = ";
        //FOR (i, SIZE(x.first)) cout << x.first[i];
        long double p = 0;
        FOR (i, SIZE(x.first)) p += (long double)abs(i - x.first[i]) * abs(i - x.first[i]) * abs(i - x.first[i]);
        cout << ", p = " << p;
        avg += p;
        cout << endl;
    }

    cout << "avg = " << setprecision(15) << avg / SIZE(c) << endl;
}

void test() {
    int const n = 1000;
    VI a(n);
    FOR (i, n) a[i] = i;

    run(a, perm2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //test();
    //return 0;

    srand(time(0));
    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    FOR (testId, tests) {
        int n;
        cin >> n;

        VI a(n);
        FOR (i, n) {
            cin >> a[i];
        }

        long double p = 0;
        FOR (i, n) {
            p += (long double) abs(i - a[i]) * abs(i - a[i]) * abs(i - a[i]);
        }

        printf("Case #%d: ", testId + 1);

        i64 bad = 93028200057LL;
        i64 good = 100111767284LL;
        if (p >= (bad + (good - bad) * 0.4))
            cout << "GOOD\n";
        else
            cout << "BAD\n";
    }

    return 0;
}
