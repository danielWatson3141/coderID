#pragma comment(linker, "/STACK:268435456")
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <numeric>
#include <bitset>

using namespace std;

int main() {
    string name = "A-large";
    string path = "";

    freopen((path + name + ".in").c_str(), "r", stdin);
    freopen((path + name + ".out").c_str(), "w", stdout);

    int test_cases;
    cin >> test_cases;

    for (int test_case = 1; test_case <= test_cases; test_case++) {

        int n;
        cin >> n;
        int L;
        cin >> L;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            bitset<100> t;
            cin >> t;
            a[i] = t.to_ullong();
        }

        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            bitset<100> t;
            cin >> t;
            b[i] = t.to_ullong();
        }

        sort(b.begin(), b.end());
        
        int res = 1000;

        for (int i = 0; i < n; i++) {
            long long x = a[i] ^ b[0];
            vector<long long> a1 = a;
            for (int j = 0; j < n; j++) {
                a1[j] ^= x;
            }
            sort(a1.begin(), a1.end());
            if (a1 == b) {
                res = min(res, __builtin_popcount(x >> 32) + __builtin_popcount(x & 0xFFFFFFFF));
            }
        }
       
        cout << "Case #" << test_case << ": ";
        if (res == 1000)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << res << endl;
    }

    fclose(stdout);
    fclose(stdin);
    return 0;
}
