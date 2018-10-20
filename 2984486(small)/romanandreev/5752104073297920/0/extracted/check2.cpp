#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int n;
int a[1010];
int was[1010];
int kc[1010];
double mn1[1010];
double mn2[1010];
int rnd(int a) {
    return ((rand() << 15) + rand()) % a;
}
int rnd(int a, int b) {
    return a + rnd(b - a + 1);
}
void gen1() {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int p = rnd(i, n - 1);
        swap(a[i], a[p]);
    }
}
void gen2() {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int p = rnd(0, n - 1);
        swap(a[i], a[p]);
    }
}
double f() {
    double res = 0;
    for (int i = 1; i <= 1; i++) {
       // cerr<<mn1[i]<<" "<<mn2[i]<<endl;
        if (kc[i] > (mn1[i] + mn2[i]) / 2)
            res++;
    }
    return res;
}
void calc() {
    for (int i = 0; i <= n; i++) {
        was[i] = 0;
        kc[i] = 0;
    }    
    /*for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                kc[2]++;
            }
        }
    } */
    for (int i = 0; i < n; i++) {
        kc[1] += ((i - a[i]) >= 0);
//        kc[2] += pow(abs(i - a[i]), 2);
//        kc[3] += pow(abs(i - a[i]), 3);
    }
    /*int kcc = 0;
    for (int i = 0; i < n; i++) if (was[i] == 0) {
        int cnt = 0;
        kcc++;
        int cur = i;
        while (was[cur] == 0) {
            was[cur] = 1;
            cur = a[cur];
            cnt++;
        }
        kc[3] -= cnt;
    }
    kc[3] /= kcc;*/
}
void pre() {
    srand(23917);
    n = 1000;
    int k = 1000;
    for (int i = 0; i < k; i++) {        
        gen1();
        calc();
        for (int j = 0; j <= n; j++) {
            mn1[j] += kc[j];
        }
    }
    for (int j = 0; j <= n; j++) {
        mn1[j] /= k;
    }

    for (int i = 0; i < k; i++) {
        gen2();
        calc();
        for (int j = 0; j <= n; j++) {
            mn2[j] += kc[j];
        }
    }
    for (int j = 0; j <= n; j++) {
        mn2[j] /= k;
    }                  
//    cerr<<(mn1[1] + mn2[1]) / 2<<endl;
    /*for (int j = 0; j <= n; j++) {
        cerr<<mn1[j]<<" ";
    }
    cerr<<endl;
    for (int j = 0; j <= n; j++) {
        cerr<<mn2[j]<<" ";
    } */
}
void solve() {
    int T;
    scanf("%d", &T);
    int res = 0;
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d: ", ti);
        int ans0;
    if (0)
        scanf("%d", &ans0);    
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        calc();
//        cerr<<ans0<<" "<<kc[1]<<endl;
        if (f() >= 1) {
            if (ans0 == 1) {
                res++;
            }
            printf("GOOD\n");
        } else {
            if (ans0 == 2) {
                res++;
            }
            printf("BAD\n");
        }
    }
    cerr<<res<<endl;
}
int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    pre();
    solve();
    return 0;
}
