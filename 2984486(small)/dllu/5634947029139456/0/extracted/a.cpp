#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <stack>
#include <iomanip>
#include <map>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

inline unsigned long long mymin(unsigned long long a, unsigned long long b) {
    return a<b?a:b;
}

int main() {
    int N;
    cin >> N;
    for (int kase = 1; kase<=N; kase++) {
        int n, l; cin >> n >> l;
        unsigned long long x[200], y[200], m[200];
        for(int i=0; i<n; i++) {
            string s;
            cin >> s;
            x[i] = 0;
            for(unsigned long long j=0; j<l; j++) {
                if(s[l-1-j] == '1') {
                    x[i] += (1ULL << j);
                }
            }
        }
        for(int i=0; i<n; i++) {
            string s;
            cin >> s;
            y[i] = 0;
            for(unsigned long long j=0; j<l; j++) {
                if(s[l-1-j] == '1') {
                    y[i] += (1ULL << j);
                }
            }
        }
        sort(y, y+n);
        bool reallyworks = false;
        unsigned long long zxcv = 100;
        for(int k=0; k<n; k++) {
            // cerr << x[k] << " ";
        }
        // cerr << endl;
        for(int k=0; k<n; k++) {
            // cerr << y[k] << " ";
        }
        // cerr << endl;
        for(int i=0; i<n; i++) {
            unsigned long long z = x[i]^y[0];
            for(int j=0; j<n; j++) {
                m[j] = x[j]^z;
            }
            sort(m, m+n);
            // cerr << z << endl;
            for(int k=0; k<n; k++) {
                // cerr << m[k] << " ";
            }
            // cerr << endl;
            bool works = true;
            for(int j=0; j<n; j++) {
                if(m[j] != y[j]) {
                    works = false;
                    break;
                }
            }
            if(works) {
                reallyworks = true;
                zxcv = mymin(zxcv, __builtin_popcountll(z));
            }
        }
        if(reallyworks) {
            cout << "Case #" << kase << ": " << zxcv << endl;
        } else {
            cout << "Case #" << kase << ": " << "NOT POSSIBLE" << endl;
        }
    }
    return 0;    
}
