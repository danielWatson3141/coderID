#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int a[1000], b[1000], t[1000];
int main(){
    int T, n, l, cnt = 1;
    char s[100];
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &l);
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            int len = strlen(s);
            int sum = 0;
            for(int j = 0; j < len; j++){
                sum*=2;
                sum+=(s[j]-'0');
            }
            a[i] = sum;//printf("%d\n", a[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            int len = strlen(s);
            int sum = 0;
            for(int j = 0; j < len; j++){
                sum*=2;
                sum+=(s[j]-'0');
            }
            b[i] = sum;//printf("%d\n", b[i]);
        }
        sort(b, b+n);
        int m = (1<<l);
        int f, ans = ~0U>>1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                t[j] = a[j]^i;//printf("%d %d\n",a[j], t[j]);
            }
            sort(t, t+n);
            f = 0;
            for(int j = 0; j < n; j++){
                if(b[j]!=t[j]){
                    f = 1;break;
                }
            }
            if(!f) {
                int ret = i;
                int y = 0;
                while(ret){
                    y+=ret%2;
                    ret/=2;
                }
                ans = min(ans, y);
            }
        }
        int res = 0;
        if(ans == (~0U>>1)) printf("Case #%d: NOT POSSIBLE\n", cnt++);
        else{
            printf("Case #%d: %d\n", cnt++, ans);
        }
    }
    return 0;
}

