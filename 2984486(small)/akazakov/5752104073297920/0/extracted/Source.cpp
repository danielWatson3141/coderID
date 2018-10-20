#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

#include <algorithm>
#include <cmath>
#include <ctime>

#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define uLL unsigned long long
#define BIG 1000000000

using namespace std;

#define PROBLEM "C"

void solveTestCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int inv = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            inv += (a[i] > a[j]);
        }
    }
    if ((inv < n * (n + 1) / 4) ^ (rand() % 10 == 1)) {
        cout << "BAD";
    } else {
        cout << "GOOD"; 
    }
    cout << endl;
}

int main() {
    srand(time(0));
    freopen("input_" PROBLEM ".txt", "rt", stdin); //-V530
    freopen("output.txt", "wt", stdout); //-V530
    uLL num_tests;
    cin >> num_tests;
    for (uLL i = 1; i <= num_tests; ++i) {
        cerr << i << "\r" << flush;
        cout << "Case #" << i << ": ";
        solveTestCase();
    }
    return 0;
}