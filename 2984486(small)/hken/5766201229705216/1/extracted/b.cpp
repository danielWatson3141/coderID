#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <memory.h>
 
using namespace std;
 
#define LL               long long
#define pb               push_back
#define mp               make_pair
typedef vector <int>     vi; 
typedef vector <string>  vs;
typedef pair   <int,int> pii;


int m, n, res;
pii a[2000];
int f[1001];
bool dx[1001], dx2[1001];

void input() {
    int u, v;

    //
    cin >> n; m = 0;
    for (int i=0; i<n-1; i++) {
        cin >> u >> v; u--; v--;
        a[m++] = mp(u,v);
        a[m++] = mp(v,u);
    }
    
    //
    sort(a, a+m);
    f[0] = 0;
    for (int i=1; i<m; i++) if (a[i].first != a[i-1].first) {
        f[a[i].first] = i;
    }
    f[n] = m;
    //for (int i=0; i<=n; i++) { cerr << f[i] << " "; } cerr << endl;
    //for (int i=0; i<m; i++) { cerr << a[i].first << " " << a[i].second << endl; }
}

int trimall(int x) {
    int cnt = 0; dx2[x] = false;
    for (int i=f[x]; i<f[x+1]; i++) if (dx[a[i].second] && dx2[a[i].second]) {
        cnt += trimall(a[i].second);
    }
    return cnt+1;
}

int trimt(int x) {
    //cerr << "node " << x << endl;

    //
    int t,ta, cnt = 0, s=0, r1 = INT_MAX, r1a=0, r2 = INT_MAX, r2a = 0;
    dx[x] = false;
    for (int i=f[x]; i<f[x+1]; i++) if (dx[a[i].second]) cnt++;
    //cerr << "    cnt = " << cnt << endl; 

    //
    if (cnt == 0) return 0;
    if (cnt == 1) {
        for (int i=f[x]; i<f[x+1]; i++) if (dx[a[i].second]) {
            memset(dx2, true, sizeof(dx2));
            r1 = trimall(a[i].second);
            return r1;
        }
    }

    //
    for (int i=f[x]; i<f[x+1]; i++) if (dx[a[i].second]) {
        memset(dx2, true, sizeof(dx2));
        ta = trimall(a[i].second); t = trimt(a[i].second);
        //cerr << "   adj=" << a[i].second << "  ta = " << ta << "   t = " << t << endl;
        s += ta;
        if ( (t-ta) < (r1-r1a) ) { r2=r1; r2a=r1a; r1=t; r1a=ta; }
        else if ( (t-ta) < (r2-r2a) ) { r2=t; r2a=ta; }
    }
    return (s + r1-r1a + r2-r2a);
}

void solve() {
    int tmp;

    //
    res = n-1;
    for (int i=0; i<n; i++) {
        //cerr << "----- root = " << i << " ---- " << endl;
        memset(dx, true, sizeof(dx));
        tmp = trimt(i);
        res = min(res, tmp);
        //cerr << "      need to delete " << tmp << endl;
    }
}




int main() {
    int i, num_test;
    cin >> num_test;
    for (int i=1; i<=num_test; i++) {
        input();
        solve();
        printf("Case #%d: %d\n", i, res);
    }
    return 0;
}
