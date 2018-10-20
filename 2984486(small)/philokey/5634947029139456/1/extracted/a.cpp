#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 105;
char sa[MAXN][MAXN],sb[MAXN][MAXN];
bool check(int n) {
    bool vis[MAXN] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[j]&&strcmp(sa[i],sb[j])==0) {
                vis[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) return 0;
    }
    return 1;
}
int main()
{
    freopen("/home/qitaishui/practice/retired/in.txt","r",stdin);
    freopen("/home/qitaishui/practice/retired/out.txt","w",stdout);
    int cas;
    int n,l;
    int ans,cnt;
    scanf("%d",&cas);

    for (int ca = 1; ca<=cas; ++ca) {
        scanf("%d%d",&n,&l);
        for (int i = 0; i < n; ++i) {
            scanf("%s",sa[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%s",sb[i]);
        }
        char st[MAXN][MAXN];
        int tmp ;
        ans = 11111;
        for (int i = 0; i < (1<<l); ++i) {
            cnt = 0;
            for (int j = 0; j < n; ++j) {
                strcpy(st[j],sa[j]);
                tmp = i;
                for (int k = 0; k < l; ++k) {
                    if (tmp&1) {
                        if (j == 0) {
                            ++cnt;
                        }
                        sa[j][k] = ((sa[j][k]-'0')^1)+'0';
                    }
                    tmp >>= 1;
                }

            }

            tmp = check(n);
            if (tmp) {
                ans = min(ans,cnt);
            }
            for (int j = 0; j < n; ++j)
                strcpy(sa[j],st[j]);
        }
        printf("Case #%d: ",ca);
        if (ans > 100) {
            printf("NOT POSSIBLE\n");
        }
        else printf("%d\n",ans);
    }
    return 0;
}

