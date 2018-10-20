#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, N, L;
long long f0[200], f1[200], ff[200];
int bb[200], b1[200];

int num_ones(long long a[], int p) {
    int i, num = 0;
    long long mask = 1 << p;
    for (i = 0; i < N; i++) {
        // printf("%lld ^ %lld\n", a[i], mask);
        if (a[i] & mask) num++;
    }
    return num;
}

int switch_bit(long long a[], int p) {
    int i, num = 0;
    long long mask = 1 << p;
    for (i = 0; i < N; i++) {
        a[i] = a[i] ^ mask;
    }
    return num;
}

int int_cmp(const void *a, const void *b) {
    long long d = *(long long*) a - *(long long*) b;
    if (d < 0) return -1;
    if (d > 0) return 1;
    return 0;
}

int min_switches(int n) {
    int i, n0 = L+1, n1 = L+1;
    if (n == L) {
        qsort(ff, (size_t)N, sizeof(ff[0]), int_cmp);
        // for (i = 0; i < N; i++) {
        //     printf("%lld ", ff[i]);
        // }
        // puts("");
        // for (i = 0; i < N; i++) {
        //     printf("%lld ", f1[i]);
        // }
        // puts("");
        for (i = 0; i < N; i++) {
            if (ff[i] != f1[i]) {
                return L+1;
            }
        }
        return 0;
    }

    int cc = bb[n];
    int c1 = b1[n];
    // printf("n %d: cc %d c1 %d\n", n, cc, c1);
    if (cc == c1) {
        n0 = min_switches(n+1);
    }
    if (N - cc == c1){
        switch_bit(ff, n);
        n1 = min_switches(n+1) + 1;
        switch_bit(ff, n);
    }

    if (n0 < n1) {
        return n0;
    } else {
        return n1;
    }
}

long long read_binary(int L) {
    int i;
    long long n = 0, d;
    char c;
    for (i = 0; i < L; n = n << 1) {
        scanf("%c", &c);
        if (c >= '0' && c <= '1') {
            d = c - '0';
            n = n ^ d;
            i++;
        }
    }
    return n >> 1;
}

int main() {
    scanf("%d", &T);
    int i, j;
    for (i = 1; i <= T; i++) {
        scanf("%d %d", &N, &L);
        for (j = 0; j < N; j++) {
            f0[j] = read_binary(L);
        }
        for (j = 0; j < N; j++) {
            f1[j] = read_binary(L);
        }
        memcpy(ff, f0, sizeof(ff[0])*(size_t)N);
        qsort(f1, (size_t)N, sizeof(f1[0]), int_cmp);
        for (j = 0; j < L; j++) {
            bb[j] = num_ones(ff, j);
            b1[j] = num_ones(f1, j);
            // printf("%d: %d %d\n", j, bb[j], b1[j]);
        }
        int ret = min_switches(0);
        if (ret > L) {
            printf("Case #%d: NOT POSSIBLE\n", i);
        } else {
            printf("Case #%d: %d\n", i, ret);
        }
    }
    
    return 0;
}
