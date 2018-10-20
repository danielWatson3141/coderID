#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char outlets[150][41];
char devices[150][41];
char orz[150][41];
char ooo[41];
char ddd[41];
int N, L;

char flips[40];

int cmp(const void *p, const void *q)
{
    return strcmp((const char *)p, (const char *)q);
}

int check()
{
    int i, j;
    for (j = 0; j < L; j++)
        if (flips[j])
            for (i = 0; i < N; i++)
                orz[i][j] = (outlets[i][j] == '1' ? '0' : '1');
        else
            for (i = 0; i < N; i++)
                orz[i][j] = outlets[i][j];
    for (i = 0; i < N; i++)
        orz[i][L] = '\0';

    qsort(orz, N, sizeof(orz[0]), cmp);

    /*
    printf("checking: ");
    for (j = 0; j < L; j++) {
        printf("%d", flips[j]);
    }
    printf("\n");
    */
    for (i = 0; i < N; i++) {
//        printf("%s : %s\n", orz[i], devices[i]);
        if (strcmp(orz[i], devices[i]) != 0)
            return 0;
    }
//    printf("\n");

    return 1;
}

int rec(int k)
{
    int ans0, ans1;

    if (k == -1) {
        if (check())
            return 0;
        else
            return 41;
    }

    ans0 = ans1 = 41;
    if (ooo[k] == ddd[k]) {
        ans0 = rec(k - 1);
    }
    if (ooo[k] == N - ddd[k]) {
        flips[k] = 1;
        ans1 = rec(k - 1) + 1;
        flips[k] = 0;
    }

    return ans0 < ans1 ? ans0 : ans1;
}

int main()
{
    int T, t;
    int i, j;
    int ans;

    scanf("%d\n", &T);
    for (t = 1; t <= T; t++) {
        scanf("%d %d\n", &N, &L);
        for (j = 0; j < L; j++) {
            ooo[j] = ddd[j] = 0;
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < L; j++) {
                scanf("%c", &outlets[i][j]);
                if (outlets[i][j] == '0') {
                    ooo[j]++;
                }
            }
            outlets[i][L] = '\0';
            scanf(" ");
        }
        scanf("\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < L; j++) {
                scanf("%c", &devices[i][j]);
                if (devices[i][j] == '0') {
                    ddd[j]++;
                }
            }
            devices[i][L] = '\0';
            scanf(" ");
        }
        scanf("\n");

        /*
        ans = 0;
        for (j = 0; j < L; j++) {
            if (ooo[j] == ddd[j]) {
            } else if (ooo[j] == N - ddd[j]) {
                ans++;
            } else {
                ans = -1;
                break;
            }
        }
        */
        qsort(devices, N, sizeof(devices[0]), cmp);
        ans = rec(L - 1);

        if (ans <= L)
            printf("Case #%d: %d\n", t, ans);
        else
            printf("Case #%d: NOT POSSIBLE\n", t);
    }

    return 0;
}
