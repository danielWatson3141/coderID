#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 200;

lint outlet[MAXN], charger[MAXN];

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
        for(int a=0;a<n;++a) {
            lint mask = 0;
            int q = 0;
            for(int b=0;b<l;++b) {
                if( (charger[0]&(1ll<<b)) ^ (outlet[a]&(1ll<<b)) ) {
                    mask ^= (1ll<<b);
                    q++;
                }
            }
            set<lint> cj;
            for(int b=0;b<n;++b) {
                lint add = outlet[b];
                for(int c=0;c<l;++c)
                    if(mask&(1ll<<c))
                        add ^= (1ll<<c);
                cj.insert(add);
            }
            bool ok = 1;
            for(int b=0;b<n;++b)
                if(cj.find(charger[b]) == cj.end())
                    ok = 0;
            if(ok) ans = min(ans,q);
        }
        if(ans == INF) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }        
    return 0;
}
