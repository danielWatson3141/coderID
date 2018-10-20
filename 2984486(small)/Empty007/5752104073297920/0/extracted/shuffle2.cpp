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

typedef long long ll;

int main() { 
    int N, T;

    cin >> T;

    int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    double totm1 = 157252, totm2 = 166735, totd1 = 3.66492e+13, totd2 = 3.88601e+13;

    REP(tc, T) {
        cin >> N;
        int A[N];
        REP(i, N) {
            cin >> A[i];
        }

        double res = 0;

        REP(i, N) {
            res += pow((A[i] - i), 2.0);
        }
    
        double m1 = res/N;
        double d1 = 0;

        REP(i, N) {
            d1 += pow((pow((A[i] - i), 2.0) - m1), 2.0);
        }

        if (fabs(totd1 - d1) <= fabs(totd2 - d1)) {
            printf("Case #%d: GOOD\n", tc+1);
        }
        else 
            printf("Case #%d: BAD\n", tc+1);
    }
	
	return 0;
}
