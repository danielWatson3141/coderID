#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
long long elec[200];
long long sw[200];
char str[200];
long long tmp[200];
const int INF = 0x3fffffff;
int nbits(long long n){
        int ret = 0;
        while(n) n &= n - 1, ++ret;
        return ret;
}
void solve(){
        int N, L;
        scanf("%d%d", &N, &L);
        for(int i = 0; i < N; ++i){
                scanf("%s", str);
                elec[i] = 0;
                for(int j = 0; j < L; ++j){
                        int bit = (str[j] - '0');
                        elec[i] = (elec[i] << 1) | bit;
                }
        }
        std::sort(elec + 0 , elec + N);
        for(int i = 0; i < N; ++i){
                sw[i] = 0;
                scanf("%s", str);
                for(int j = 0; j < L; ++j){
                        int bit = (str[j] - '0');
                        sw[i] = (sw[i] << 1) | bit;
                }
        }
        int ans = INF;
        for(int i = 0; i < N; ++i){
                int solve = elec[0] ^ sw[i];
                for(int j = 0; j < N; ++j){
                        tmp[j] = solve^sw[j];
                }
                std::sort(tmp + 0 , tmp + N);
                bool valid = true;
                for(int j = 0; j < N; ++j){
                        if(tmp[j] != elec[j]){
                                valid = false;
                                break;
                        }
                }
                if(valid) ans = std::min(ans, nbits(solve));
        }
        if(ans == INF)
                printf("NOT POSSIBLE\n");
        else
                printf("%d\n", ans);
}

int main(){
        int T;
        scanf("%d", &T);
        for(int t = 1; t <= T; ++t){
                printf("Case #%d: ", t);
                solve();
        }
}
