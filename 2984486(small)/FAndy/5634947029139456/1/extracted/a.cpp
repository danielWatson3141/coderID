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

int n, l;
vector<string> a;
vector<string> b;
char buf[10000];
int ans;

inline char change(char ch) {
    if (ch == '1')
        return '0';
    else return '1';
}

void solve() {
    set<string> ts;
    for (int i = 0; i < n; i++) ts.insert(b[i]);
    
    ans = -1;
    for (int i = 0; i < n; i++) {
        vector<int> c;
        for (int j = 0; j < l; j++)
            if (a[0][j] != b[i][j])
                c.push_back(j);
        if (c.size() >= ans && ans >= 0)
            continue;
        bool flag = true;
        for (int j = 1; j < n; j++) {
            strcpy(buf, a[j].c_str());
            for (int k = 0; k < c.size(); k++)
                buf[c[k]] = change(buf[c[k]]);
            if (ts.find(buf) == ts.end()) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = c.size();
        }
            
    }
}

int main() {    
    int T;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d\n", &n, &l);
        a.clear();
        b.clear();
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            a.push_back(buf);
        }
        scanf("\n");
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            b.push_back(buf);
        }
        scanf("\n");
        solve();
        
        printf("Case #%d: ", t);
        if (ans < 0) {
            printf("NOT POSSIBLE");
        } else printf("%d", ans);
        printf("\n");
    }
}

