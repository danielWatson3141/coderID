#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

double ratio[1000];

int main(void) {
    int num, try_num;
    int N;
    int i, j, k;
    double ratio;

    num = 120;
    for(try_num = 1; try_num <= num; ++try_num) {
        N = 1000;
        ratio = 0.0;

        for(i = 0; i < N; ++i) {
            scanf("%d", &j);
            ratio += ((i < j) ? 1.0 : 0.0) / N;
        }

        printf("Case #%d: ", try_num);
        if(ratio < 0.4) printf("BAD\n");
        else printf("GOOD\n");
    }

    return 0;
}
