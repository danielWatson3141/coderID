#include <stdio.h>
#include <string.h>
#include <algorithm>


using namespace std;

long long T, N, L, A1[154], A2[154];

pair<long long, pair<long, long> > B[23720];

int main(){

    long long i, j, k, x,y, w;
    char c;

    scanf("%d", &T);
    for (k = 1; k <= T; k++) {
        scanf("%d%d", &N, &L);
        for (i=0; i<N; i++) {
            A1[i] = 0;
            for (j = 0; j < L; j ++) {
                scanf(" %c", &c);
                if (c == '1') {
                    A1[i] |= (1<<(L-j-1));
                }
            }
        }
        for (i=0; i<N; i++) {
            A2[i] = 0;
            for (j = 0; j < L; j ++) {
                scanf(" %c", &c);
                if (c == '1') {
                    A2[i] |= (1<<(L-j-1));
                }
            }
        }

        printf("Case #%d: ", k);

        w = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                x = A1[i] ^ A2[j];
                B[w++] = make_pair(x, make_pair(i, j));
            }
        }

        sort(B, B+w);
        x = B[0].first;
        memset(A1, 0, sizeof(A1));
        memset(A2, 0, sizeof(A2));
        y = (1LL << 50);
        for (i = 0; i < w; i++){ //printf ("%d -- %d,%d\n", B[i].first, B[i].second.first, B[i].second.second);
            if (B[i].first == x) {
                A1[B[i].second.first] ++;
                A2[B[i].second.second] ++;
            }
            else {
                x = 1;
                for (j = 0; j < N; j++) {
                    if(A1[j] == 0 || A2[j] == 0)
                        x = 0;
                }
                if (x == 1) {
                    x = 0;
                    for (j=0; j<L; j++){
                        if (B[i-1].first & (1<<j))
                            x++;
                    }
                    if (y > x)
                        y = x;
                }
                memset(A1, 0, sizeof(A1));
                memset(A2, 0, sizeof(A2));
                x = B[i].first;
                A1[B[i].second.first] ++;
                A2[B[i].second.second] ++;
            }
        }

        x = 1;
        for (j = 0; j < N; j++) {
            if(A1[j] == 0 || A2[j] == 0)
                x = 0;
        }
        if (x == 1) {
            x = 0;
            for (j=0; j<L; j++){
                if (B[i-1].first & (1<<j))
                    x++;
            }
            if (y > x)
                y = x;
        }

        if (y == (1LL<<50))
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", y);

    }

    return 0;
}
