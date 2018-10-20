#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ulong unsigned long

int c, n, l; //Cases, #Devices, Switch size
ulong S[150], R[150]; //Switches, Required
int beststeps, bestmask;

void printbits(int l, ulong v) {
    int i;
    for(i = l-1; i >= 0; --i) putchar('0' + ((v >> i) & 1));
    putchar('\n');
}

void readbin(ulong *loc) {
    char c = getchar();
    ulong num = 0;

    do {
        num <<= 1;
        num += c == '1';
        c = getchar();
    } while (c != ' ' && c != '\n');

    *loc = num;
}

bool allvalid() {
    int i, j;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            //printf("%d vs %d, (%lu) vs (%lu)\n", i, j, R[i], S[j]);
            if (R[i] == S[j]) goto good;
        }
        return false;
        good:;
    }
    return true;
}

void togglemask(int mask) {
    int i;
    for (i = 0; i < n; ++i) S[i] ^= mask;
}

void solve(ulong smask, int steps) {
    int i, nmask;

    if (beststeps != -1 && steps >= beststeps) return;
    //printbits(l, smask);

    togglemask(smask);
    //printf("After toggle: ");
    //printbits(l, S[0]);
    if (allvalid()) {
        beststeps = steps;
        bestmask = smask;
        togglemask(smask);
        return;
    }
    togglemask(smask);


    for (nmask = smask, i = 0; i < l; ++i, nmask >>= 1) {
        if ((nmask & 1) != 1) solve(smask | (1 << i), steps+1);
    }
    return;
}

int main(void) {
    int i, j;

    scanf("%d", &c);
    for (i = 0; i < c; ++i) {
        scanf("%d%d", &n, &l);
        for (j = 0; j < n; ++j) readbin(&(S[j]));
        for (j = 0; j < n; ++j) readbin(&(R[j]));

        beststeps = -1;
        solve(0, 0);
        if (beststeps < 0) {
            printf("Case #%d: NOT POSSIBLE\n", i+1);
        } else {
            printf("Case #%d: %d\n", i+1, beststeps);
            //printbits(l, bestmask);
        }
    }
    return 0;
}
