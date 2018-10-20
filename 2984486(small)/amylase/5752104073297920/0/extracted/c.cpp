#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <complex>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long       li;
typedef vector<li>      vi;
typedef complex<double> pt;
typedef pair<pt, pt>    line;
typedef pair<li, li>    pi;
typedef vector<string>  vs;

#define rep(i,to)       for(li i=0;i<((li)to);++i)
#define foreach(it,set) for(__typeof((set).begin()) it=(set).begin();it!=(set).end();it++)
#define all(v)          v.begin(), v.end()

template <class T> inline void minu(T& x, T y) { x = min(x, y); }
template <class T> inline void maxu(T& x, T y) { x = max(x, y); }

inline li bit(li n){ return 1LL<<n; }
template <class T> ostream& operator<<(ostream& os, vector<T> x){
    foreach(it, x) os << *it << ' ';
    return os;
}

li dx[8] = {1, -1, 0,  0, -1, 1,  1, -1};
li dy[8] = {0,  0, 1, -1, -1, 1, -1,  1};

const int sz = 1000;
double prob[sz][sz];

void init(int n) {
    cerr << "init " << n << endl;
    rep(i, n) prob[i][i] = 1;
    rep(i, n) {
        rep(p, n) {
            double g = prob[i][p] / n;
            prob[i][p] = 0;
            rep(t, n) prob[i][t] += g;
        }
    }
}

void solve(int caseNum) {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    //if (n != sz) init(n);

    double llb = 0, llg = 0;
    rep(i, n) {
        llb += log(prob[p[i]][i]);
        llg += log(1.0 / n);
    }
    cout << "Case #" << caseNum << ": " << (llb < llg ? "GOOD" : "BAD") << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    init(sz);
    rep(i, n) solve(i + 1);
    return 0;
}
