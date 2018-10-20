/*
 * Author: fatboy_cw
 * Created Time:  2014/4/26 10:04:30
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int t, n, l, ca;
vector<string> v1, v2;
set<string> s1, s2;

int check(int r) {
    vector<int> flip;
    for(int i = 0; i < l; i++) {
        if(v1[r][i] != v2[0][i]) {
            flip.push_back(i);
        }
    }
    s1.clear();
    s2.clear();
    for(int i = 0; i < n; i++) {
        string s = v1[i];
        for(int j = 0; j < flip.size(); j++) {
            s[flip[j]] = '1' - s[flip[j]] + '0';
        }
        s1.insert(s);
    }
    for(int i = 0; i < n; i++) {
        s2.insert(v2[i]);
    }
    if(s1 == s2) return flip.size();
    return maxint;
}


int main() {
    freopen("A2.in", "r", stdin);
    freopen("A2.out", "w", stdout);
    cin >> t;
    while(t--) {
        v1.clear();
        v2.clear();
        cin >> n >> l;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v1.push_back(s);
        }
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v2.push_back(s);
        }
        int res = maxint;
        for(int i = 0; i < n; i++) {
            get_min(res, check(i));
        }
        if(res == maxint) printf("Case #%d: NOT POSSIBLE\n", ++ca);
        else printf("Case #%d: %d\n", ++ca, res);
    }
    return 0;
}

