#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int T,N,l;

char ch[20][20],ta[20][20],p[20][20];


int main() {
    freopen("A1.in","r",stdin);
    freopen("A1.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d%d",&N,&l);
        for (int i = 1;i <= N; i++)
            scanf("%s",ch[i]);
        for (int i = 1;i <= N; i++)
            scanf("%s",ta[i]);
        bool ft; int ans = 0;
        for (int i = 0;i <= (1<<l)-1; i++) {
            for (int j = 1;j <= N; j++) {
                memcpy(p[j],ch[j],l+1);
                for (int k = 0;k < l; k++)
                if (i & (1<<k)) {
                        p[j][k] = char((int(p[j][k])-int('0'))^1+int('0'));
                }
                p[j][l] = '\0';
            }
           // cout<<"-----"<<endl;
          //  for (int j = 1;j <= N; j++) cout<<p[j]<<" "<<ta[j]<<endl;
            //cout<<p[1]<<" "<<ta[2]<<" "<<strlen(p[1])<<" "<<strlen(ta[2])<<endl;
            ft = true;
            for (int j = 1;j <= N; j++) {
                bool flag = false;
                for (int k = 1;k <= N; k++) {
                    bool st = true;
                    for (int m = 0;m < l; m++)
                    if (p[j][m] != ta[k][m]) {st = false; break;}
                    if (st) {flag = true; break; }
                }
                ft = ft && flag;
            }
            if (ft) { ans = i; break;}
        }
        printf("Case #%d: ",kase);
        if (!ft) printf("NOT POSSIBLE\n");
        else {
            int tot = 0;
            for (int i = 1;i <= l; i++)
                if (ans & (1<<(i-1))) tot++;
            printf("%d\n",tot);
        }
    }
    return 0;
}
