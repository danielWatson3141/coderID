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


int n, len, res;
int a[200], b[200];


int bin2dec(string t) {
    int x = 0;
    for (int i=0; i<len; i++) if (t[i]=='1') {
        x = x | (1<<i);
    }
    return x;
}

void input() {
    string tmp;
    cin >> n >> len;
    for (int i=0; i<n; i++) { cin >> tmp; a[i] = bin2dec(tmp); }
    for (int i=0; i<n; i++) { cin >> tmp; b[i] = bin2dec(tmp); }
    
    //for (int i=0; i<n; i++) cout << a[i] << " "; cout << endl;
    //for (int i=0; i<n; i++) cout << b[i] << " "; cout << endl;
    sort(b, b+n);

}

void solve() {
    int cnt; bool ok;
    int c[200];

    //
    res = INT_MAX;
    for (int i=0; i<n; i++) {
        //
        cnt = 0;
        for (int j=0; j<len; j++) if ( ((a[i]>>j)&1) != ((b[0]>>j)&1) ) cnt++;    
        if (cnt >= res) continue;

        //
        for (int k=0; k<n; k++) c[k] = a[k];
        for (int j=0; j<len; j++) if ( ((a[i]>>j)&1) != ((b[0]>>j)&1) ) {
            for (int k=0; k<n; k++) {
                if ( ((c[k]>>j)&1) == 0) c[k] = c[k] | (1<<j);
                else c[k] = c[k] - (1<<j);
            }
        }    

        //
        ok = true;
        sort(c, c+n);
        for (int k=0; k<n; k++) if (c[k] != b[k]) { ok = false; break; }

        if (ok) res = cnt;
    }
}



int main() {
    int i, num_test;
    
    //
    cin >> num_test;
    for (int i=1; i<=num_test; i++) {
        input();
        solve();
        printf("Case #%d: ", i);
        if (res == INT_MAX) printf("NOT POSSIBLE\n"); else printf("%d\n", res);
    }

    //
    return 0;
}
