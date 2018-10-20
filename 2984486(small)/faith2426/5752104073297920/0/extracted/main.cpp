#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("in.in");
    ofstream ofs("out.out");

    srand(time(NULL));

    int T;
    ifs >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        ifs >> N;

        int *nums = (int *)calloc(N, sizeof(int));
        int r = rand() % 2;

        for (int i = 0; i < N; ++i) {
            ifs >> nums[i];
        }

        for (int i = 0; i < N; ++i) {
            if (nums[i] == i) {
                goto BAD;
            }
        }

        if (r == 0) {
            ofs << "Case #" << t << ": GOOD" << endl;
            free(nums);
            continue;
        }

BAD:
        ofs << "Case #" << t << ": BAD" << endl;
        free(nums);
    }

    return 0;
}
