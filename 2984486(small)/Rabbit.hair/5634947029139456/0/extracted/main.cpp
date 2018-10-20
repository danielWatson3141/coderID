#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N = 150+10;
char s1[N][50], s2[N][50];
int n, L;
vector<string> vs1,vs2;
int b[50];
void solve() {
    int ans = -1;
    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int k = 0; k < L; k++) {
            if (s1[0][k] == s2[j][k]) b[k] = 1;
            else {
                b[k] = 0;
                cnt++;
            }
        }
        vs1.clear(); vs2.clear();
        for (int i = 1; i < n; i++) {
            string ss = "";
            for (int k = 0; k < L; k++) {
                if (b[k]) ss += s1[i][k];
                else ss += (s1[i][k] == '0' ? '1' : '0');
            }
            vs1.push_back(ss);
        }
        for (int i = 0; i < n; i++) {
            if (i != j) vs2.push_back((string)s2[i]);
        }
        sort(vs1.begin(), vs1.end());
        sort(vs2.begin(), vs2.end());
        if (vs1 == vs2) {
            if (ans == -1 || cnt < ans) {
                ans = cnt;
            }
        }

    }
    if (ans == -1) printf("NOT POSSIBLE\n");
    else printf("%d\n",ans);

}
int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T, cas = 0;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&L);
        for (int i = 0; i < n; i++) {
            scanf("%s",s1[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s",s2[i]);
        }
        printf("Case #%d: ",++cas);
        solve();
    }
    return 0;
}
