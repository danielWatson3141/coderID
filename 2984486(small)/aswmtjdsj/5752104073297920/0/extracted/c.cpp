#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>

using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

#define MULTIPLE "Bad magician!"
#define NOANS "Volunteer cheated!"

typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int inf = INT_MAX;
const double eps = 1e-8;

int sgn(double x) {
    return fabs(x) < eps ? 0:x < -eps ? -1:1;
}

int main(){
    int T;
    cin >> T;
    for(int c = 1; c <= T; c++) {
        int a[1005];
        int n;
        cin >> n;
        int mark = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 999) {
                mark = i;
            }
        }
        printf("Case #%d: ", c);
        if(mark < 500) {
            puts("GOOD");
        }
        else {
            puts("BAD");
        }
    }
}
