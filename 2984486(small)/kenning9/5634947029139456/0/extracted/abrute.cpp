#include<bits/stdc++.h>
using namespace std;
int n, l, tc, p1[11], p2[11];
char str[12];
int main(){
    scanf("%d", &tc);
    for(int TC = 1; TC <= tc; ++TC){
        int bflip = 90;
        scanf("%d %d", &n, &l);
        for(int i = 0; i < n; ++i){
            scanf("%s", str);
            p1[i] = 0;
            for(int j = 0; j < l; ++j){
                p1[i] *= 2;
                if(str[j] == '1') p1[i] += 1;
            }
        }
        for(int i = 0; i < n; ++i){
            scanf("%s", str);
            p2[i] = 0;
            for(int j = 0; j < l; ++j){
                p2[i] *= 2;
                if(str[j] == '1') p2[i] += 1;
            }
        }
        //    for(int i = 0; i < n; ++i) printf("%d ", p1[i]); printf("d\n");
        //    for(int i = 0; i < n; ++i) printf("%d ", p2[i]); printf("d\n");
        sort(p2, p2+n);
        for(int flip = 0; flip < (1 << l); ++flip){
            for(int i = 0; i < n; ++i) p1[i] = (p1[i]^flip)&((1 << l)-1);
            sort(p1, p1+n);
            bool suc = true;
            for(int i = 0; i < n; ++i) if(p1[i] != p2[i]) suc = false;
            for(int i = 0; i < n; ++i) p1[i] = (p1[i]^flip)&((1 << l)-1);
            if(suc){
                int t = 0;
                for(int i = 0; i < l; ++i) if(flip & (1 << i)) ++t;
                bflip = min(bflip, t);
            }
        }
        if(bflip == 90) printf("Case #%d: NOT POSSIBLE\n", TC);
        else printf("Case #%d: %d\n", TC, bflip);
    }
}
        
