#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_N 150

unsigned long long int devices[MAX_N];
unsigned long long int outlets[MAX_N];
unsigned long long int mask;
int best = INT_MAX;
int popcount = 0;
int N, L;

void rec(int ind);
int score();
void printmask(unsigned long long int num);

int main(){

    int ntt, tt, i, j;
    scanf("%d", &ntt);

    for(tt=1; tt<=ntt; tt++){

        memset( devices, 0, sizeof(unsigned long long int) * MAX_N );
        memset( outlets, 0, sizeof(unsigned long long int) * MAX_N );
        popcount = 0;
        best = INT_MAX;
        mask = 0;

        scanf("%d %d", &N, &L);

        char setup[L * N + N];
        j = 0;
        for( i=0; i<N; i++ ){
            scanf("%s", setup);
            for(j=0; j < L; j++){
                if(setup[j] == '1')
                    outlets[i] += 1 << j;
            }
        }

        j = 0;
        for( i=0; i<N; i++ ){
            scanf("%s", setup);
            for(j=0; j < L; j++){
                if(setup[j] == '1')
                    devices[i] += 1 << j;
            }
        }

        rec(0);

        if(best == INT_MAX)
            printf("Case #%d: NOT POSSIBLE\n", tt);
        else
            printf("Case #%d: %d\n", tt, best);
    }

    return 0;

}

void rec(int ind) {

    if(popcount > best)
        return;

    if(ind > L){
        int s = score();
        if( s < best )
            best = s;
        return;
    }

    rec(ind + 1);

    popcount += 1;
    mask += 1 << (ind-1);
    rec(ind + 1);
    mask -= 1 << (ind-1);
    popcount -= 1;

}

/*returns MAX_INT in case of impossibility*/
int score() {
    int i,j, hasoutlet;
    for( i=0; i<N; i++ ){
        hasoutlet = 0;
        for( j=0; j<N; j++ ){
            if( devices[i] == (outlets[j] ^ mask) ){
                hasoutlet = 1;
                break;
            }
        }
        if(hasoutlet == 0)
            return INT_MAX;
    }
    return popcount;
}

void printmask(unsigned long long int num){
    int i;
    for(i=0; i<L; i++){
        printf("%llu", num % 2 );
        num /= 2;
    }
    printf("\n");
}
