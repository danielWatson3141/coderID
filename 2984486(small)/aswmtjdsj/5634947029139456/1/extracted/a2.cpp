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
        string output[MAXN], needed[MAXN], switched_s[MAXN];
        cin >> n >> l;
        for(int i = 0;i < n;i ++) {
            cin >> output[i];
            switched_s[i] = output[i];
        }
        for(int i = 0;i < n;i ++) {
            cin >> needed[i];
        }
        int ans = l + 1;
        sort(output, output + n);
        sort(needed, needed + n);

        vector<bool> switched(l);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int temp = 0;
                for(int k = 0; k < l; k++) {
                    if(needed[j][k] != output[i][k]) {
                        switched[k] = 1;
                        temp++;
                    }
                    else {
                        switched[k] = 0;
                    }
                }
                for(int p = 0; p < n; p++) {
                    for(int k = 0; k < l; k++) {
                        if(switched[k]) {
                            switched_s[p][k] = neg(output[p][k]);
                        }
                        else {
                            switched_s[p][k] = output[p][k];
                        }
                    }
                }
                sort(switched_s, switched_s + n);
                bool cur = true;
                for(int p = 0; p < n; p++) {
                    if(switched_s[p] != needed[p]) {
                        cur = false;
                        break;
                    }
                }
                if(cur) {
                    ans = min(ans, temp);
                }
            }
        }

        printf("Case #%d: ", c);
        if(ans > l) {
            puts("NOT POSSIBLE");
        }
        else {
            printf("%d\n", ans);
        }
    }
}
