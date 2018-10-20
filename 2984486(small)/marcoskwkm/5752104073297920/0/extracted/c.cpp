#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int N = 1000;
const int MAGIC = 485769;

int v[N];

int get_score(int *vet) {
    int score = 0;
    for(int a=0;a<N;++a) {
        if(vet[a] > 0) {
            int x = vet[a]-1;
            if(a > x) x -= N;
            score += a-x;            
        }
    }
    return score;
}

int main() {
    int t=1,T;
    for(scanf("%d",&T);t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%*d");
        for(int a=0;a<N;++a) scanf("%d",&v[a]);
        int score = get_score(v);
        if(score <= MAGIC) printf("BAD\n");
        else printf("GOOD\n");
    }
    return 0;
}
