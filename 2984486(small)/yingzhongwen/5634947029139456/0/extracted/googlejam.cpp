#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <list>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <stack>
#include <iomanip>

using namespace std;

ofstream fout ("A-small-attempt3.out");
ifstream fin ("A-small-attempt3.in");

int main() {
    int T;
    fin >> T;
    for (int t = 1; t <= T; t++) {
        int N, L;
        fin >> N >> L;
        fout << "Case #" << t << ": ";
        vector<string> input(N);
        for (int i = 0; i < N; ++i) fin >> input[i];
        sort(input.begin(), input.end());
        vector<string> target(N);
        for (int i = 0; i < N; ++i) fin >> target[i];
        sort(target.begin(), target.end());
        if (input == target) {
            fout << 0 << endl;
            continue;
        }
        int ans = L+1;
        for (int i = 0; i <= ((1 << L) - 1); ++i) {
            int tmp = i;
            int k = 0;
            vector<string> inpu = input;
            while (tmp > 0) {
                //cout << k << endl;
                if (tmp & 1) {
                    for (int j = 0; j < N; ++j) inpu[j][k] = (inpu[j][k] == '0'? '1' : '0');
                }
                tmp >>= 1;
                k++;
            }
            sort(inpu.begin(), inpu.end());
            if (inpu == target) {
                //cout << "i = " << i << endl;
                int tmp1 = i;
                int index = 0;
                while (tmp1 > 0) {
                    if (tmp1 & 1) index++;
                    tmp1 >>= 1;
                }
                ans = min(ans, index);
            }
        }
        if (ans == L+1) fout << "NOT POSSIBLE" << endl;
        else fout << ans << endl;
    }
    return 0;
}
