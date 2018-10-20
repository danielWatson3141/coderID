#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int N = 155;
int n , m;
string a[N] , b[N] , c[N];
int main () {
#ifndef ONLINE_JUDGE
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    cin >> t;
    while (t --) {
        cin >> n >> m;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cin >> b[i];
        }
        sort (b , b + n);
        int ans = m + 1;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                for (int k = 0 ; k < n ; k ++) {
                    c[k] = a[k];
                }
                int cnt = 0;
                for (int k = 0 ; k < m ; k ++) {
                    if (a[i][k] != b[j][k]) {
                        cnt ++;
                        for (int r = 0 ; r < n ; r ++) {
                            c[r][k] = 1 - (c[r][k] - '0') + '0';
                        }
                    }
                }
                sort (c , c + n);
                int ok = 1;
                for (int k = 0 ; k < n ; k ++) {
                    if (b[k] != c[k]) {
                        ok = 0;
                    }
                }
                if (ok) ans = min (ans , cnt);
            }
        }
        cout << "Case #" << ++ cas << ": ";
        if (ans > m) {
            puts ("NOT POSSIBLE");
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}