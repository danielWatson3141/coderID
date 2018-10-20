#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 12;

int outlet[MAXN], charger[MAXN];
int aux[MAXN];

int main() {
    int t=1,T;
    for(scanf("%d",&T);t<=T;++t) {
        printf("Case #%d: ",t);
        int n,l;
        scanf("%d%d",&n,&l);
        memset(outlet,0,sizeof(outlet));
        memset(charger,0,sizeof(charger));
        for(int a=0;a<n;++a) {
            for(int b=0;b<l;++b) {
                char c;
                scanf(" %c",&c);
                if(c == '1') outlet[a] = 2*outlet[a] + 1;
                else outlet[a] *= 2;
            }
        }
        for(int a=0;a<n;++a) {
            for(int b=0;b<l;++b) {
                char c;
                scanf(" %c",&c);
                if(c == '1') charger[a] = 2*charger[a] + 1;
                else charger[a] *= 2;
            }
        }
        int ans = INF;
        for(int mask=0;mask<(1<<l);++mask) {
            set<int> cj;
            for(int a=0;a<n;++a) {
                aux[a] = outlet[a];
                for(int b=0;b<l;++b) {
                    if(mask&(1<<b)) aux[a] ^= (1<<b);
                }
                cj.insert(aux[a]);
            }
            bool ok = 1;
            for(int a=0;a<n;++a)
                if(cj.find(charger[a]) == cj.end())
                    ok = 0;
            if(ok) ans = min(ans,__builtin_popcount(mask));
        }
        if(ans == INF) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }        
    return 0;
}
