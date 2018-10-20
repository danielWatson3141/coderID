#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 160

int T;
int N;
int L;
int minStep;
int ans;

char src[SIZE][SIZE];
char dst[SIZE][SIZE];
char tmp[SIZE][SIZE];

int cmp(const void *a, const void *b) {
    return strcmp((const char *)b, (const char *)a);
}

void flip(int pos) {
    ans = 0;
    for (int i = 0; i < L; ++i) {
        if (tmp[pos][i] != dst[0][i]) {
            for (int j = 0; j < N; ++j) {
                tmp[j][i] = (tmp[j][i] == '1')?'0':'1';
            }
            ++ans;
        }
    }
}

int check() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < L; ++j) {
            if (tmp[i][j] != dst[i][j])
                return 0;
        }
    }
    return 1;
}

int
main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        memset(src, 0, sizeof(src));
        memset(dst, 0, sizeof(dst));
        minStep = SIZE;

        /** read data */
        scanf("%d %d\n", &N, &L);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < L; ++j)
                scanf("%c", &src[i][j]);
            getchar();
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < L; ++j)
                scanf("%c", &dst[i][j]);
            getchar();
        }
        qsort(dst, SIZE, SIZE, cmp);
        for (int i = 0; i < N; ++i) {
            memcpy(tmp, src, sizeof(src));

            /** flip */
            flip(i);

            qsort(tmp, SIZE, SIZE, cmp);
            /** check */
            if (check() && ans < minStep) {
                minStep = ans;
            }
        }

        if (minStep == SIZE)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", minStep);
    }
}
