#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string sw(string a, string b) {
    string ret;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == b[i]) ret.push_back('0');
        else ret.push_back('1');
    }
    return ret;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, N, L;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int ans = -1;
        cin >> N >> L;
        vector<string> e(N);
        vector<string> d(N);
        for(int n = 0; n < N; n++) {
            cin >> e[n];
        }
        for(int n = 0; n < N; n++) {
            cin >> d[n];
        }
        for(int i = 0; i < N; i++) {
            string need = sw(d[0], e[i]);
            vector<string> e2 = e;
            for(int n = 0; n < N; n++) {
                for(int j = 0; j < L; j++) {
                    if(need[j] == '1') {
                        if(e2[n][j] == '0') e2[n][j] = '1';
                        else e2[n][j] = '0';
                    }
                }
            }
            int tans = 0;
            for(int j = 0; j < L; j++) {
                if(need[j] == '1') tans++;
            }
            bool good = true;
            for(int n = 0; n < N; n++) {
                if(find(e2.begin(), e2.end(), d[n]) == e2.end()) good = false;
            }
            if(good) {
                if(ans == -1) ans = tans;
                else ans = min(tans, ans);
            }
        }
        cout << "Case #" << t << ": ";
        if(ans == -1) cout << "NOT POSSIBLE\n";
        else cout << ans << endl;
    }
}