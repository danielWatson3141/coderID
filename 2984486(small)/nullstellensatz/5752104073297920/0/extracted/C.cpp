


/*
    Prob:   Google Code Jam Round1A 2014
    Author: peanut
    Time:   26/04/14 11:04
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 1000 + 50;

int T, n;

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        string post = argv[1][0] == 's' ? 
                      "-small-attempt" + string(argv[2]):
                      "-large";  
        string input_file  = string(argv[0]) + post + ".in",
               output_file = string(argv[0]) + post + ".out";
        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);
    }
    
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d", &n);
        int cnt = 0;
        for (int k = 0; k < n; ++ k) {
            int p; scanf("%d", &p);
            cnt += (p < k);
        }
        printf("Case #%d: ", testcase);
        if (cnt >= n / 2 - 10)
            puts("GOOD");
        else
            puts("BAD");
    }
    
    return 0;
}
