#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cstring>
#include <string>
using namespace std;

#define pairii pair<int, int>
#define llong long long
#define pb push_back
#define sortall(x) sort((x).begin(), (x).end())
#define INFI  numeric_limits<int>::max()
#define INFLL numeric_limits<llong>::max()
#define INFD  numeric_limits<double>::max()
#define FOR(i,s,n) for (int (i) = (s); (i) < (n); (i)++)
#define FORZ(i,n) FOR((i),0,(n))

int n,l;

void solve() {
    scanf("%d %d", &n, &l);
    vector<string> outlet(n);
    vector<string> dev(n);
    FORZ(i,n) cin >> outlet[i];
    FORZ(i,n) cin >> dev[i];
    sortall(dev);
    int res = -1;
    FORZ(i,n) {
        bool sw[n];
        int cnt = 0;
        vector<string> tmpol = outlet;
        FORZ(j,l) {
            if (dev[0][j] != tmpol[i][j]) {
                sw[j] = true;
                cnt++;
            }
            else sw[j] = false;
        }
        FORZ(j,l) {
            if (sw[j]) {
                FORZ(k,n) {
                    if (tmpol[k][j] == '1') tmpol[k][j] = '0';
                    else tmpol[k][j] = '1';
                }
            }
        }
        sortall(tmpol);
        if (tmpol == dev) {
            if (res == -1) res = cnt;
            else res = min(res,cnt);
        }
    }
    if (res >= 0) printf("%d\n", res);
    else printf("NOT POSSIBLE\n");
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    int t;
    scanf("%d", &t);
    FOR(i,1,t+1) {
        printf("Case #%d: ", i);
        solve();
    }
    
    return 0;
}

