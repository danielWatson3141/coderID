#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 160 ;

int n,l;
char st[MAXN][50],ed[MAXN][50] ;
bool flag[50];
int te=0;

int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int _,cas=0;
    scanf("%d",&_);
    while (_--) {
        scanf("%d%d",&n,&l);
        for (int i=0; i<n; i++) scanf("%s",st[i]);
        for (int i=0; i<n; i++) scanf("%s",ed[i]);
        vector<string> s1 ;
        int ans = 0x3f3f3f3f ;
        for (int i=0; i<n; i++) s1.push_back(string(st[i]));
        for (int i=0; i<n; i++) {
            int te=0;
            for (int j=0; j<l; j++)
                if (st[i][j] != ed[0][j]) {
                    flag[j] = true ;
                    te++ ;
                } else
                    flag[j] = false ;
            char tes[MAXN] ;
            set<string> myset ;
            for (int j=0; j<n; j++) {
                tes[l] = 0 ;
                for (int k=0; k<l; k++)
                    if (flag[k]) {
                        if (ed[j][k]=='1') tes[k]='0';
                        else tes[k]='1';
                    } else {
                        tes[k] = ed[j][k];
                    }
                myset.insert(string(tes));
            }
            bool legal = true ;
            for (int j=0;j<n;j++)
                if (myset.find(s1[j]) == myset.end()) legal = false ;
            if (legal) ans = min(ans , te) ;
        }
        printf("Case #%d: ",++cas);
        if (ans == 0x3f3f3f3f) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans) ;
    }
    return 0 ;
}
