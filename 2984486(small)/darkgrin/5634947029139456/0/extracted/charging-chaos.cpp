#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define loop(i,n) for(int i=0;i<n;i++)
#define INF 0xfffffff
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned int ui;

map<pii, ul> d;

ul bs(int num, int i) {
    pii p = make_pair(num, i);
    if (d.find(p) != d.end())
        return d[p];
    d[p] = (num ^= (1<<i));
    return d[p];
}

ul solve(int toggled, vui &first, vui &second, int n, int c) {
    // If possibility if we don't toggle bit c
    if (first == second) {
        return toggled;
    } 
    if (c == n) {
        return INF;
    }
    ul min = INF;
    vui fst1 = first;
    ul num = solve(toggled, fst1, second, n, c+1);
    if (num < min)
        min = num;
    for(int i = c; i<n; i++) {
        vui fst = first;
        loop(j, fst.size()) {
            fst[j] = bs(fst[j], i);
        }
        sort(fst.begin(), fst.end());
//        printf("Changing bit %d\n", i);
//        loop(j, fst.size()) {
//            printf("%lu ", fst[j]);
//        }
//        printf("\n");
        int num = solve(toggled+1, fst, second, n, i+1);
        if (num < min) {
            min = num;
        }
    }
    return min;
}

int main() {
    int t, n, l;
    cin >> t;

    int casenum = 1;
    while (t--) {
        vui first;
        vui second;
        string s;
        cin >> n >> l;
        // first
        loop(i, n) {
            cin >> s;
            const char *c = s.c_str();
            char *end;
            ul x = strtol(c, &end, 2);
            first.push_back(x);
        }

        loop(i, n) {
            cin >> s;
            const char *c = s.c_str();
            char *end;
            ul x = strtol(c, &end, 2);
            second.push_back(x);
            //printf("%lu\n", x);
        }
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        ul answer = solve(0, first, second, l, 0);
        cout << "Case #" << casenum << ": ";
        if (answer == INF) {
            cout << "NOT POSSIBLE" << endl;
        } else {
            cout << answer << endl;
        }
        casenum++;
    }
}
