#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 160;
const int MAXL = 70;

int n,l,a[MAXN];
bool used[MAXN];
string outlets[MAXN], need[MAXN], ot[MAXN], on[MAXN];

int main(){
    freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int cases;scanf("%d",&cases);
    for (int it=1;it<=cases;it++){
        printf("Case #%d: ",it);
        cin>>n>>l;
        for (int i=0;i<n;i++){
            cin>>outlets[i];
        }
        for (int i=0;i<n;i++){
            cin>>need[i];
        }
        int res = l+1;
        for (int x=0;x<n;x++)
        for (int y=0;y<n;y++){
            memset(a,-1,sizeof(a));
            memset(used,false,sizeof(used));
            int cnt = 0;
            for (int i=0;i<n;i++){
                ot[i] = outlets[i];
                on[i] = need[i];
            }

            for (int i=0;i<l;i++) if (ot[x][i] != on[y][i]){
                cnt++;
                for (int j=0;j<n;j++){
                    if (ot[j][i] == '0') ot[j][i] = '1';
                    else ot[j][i] = '0';
                }
            }

            a[x] = y; used[y] = true;
            bool found = true;
            for (int i=0;i<n;i++) if (a[i] == -1){
                found = false;
                for (int j=0;j<n;j++) if (!used[j]){
                    if (ot[i] == on[j]){
                        used[j] = true;
                        a[i] = j;
                        found = true;
                        break;
                    }
                }
                if (!found) break;
            }
            if (!found) continue;
            res = min(res, cnt);
        }
        if (res == l+1) puts("NOT POSSIBLE");
        else cout<<res<<endl;
    }
    return 0;
}
