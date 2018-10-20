#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define mp make_pair
#define pb push_back
#define snuke(it,x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it ++)
typedef long long lld;
typedef pair<int,int> PII;


const int N = 13,INF = 0x3f3f3f3f;
int n,m;
string s[N];
set<string> Set;

void flip(int state) {
        for (int i = 0; i < m; i ++) if (state>>i&1) {
                for (int j = 0; j < n; j ++) {
                        s[j][i] = s[j][i]=='1' ? '0' : '1';
                }
        }
}

bool check() {
        for (int i = 0; i < n; i ++) {
                if (!Set.count(s[i])) return false;
        }
        return true;
}

int main(int argc,char **argv) {
        if (argc>1) {
                freopen(argv[1],"r",stdin);
                freopen("out.txt","w",stdout);
        }
        ios::sync_with_stdio(false);
        int cas,ca = 0;
        cin >> cas;
        while (cas--) {
                cin >> n >> m;
                for (int i = 0; i < n; i ++) {
                        cin >> s[i];
                }
                string x;
                Set.clear();
                for (int i = 0; i < n; i ++) {
                        cin >> x;
                        Set.insert(x);
                }
                int ans = INF;
                for (int i = 0; i < 1<<m; i ++) {
                        int cnt = 0;
                        for (int j = 0; j < m; j ++) cnt += i>>j&1;
                        if (cnt>=ans) continue;
                        flip(i);
                        if (check()) ans = cnt;
                        flip(i);
                }
                printf("Case #%d: ",++ca);
                if (ans==INF) {
                        puts("NOT POSSIBLE");
                } else {
                        printf("%d\n",ans);
                }
        }
        return 0;
}
