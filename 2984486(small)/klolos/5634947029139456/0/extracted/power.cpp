#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void solve_next();
int min(int a, int b) { return a < b ? a : b; }
int check(long long mask, long long * inputs, long long * outpus, int N);
inline int exists(long long num, long long *outputs, int N);
int ones(long long num);

/**
 * Reads the input from stdin and prints the result
 */
int main(int argc, char** argv)
{
    int num_tests;
    if (fscanf(stdin, "%d", &num_tests) != 1) {
        printf("error\n");
        return 1;
    }

    for (int i = 0; i < num_tests; ++i) {
        printf("Case #%d: ", i+1);
        solve_next();
    }

    return 0;
}

void solve_next()
{
    int N, L;
    if (fscanf(stdin, "%d %d\n", &N, &L) != 2) return;
    long long *outputs = (long long *) malloc(N * sizeof(*outputs));
    long long *inputs  = (long long *) malloc(N * sizeof(*inputs));

    for (int i = 0; i < N; ++i) {
        long long num = 0;
        char c;
        for (int j = 0; j < L; ++j) {
            if (fscanf(stdin, "%c", &c) != 1) return;
            c = c - '0';
            num = (num << 1) + c;
        }
        outputs[i] = num;
        if (fscanf(stdin, "%c", &c) != 1) return;
    }
    for (int i = 0; i < N; ++i) {
        long long num = 0;
        char c;
        for (int j = 0; j < L; ++j) {
            if (fscanf(stdin, "%c", &c) != 1) return;
            c = c - '0';
            num = (num << 1) + c;
        }
        inputs[i] = num;
        if (fscanf(stdin, "%c", &c) != 1) return;
    }

    int minmask = L+1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            long long mask = inputs[i] ^ outputs[j];
            int res = check(mask, inputs, outputs, N);
            if (res != -1)
                minmask = min(minmask, res);
        }
    }
    if (minmask <= L) printf("%d\n", minmask);
    else              printf("NOT POSSIBLE\n");
}

int check(long long mask, long long *inputs, long long *outputs, int N)
{
    for (int i = 0; i < N; ++i)
        if (!exists(mask ^ inputs[i], outputs, N))
            return -1;
    return ones(mask);
}

inline int exists(long long num, long long *outputs, int N)
{
    for (int i = 0; i < N; ++i)
        if (num == outputs[i])
            return 1;
    return 0;
}

int ones(long long num)
{
    int count = 0;
    for (int i = 0; i < 64; ++i)
        if ((num >> i) & 1)
            count++;
    return count;
}
