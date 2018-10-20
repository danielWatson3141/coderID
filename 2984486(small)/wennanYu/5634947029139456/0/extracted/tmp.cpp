#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int n, T, L;
long long data[150], target[150];

long long read(){
    char ts[50];
    scanf("%s", ts);
    long long ret=0, pw=1;
    for (int i=strlen(ts)-1;i>=0;--i){
        if (ts[i] == '1'){
            ret += pw;
        }
        pw*=2;
    }
    return ret;
}

int ans = -1, cas = 0;

void dfs(int k, int sum){
    if (ans!=-1 && sum>=ans) return;
    if (k<0){
        sort(data+1,data+1+n);
        for (int i=1;i<=n;++i){
            if (data[i]!=target[i]){
                return;
            }
        }
        ans = sum;
        return;
    }
    long long mask = 1LL << k;
    int a=0,b=0;
    for (int i=1;i<=n;++i){
        if (data[i] & mask) a++;
        if (target[i] & mask) b++;
    }
    if (a!=b && (n-a)!=b) return;
    if (a==b){
        dfs(k-1,sum);
    }
    if ((n-a)==b){
        for (int i=1;i<=n;++i) data[i]^=mask;
        dfs(k-1,sum+1);
        for (int i=1;i<=n;++i) data[i]^=mask;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        ans = -1;
        scanf("%d%d", &n, &L);
        getchar();
        for (int i=1;i<=n;++i){
            data[i] = read();
        }
        for (int i=1;i<=n;++i){
            target[i] = read();
        }
        sort(target+1,target+1+n);
        dfs(40,0);
        printf("Case #%d: ", ++cas);
        if (ans==-1) puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
}
