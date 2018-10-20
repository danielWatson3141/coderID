/*
// Google Code Jam 2014 - Round 1A
// Solution of Problem B ("Full Binary Tree") [small]
// Author: Sergii Skorokhodov <SergSko@gmail.com>
*/
#include <stdio.h>

void delete(int N, int *edges, int *ecnts, int i)
{
    int j;

    if (N <= 0 || i >= N)
        return;

    for (j = 0; j < N; j++) {
        if (j != i && edges[j] & (1 << i)) {
            edges[j] ^= 1 << i;
            ecnts[j]--;
        }
    }
    edges[i] = 0;
    ecnts[i] = 0;
}

int attempt(int N, int *edges, int *ecnts)
{
    int i, j, k;
    for (i = 0; i < N; i++) {
        if (ecnts[i] == 1) {
            for (j = 0; j < N; j++) {
                if (ecnts[j] == 2 && edges[j] & (1 << i)) {
                    for (k = 0; k < N; k++) {
                        if (ecnts[k] == 2 && edges[k] & (1 << j)) {
                            delete(N, edges, ecnts, i);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int T, c, N, i, j, k, S;
    int edges[16], ecnts[16];

    scanf("%d", &T);
    for (c = 1; c <= T; c++) {
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            edges[i] = 0;
            ecnts[i] = 0;
        }
        for (i = 1; i < N; i++) {
            scanf("%d %d", &j, &k);
            j--; k--;
            ecnts[j]++; edges[j] |= 1 << k;
            ecnts[k]++; edges[k] |= 1 << j;
        }
        S = 0; 
        while (attempt(N, edges, ecnts)) S++;
        printf("Case #%d: %d\n", c, S);
    }
    return 0;
}
