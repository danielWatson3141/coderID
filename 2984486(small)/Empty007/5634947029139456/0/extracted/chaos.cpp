#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

string A[165];
string B[165];
string O[165];

int main() { 

    int N, L, T;

    cin >> T;
    
    REP(tc, T) {
        cin >> N >> L;
        REP(i, N) {
            cin >> O[i];
        }

        REP(i, N) {
            cin >> B[i];
        }

        sort(B, B + N);

        int res = 1000;

        REP(i, (1<<L)) {
            REP(k, N) {
                A[k] = O[k];
            }

            REP(j, L) {
                if (i & (1<<j)) {
                    REP(k, N) {
                        if (A[k][j] == '0') A[k][j] = '1';
                        else A[k][j] = '0';
                    }
                }
            }
            sort(A, A + N);

            bool bo = true;
            
            REP(k, N) {
                if (A[k] != B[k]) {
                    bo = false;
                    break;
                }
            }
            
            if (bo) {
                res = min(res, int(__builtin_popcount(i)));
            }
        }

        if (res == 1000) {
            printf("Case #%d: NOT POSSIBLE\n", tc+1);
        }
        else 
            printf("Case #%d: %d\n", tc+1, res);
    }
	
	return 0;
}
