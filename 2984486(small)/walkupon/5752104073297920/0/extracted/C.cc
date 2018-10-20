#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <vector>
#define LL long long
using namespace std;

int main(){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t, tt = 0;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int a = 0, b = 0, x;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            if(i < (n + 1)/2) a += x;
            else b += x;
        }
        printf("Case #%d: ", ++tt);
        if(a >= b) puts("GOOD");
        else puts("BAD");
    }
    return 0;
}
