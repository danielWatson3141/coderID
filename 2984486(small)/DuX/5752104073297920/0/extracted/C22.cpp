#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

struct st {
    int s,ind;
} score[5555];

bool cmp(st a, st b) {
    return (a.s > b.s);
}

int main() {

    FILE *ff=fopen("C-small-attempt0.in", "r"), *gg=fopen("C-small-attempt01.out", "w");

    int n,p,i,j,s,tt,ttt,left,right,a[5555];
    bool good[555];

    fscanf(ff,"%d", &tt);
    for(ttt=0;ttt<tt;ttt++) {

        fscanf(ff,"%d", &n);
        for(i=0; i<n; i++) {
            fscanf(ff,"%d", &a[i]);
        }

        s = 0;
        for(i=0; i<n; i++) {
            left = max(0, a[i] - 333);
            right = a[i] - 1;

            if (i>=left && i<=right) {
                s += 333 - (right - i);
            }
        }

        score[ttt].s = s;
        score[ttt].ind = ttt;

        //fprintf(gg,"Case #%d: %d\n", tt, res);
    }

    sort(score, score+tt, cmp);
    for(ttt=0; ttt<tt; ttt++) {

        if (ttt < 60) {
            good[score[ttt].ind] = false;
            printf("-> %d ok\n",score[ttt].ind );
        }
        else {
            good[score[ttt].ind] = true;
            printf("-> %d bad\n", score[ttt].ind);
        }
    }

    for(ttt=0; ttt<tt; ttt++) {
        fprintf(gg,"Case #%d: ", ttt+1);
        if (good[ttt]) fprintf(gg,"GOOD\n"); else fprintf(gg,"BAD\n");
    }

    fclose(ff); fclose(gg);

    /*int n,t,i,j,p,a[555],br1[55][55],br2[55][55];

    n = 20;

    for(t=0; t<100000; t++) {

        for(i=0; i<n; i++) a[i] = i;
        for(i=0; i<n; i++) {
            j = rand() % n;
            p = a[i]; a[i] = a[j]; a[j] = p;
        }

        for(i=0; i<n; i++) {
            br1[a[i]][i]++;
        }
        //for(i=0; i<n; i++) printf("%d ", a[i]);
        //printf("\n");

        //system("pause");
    }

    for(t=0; t<100000; t++) {

        for(i=0; i<n; i++) a[i] = i;
        for(i=0; i<n; i++) {
            j = i + rand() % (n - i) ;
            p = a[i]; a[i] = a[j]; a[j] = p;
        }

        for(i=0; i<n; i++) {
            br2[a[i]][i]++;
        }
        //for(i=0; i<n; i++) printf("%d ", a[i]);
        //printf("\n");

        //system("pause");
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) printf("%5d ", br1[i][j]);
        printf("\n");
    }
    printf("\n\n\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) printf("%5d ", br2[i][j]);
        printf("\n");
    }*/

    /*int n,p,i,j,s,tt,ttt,left,right,a[5555];
    bool good[555];

    n = 1000;

    tt = 120;
    for(ttt=0; ttt<tt; ttt++) {
        p = rand() % 2;

        if (p == 1) {

            good[ttt] = true;
            for(i=0; i<n; i++) a[i] = i;
            for(i=0; i<n; i++) {
                j = i + rand() % (n - i) ;
                p = a[i]; a[i] = a[j]; a[j] = p;
            }

        } else {

            good[ttt] = false;
            for(i=0; i<n; i++) a[i] = i;
            for(i=0; i<n; i++) {
                j = rand() % n;
                p = a[i]; a[i] = a[j]; a[j] = p;
            }

        }

        s = 0;
        for(i=0; i<n; i++) {
            left = max(0, a[i] - 333);
            right = a[i] - 1;

            if (i>=left && i<=right) {
                s += 333 - (right - i);
            }
        }

        score[ttt].s = s;
        score[ttt].ind = ttt;
    }

    sort(score, score+tt, cmp);
    for(ttt=0; ttt<tt; ttt++) {
        if (ttt == 60) printf("-------------- pola ------------\n");
        printf("-> %d   ", score[ttt].s);
        if (good[score[ttt].ind]) printf("GOOD\n"); else printf("BAD\n");
    }*/

    return 0;
}
