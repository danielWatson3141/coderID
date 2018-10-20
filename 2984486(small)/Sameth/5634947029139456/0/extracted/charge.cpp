#include <set>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main () {
    int t, n, l, bestsol, actsol;
    vector <vector <bool> > devices, outlets;
    vector <bool> switches;
    set <long long> maaagic;
    long long x;
    bool issolution;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases ++) {
        scanf("%d %d", &n, &l);
        bestsol = n+1000;
        devices.resize(n, vector <bool> (l, false));
        outlets.resize(n, vector <bool> (l, false));
        switches.resize(l, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                scanf("%1lld", &x);
                devices [i] [j] = (x == 1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                scanf("%1lld", &x);
                outlets [i] [j] = (x == 1);
            }
        }
        for (int i = 0; i < n; i++) {
            actsol = 0;
            issolution = true;
            for (int j = 0; j < l; j++) {
                switches[j] = (devices [0] [j] != outlets [i] [j]);
                if (switches [j]) actsol ++;
            }
            for (int j = 0; j < n; j++) {
                x = 0;
                for (int k = 0; k < l; k++) {
                    x <<= 1;
                    if (switches [k] != outlets [j] [k]) x++;
                }
                maaagic.insert(x);
            }
            for (int j = 0; j < n; j++) {
                x = 0;
                for (int k = 0; k < l; k++) {
                    x <<= 1;
                    if (devices [j] [k]) x++;
                }
                if (maaagic.find (x) == maaagic.end()) issolution = false;
                maaagic.erase(x);
            }
            if (issolution && maaagic.empty()) {
                bestsol = min (bestsol, actsol);
            }

            
            maaagic.clear();
        }



        printf("Case #%d: ", cases);
        if (bestsol == n+1000) printf("NOT POSSIBLE\n");
        else printf("%d\n", bestsol);
        devices.clear();
        outlets.clear();
    }
}
