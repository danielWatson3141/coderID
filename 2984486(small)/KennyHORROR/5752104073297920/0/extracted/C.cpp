#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

int p[1005];

double pr[2][1005];
double pp[1005][1005];

void Calc(int n) {
    double dp = (double)(n - 1) / n;
    for (int d = 0; d < n; ++d) {
        int cur = 0, nxt = 1;
        for (int i = 0; i < n; ++i) {
            if (i == d) {
                pr[cur][i] = 1;
            } else {
                pr[cur][i] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    pr[nxt][j] = 1.0 / n;
                } else {
                    pr[nxt][j] = dp * pr[cur][j] + (1 - dp) * pr[cur][i];
                }
            }
            swap(cur, nxt);
        }
        for (int i = 0; i < n; ++i) {
            pp[d][i] = pr[cur][i];
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << pp[i][j] << " ";
        }
        cout << endl;
    }*/
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
 //   int n;
 //   cin >> n;
 //   Calc(n);
 //   return 0;
    Calc(1000);
    int T;
    cin >> T;
    for (int I = 0; I < T; ++I) {
        printf("Case #%d: ", I + 1);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        double ppp = 0;
        for (int i = 0; i < n; ++i) {
            ppp += log(n * pp[p[i]][i]);
        }
        if (ppp > 0) {
            puts("BAD");
        } else {
            puts("GOOD");
        }
    }
    return 0;
}
