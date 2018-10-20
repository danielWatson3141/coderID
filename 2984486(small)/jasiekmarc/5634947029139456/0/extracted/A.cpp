#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int numb(int x) {
    int d = 1, w=0;
    while(x) {
        w += d*(x%10);
        x/=10;
        d*=2;
    }
    return w;
}

void solve() {
    int n, l, a;
    scanf("%d %d", &n, &l);
    int m = 1100;
    vector<unsigned int> nasze(n), ich(n), proba(n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &a);
        nasze[i] = numb(a);
    }
    for(int i = 0; i < n; i ++) {
        scanf("%d", &a);
        ich[i] = numb(a);
    }
    sort(ich.begin(), ich.end());
    for(unsigned int d = 0; d < 1 << l; d ++) {
//         printf("-- próbujemy d == %d\n", d);
        for(int i = 0; i < n; i ++)
            proba[i] = nasze[i] xor d;
        sort(proba.begin(), proba.end());
//         printf("  --- %d %d\n", proba[0], ich[0]);
        if(equal(proba.begin(), proba.end(), ich.begin()))
            m = min(m, __builtin_popcount(d));
    }
    if(m == 1100)
        printf("NOT POSSIBLE");
    else
        printf("%d", m);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }
}