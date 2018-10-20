#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long double real;

const int N = 1000;

real lastSum[2][N+5];
real cache[2][N+5][N+5];
bool ans[1005];

int main() {
    real divN = 1.0/((real)(N));
    real notDivN = 1.0 - divN;

    // precompute cache
    for(int k=N;k>=0;k--) {
        int km = (k%2);
        int nm = 1-km;
        for(int y=0;y<N;y++) {
            lastSum[km][y] = 0.0;

            for(int x=0;x<N;x++) {
                if(k == N) {
                    if(x == y) {
                        cache[km][y][x] = 1.0;
                    } else {
                        cache[km][y][x] = 0.0;
                    }
                } else {
                    if(k == x) {
                        cache[km][y][x] = divN * lastSum[nm][y];
                    } else {
                        cache[km][y][x] = (divN * cache[nm][y][k]) + (notDivN * cache[nm][y][x]);
                    }
                }

                lastSum[km][y] += cache[km][y][x];
            }
        }
    }

    real pure = 1.0;
    for(int i=1;i<=N;i++) {
        pure /= ((real)(i));
    }

//    printf("pure = %.200Lf\n",pure);

    int T;
    scanf("%d",&T);

    vector< pair<int, int> > s;
    for(int z=1;z<=T;z++) {
        int N;
        scanf("%d",&N);

        int tot = 0;
        for(int i=0;i<N;i++) {
            int a;
            scanf("%d",&a);
            a--;

            real prob = cache[0][i][a];
            if(prob > divN) {
                tot++;
            }
        }

        s.push_back(make_pair(tot,z));
    }

    sort(s.begin(), s.end());

    for(int i=0;i<T/2;i++) {
        ans[s[i].second] = true;
    }

    for(int i=1;i<=T;i++) {
        if(ans[i]) {
            printf("Case #%d: GOOD\n",i);
        } else {
            printf("Case #%d: BAD\n",i);
        }
    }

    return 0;
}
