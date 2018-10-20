#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[1024];

void solve(){
    int n;
    scanf("%d", &n);
    int count = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        if(a[i] == i+1 || a[i] == i)++count;
    }
    if(count >= 0.12 * n)
        printf("BAD\n");
    else
        printf("GOOD\n");
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        printf("Case #%d: ", t);
        solve();
    }
}