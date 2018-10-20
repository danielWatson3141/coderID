#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
string ori[155];
string req[155];
int ans;
int n, l;
unordered_set<string> hashit;

void dfs(int d, int x) {
    if (d == l) {

        hashit.clear();
        for (int i = 0; i < n; i++) {
            hashit.insert(ori[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (hashit.count(req[i]) == 0) {
                return;
            }
        }
        
        if (ans == -1) {
            ans = x;
        } else if (x < ans) {
            ans = x;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (ori[i][d] == '0') {
            ori[i][d] = '1';
        } else {
            ori[i][d] = '0';
        }
    }

    dfs(d + 1, x + 1);

    for (int i = 0; i < n; i++) {
        if (ori[i][d] == '0') {
            ori[i][d] = '1';
        } else {
            ori[i][d] = '0';
        }
    }

    dfs(d + 1, x);
}

int main() {
    int tn;
    scanf("%d", &tn);
    int cn;
    for (int cn = 1; cn <= tn; cn++) {
        printf("Case #%d: ", cn);

        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i++) {
            char s[55];
            scanf("%s", s);
            ori[i] = string(s);
        }

        for (int i = 0; i < n; i++) {
            char s[55];
            scanf("%s", s);
            req[i] = string(s);
        }

        ans = -1;
        dfs(0, 0);

        if (ans == -1) {
            printf("NOT POSSIBLE\n");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
