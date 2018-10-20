#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <float.h>
#include <fstream>

using namespace std;

typedef long long ll;

int N;
int L;

int main() {
    ifstream in("A-small-attempt0.in");
    ofstream out("A-small-attempt0.out");
    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> N; in >> L;
        vector<string> op(N);
        vector<string> de(N);
        for (int n = 0; n < N; n++) {
            in >> op[n];
        }
        for (int n = 0; n < N; n++) {
            in >> de[n];
        }
        sort(de.begin(), de.end());
        int mi = L + 1;
        for (int i = 0; i < (1 << L); i++) {
            vector<string> v = op;
            int cnt = 0;
            for (int j = 0; j < L; j++) {
                if ((i & (1 << j))) {
                    cnt++;
                    for (int k = 0; k < N; k++) {
                        v[k][j] = (v[k][j] == '1' ? '0' : '1');
                    }
                }
            }
            sort(v.begin(), v.end());
            if (v == de) {
                mi = min(mi, cnt);
            }
        }
        if (mi == L + 1) {
            out << "Case #" << t + 1 << ": " << "NOT POSSIBLE" << endl;
        } else {
            out << "Case #" << t + 1 << ": " << mi << endl;
        }
    }
//    getchar();
    return 0;
}
