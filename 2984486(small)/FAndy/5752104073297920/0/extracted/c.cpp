#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int MAXT = 120;
int T, n;
vector<vector<int> > a;
int label[MAXT];

void solve() {
    vector< pair<int, int> > tv;
    for (int i = 0; i < T; i++) {
        vector<int> &b = a[i];
        int cnt = 0;
        for (int j = 0; j < b.size(); j++)
            for (int k = 0; k < j; k++)
                if (b[j] > b[k])
                    cnt++;
        tv.push_back(make_pair(cnt, i));
    }
    
    sort(tv.begin(), tv.end());
    
    for (int i = 0; i < T / 2; i++)
        label[tv[i].second] = 1;
    for (int i = T / 2; i < T; i++)
        label[tv[i].second] = 0;
}

int main() {        
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        vector<int> b;
        int val;
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            b.push_back(val);
        }
        a.push_back(b);
    }
    solve();
    
    for (int t = 1; t <= T; t++) {
        
        printf("Case #%d: %s\n", t, label[t - 1] > 0 ? "GOOD" : "BAD");
                
    }
}

