


/*
    Prob:   Google Code Jam Round1A 2014
    Author: peanut
    Time:   26/04/14 09:29
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 150 + 50;

int T, n, L;
long long outlet[MaxN], device[MaxN], flip[MaxN * MaxN];

long long change(string tmp) {
    long long res = 0;
    for (int k = 0; k < tmp.length(); ++ k)
        res = (res << 1) + (tmp[k] - '0');
    return res;
}

int digit(long long tmp) {
    return tmp <= 0 ? 0 : digit(tmp - (tmp & -tmp)) + 1;
}

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
    
    cin >> T;
    for (int testcase = 1; testcase <= T; ++ testcase) {
        cin >> n >> L;
        for (int k = 0; k < n; ++ k) {
            string tmp; cin >> tmp;
            outlet[k] = change(tmp);
        }
        for (int k = 0; k < n; ++ k) {
            string tmp; cin >> tmp;
            device[k] = change(tmp);
        }
            
        int size = 0;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j)
                flip[size ++] = outlet[i] ^ device[j];
        sort(flip, flip + size);
            
        int res = -1, cnt = 0;
        for (int k = 0; k < size; ++ k) {
            if (k == 0 || flip[k] == flip[k - 1]) ++ cnt; else cnt = 1;
            if (cnt == n) {
                if (res < 0 || digit(flip[k]) < res)
                    res = digit(flip[k]);
            }
        }
        printf("Case #%d: ", testcase);
        if (res < 0) puts("NOT POSSIBLE"); else printf("%d\n", res);
    }
    
    return 0;
}
