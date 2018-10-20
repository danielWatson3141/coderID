#include <iostream>
#include <cstdio>

#include <cstdlib>
#include <cmath>
#include <cstring>

#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

#include <stdint.h>
using namespace std;

#define get_max(x, y) ((x)>(y)?(x):(y))
#define get_min(x, y) ((x)<(y)?(x):(y)) 
#define set_zero(a) (memset(a, 0, sizeof(a)))

#define FLOAT_LIMIT 1e-8
#define feq(a, b) (fabs((a) - (b)) <= FLOAT_LIMIT ? true : false)
template <class type> void do_swap(type &a, type &b) {type t = a; a = b; b = t;}

int n, l;

string arr[200];
string tar[200];
int sign[50];

bool cmp(string a , string b) {
    return a > b;
}


int main() {
    int t;
    freopen("A-small-attempt6.in","r",stdin);
    freopen("A-small-attempt6.out","w",stdout);
    int cas = 0;
    scanf("%d", &t);
    while(t--) {
        cas++;
        scanf("%d %d", &n, &l);
        for (int i = 0 ; i < n;  ++i) {
            cin>>arr[i];
        }
        for (int i = 0 ; i < n;  ++i) {
            cin>>tar[i];
        }
        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < l ; ++j) {
                arr[i][j] -= '0';
                tar[i][j] -= '0';
            }
        }
        bool imp = false;
        string cmp; 
        int ans = 0x7fffffff;
        sort(arr, arr +n);
        do {
            imp = true;
            cmp = "";
            for (int i = 0 ; i < l ; ++i) {
                cmp[i] = (arr[0][i] ^ tar[0][i]);
            }
            
            for (int j = 1 ; j < n;  ++j) {
                for (int i = 0 ; i < l ; ++i) {
                    if (cmp[i] != (arr[j][i] ^ tar[j][i])) {
                        imp = false;
                        break;
                    }
                }
                if (!imp) break;
            }
            if (imp) {
                int tmp = 0;
                for (int i = 0 ; i <l ; ++i) {
                    if (cmp[i] == 1) tmp++;
                }
                ans = get_min(ans, tmp);
            }
        } while(next_permutation(arr, arr + n));

        if (ans == 0x7fffffff) {
            printf("Case #%d: NOT POSSIBLE\n", cas);
        } else {
            printf("Case #%d: %d\n",cas, ans);
        }
    }
    return 0;
}
