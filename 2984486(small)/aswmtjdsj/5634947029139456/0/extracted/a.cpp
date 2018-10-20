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

char neg(char a) {
    if(a == '0') return '1';
    if(a == '1') return '0';
}

int main(){
    int T;
    cin >> T;
    for(int c = 1; c <= T; c++) {
        int n, l;
#define MAXN 155
        string output[MAXN], switched[MAXN], needed[MAXN];
        cin >> n >> l;
        for(int i = 0;i < n;i ++) {
            cin >> output[i];
        }
        for(int i = 0;i < n;i ++) {
            cin >> needed[i];
        }
        sort(needed, needed + n);
        int ans = l + 1;
        for(int i = 0; i < (1 << l); i++) {
            int temp = 0;
            for(int k = 0; k < n; k++) {
                switched[k] = output[k];
            }
            for(int j = 0; j < l; j++) {
                if((1 << j) & i) {
                    temp++;
                    for(int k = 0; k < n; k++) {
                        switched[k][j] = neg(switched[k][j]);
                    }
                }
            }
            sort(switched, switched + n);
            /*for(int k = 0; k < n; k++) {
                cout << switched[k] << ' ';
            } cout << "---" << endl;
            for(int k = 0; k < n; k++) {
                cout << needed[k] << ' ';
            } cout << endl; */
            bool mark = true;
            for(int k = 0; k < n; k++) {
                if(switched[k] != needed[k]) {
                    mark = false;
                    break;
                }
            }
            if(mark && temp < ans) {
                ans = temp;
            }
        }
        printf("Case #%d: ", c);
        if(ans == l + 1) {
            puts("NOT POSSIBLE");
        }
        else {
            printf("%d\n", ans);
        }
    }
}
