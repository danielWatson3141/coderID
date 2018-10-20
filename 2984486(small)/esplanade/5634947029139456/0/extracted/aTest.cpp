//#define __test__aTest__
#ifndef __test__aTest__

#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <stdexcept>

using namespace std;

#define ll long long
#define ull size_t

void process(int index) {
    int N, L;
    cin >> N >> L;
    vector<string> v1(N), v2(N);
    for (int i = 0; i < N; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<string> pattern;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            string s(L, '0');
            for (int k = 0; k < L; k++) {
                if (v1[i][k] != v2[j][k])
                    s[k] = '1';
            }
            pattern.push_back(s);
        }
    }
    sort(pattern.begin(), pattern.end());
    pattern.erase(unique(pattern.begin(), pattern.end()), pattern.end());
    int l = -1;
    for (int i = 0; i < pattern.size(); i++) {
        vector<string> v = v1;
        for (int j = 0; j < L; j++) {
            if (pattern[i][j] == '1') {
                for (int k = 0; k < N; k++) {
                    if (v[k][j] == '0') v[k][j] = '1';
                    else                v[k][j] = '0';
                }
            }
        }
        sort(v.begin(), v.end());
        if (v == v2) {
            int c = 0;
            for (int k = 0; k < L; k++) {
                if (pattern[i][k] == '1')
                    c++;
            }
            if (l == -1)  l = c;
            else          l = min(l, c);
        }
    }
    if (l == -1)  cout<<"Case #"<<index<<": NOT POSSIBLE"<<endl;
    else          cout<<"Case #"<<index<<": "<<l<<endl;
}

int main() {
    
    freopen("/Users/zishirs/Documents/workspace/test/test/test.txt", "r", stdin);
    freopen("/Users/zishirs/Documents/workspace/test/test/output.txt", "w", stdout);
    
    
    
    int T;
    cin >> T;
    for (int index = 1; index <= T; ++index) {
        //cout<<"Case #"<<index<<": ";
        process(index);
    }
    
    /*
    int F;
    cin >> F;
    int n;
    vector<long long> v;
    while (cin >> n) {
        v.push_back(n);
    }
    vector<int> v1(v.begin(), v.begin() + v.size()/2), v2(v.begin() + v.size()/2, v.end());
     */ 
    
    return 0;
}

#endif