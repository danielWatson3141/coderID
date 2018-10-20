#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>

using namespace std;

inline void readData(int& n,int& l,vector< string >& a, vector<string>& b,istream& cin) {
    cin >> n >> l;
    cin.get();
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }   
}


inline long long getState(const string& s) {
    long long ret = 0;
    for (auto& c : s) {
        ret = ret << 1LL | (c - '0');
    }

    return ret;
}

inline int bitCnt(long long x) {
    int ret = 0;
    while (x) {
        x &= (x - 1);
        ret++;
    }
    return ret;
}


string solve(istream& cin) {
    int n, l;
    vector<string> a, b;
    readData(n, l, a, b, cin);
    vector<long long> s1(n);
    vector<long long> s2(n);
    for (int i = 0; i < n; i++ ) {
        s1[i] = getState(a[i]);
        s2[i] = getState(b[i]);
    }

    sort (s2.begin(), s2.end());
    /*
    string brute;
    if (l <= 16) {
        int ret = l + 1;
        for (int i = 0; i < (1 << l); i++) {
            vector< long long > s3 = s1; 
            int cost = bitCnt(i);
            for (int j = 0; j < n; j++) {
                s3[j] ^= i;
            }
            
            sort (s3.begin(), s3.end());
            if (s3 == s2 && cost < ret) {
                ret = cost;
            }
        }

        if (ret != l + 1) {
            ostringstream oss;
            oss << ret;
            brute = oss.str();
        } else
        brute = "NOT POSSIBLE";

    }
    */
    int ret = l + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long mask = s1[i] ^ s2[j];
            vector<long long> s3 = s1;
            for (int k = 0; k < n; k++) {
                s3[k] ^= mask; 
            }

            sort (s3.begin(),s3.end());
            if (s2 == s3) {
                int cost = bitCnt(mask);
                if (cost < ret) {
                    ret = cost;
                }
            }
        }
    }

    if (ret != l + 1) {
        ostringstream oss;
        oss << ret;
        return oss.str();
    }
    return "NOT POSSIBLE";
}


int main() {
    ifstream cin("test.in");
    ofstream cout("test.out");
    int testCount;
    cin >> testCount;
    for (int testCase = 1; testCase <= testCount; testCase++) {
        cout << "Case #" << testCase << ": ";  
        cout << solve(cin) << "\n";
    }   
    return 0;
}
