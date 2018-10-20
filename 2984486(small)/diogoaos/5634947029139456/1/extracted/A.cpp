#include <cstdio>
#include <set>

using namespace std;

typedef long long lint;

lint parse(const char* s) {
    int pos = 0;
    lint res = 0;
    while (s[pos]) {
        res *= 2;
        if (s[pos] - '0') {
            res++;
        }
        pos++;
    }
    return res;
}

int main() {
    int N, L;
    int ntests;
    scanf("%d", &ntests);
    
    for (int test = 1; test <= ntests; test++) {
        scanf("%d %d", &N, &L);
        
        lint device[N], outs[N];
        set<lint> target;

        char reade[60];
        
        for (int i = 0; i < N; i++) {
            scanf("%s", reade);
            device[i] = parse(reade);
        }
        
        for (int i = 0; i < N; i++) {
            scanf("%s", reade);
            target.insert(parse(reade));
            outs[i] = parse(reade);
        }
        
        int best = -1;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                lint mask = device[i] ^ outs[j];            
                set<lint> done;
                for (int k = 0; k < N; k++) {
                    done.insert(device[k] ^ mask);
                }
                if (done == target) {
                    if (best == -1 || best > __builtin_popcount(mask)) {
                        best = __builtin_popcount(mask);
                    }
                }
            }
        }
        
        printf("Case #%d: ", test);
        if (best == -1) {
            printf("NOT POSSIBLE\n");
        } else {
            printf("%d\n", best);
        }
    }
    
    return 0;
}
