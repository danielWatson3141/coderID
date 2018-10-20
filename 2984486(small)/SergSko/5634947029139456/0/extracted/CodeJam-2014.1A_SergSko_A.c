/*
// Google Code Jam 2014 - Round 1A
// Solution of Problem A ("Charging Chaos")
// Author: Sergii Skorokhodov <SergSko@gmail.com>
*/
#include <stdio.h>

int count_bits(int x)
{
    int cnt;

    for (cnt = 0; x; cnt += x & 1, x >>= 1);

    return cnt;
}

int check(int N, int *outlets, int *devices, int x)
{
    int cnt, i, j;

    for (cnt = 0, i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            cnt += (outlets[i] ^ x) == devices[j];

    return cnt;
}

int main(int argc, char *argv[])
{
    int T, c, N, L, i, j, x, code, best;
    int outlets_and_devices[20], *p;

    scanf("%d", &T);
    for (c = 1; c <= T; c++) {
        scanf("%d %d", &N, &L);
        p = outlets_and_devices;
        for (i = 1; i <= 2*N; i++, p++) {
            scanf("%d", &code);
            for (j = 0, *p = 0; j < L && code; j++) {
                *p   += (code % 10) << j;
                code /= 10;
            }
        }
        best = L + 1;
        p = outlets_and_devices;
        for (x = 0; best && x < 2 << L; x++) {
            if (check(N, p, p + N, x) == N) {
                i = count_bits(x);
                if (i < best)
                    best = i;
            }
        }
        printf("Case #%d: ", c);
        if (best == L + 1)
            printf("NOT POSSIBLE");
        else
            printf("%d", best);
        printf("\n");
    }
    return 0;
}
