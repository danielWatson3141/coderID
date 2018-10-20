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

const int M = 1000; // roman numeral for 1000
ld histogram[M][M];
ld histogram2[M][M];

int main() {
    int N;
    cin >> N;
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            histogram[i][j] = 0;
        }
        histogram[i][i] = 1;
    }
    for(int i=0; i<M; i++) {
        ld x[M], y[M];
        for(int j=0; j<M; j++) {
            x[j] = histogram[i][j];
            y[j] = 0;
            for(int k=0; k<M; k++) {
                y[j] += histogram[k][j];
            }
            y[j]/= M;
        }
        for(int k=0; k<M; k++) {
            for(int j=0; j<M; j++) {
                histogram[k][j] = ((M-1)*histogram[k][j] + x[j])/M;
            }
        }
        for(int j=0; j<M; j++) {
            histogram[i][j] = y[j];
        }
    }
    // for(int i=0; i<M; i++) {
    //     ld x = 0;
    //     for(int j=0; j<M; j++) {
    //         x += j*histogram[i][j];
    //     }
    //     cerr << x << " ";
    // }
    // cerr << endl;
    for (int kase = 1; kase<=N; kase++) {
        cout << "Case #" << kase << ": ";
        int q; cin >> q;
        ld hmm = 1;
        int mm = M;
        for(int i=0; i<M; i++) {
            for(int j=0; j<M; j++) {
                histogram2[i][j] = histogram[i][j];
            }
        }
        for(int i=0; i<M; i++) {
            int x; cin >> x;
            ld zxcv = 0;
            for(int j=0; j<M; j++) {
                zxcv += histogram2[i][j];
            }
            hmm *= histogram2[i][x]/zxcv*mm;
            for(int j=i; j<M; j++) {
                histogram2[j][x] = 0;
            }
            mm--;
        }
        if(1.0L/(1.0L/hmm + 1) > 0.5) {
            cout << "BAD" << endl;
        } else {
            cout << "GOOD" << endl;
        }
    }
    return 0;    
}
