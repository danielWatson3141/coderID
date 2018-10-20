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

long long dva[555];
char o[555][555],s[555][555];

struct st {
    long long a;
    int b;
} a[555*555];

bool cmp(st a, st b) {
    return (a.a < b.a || (a.a == b.a && a.b < b.b));
}

int main() {

    FILE *ff=fopen("A-small-attempt0.in", "r"), *gg=fopen("A-small-attempt0.out", "w");

    int n,l,i,j,k,br,tt,ttt,num,res;
    long long r;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {

        fscanf(ff,"%d %d", &n, &l);
        for(i=0; i<n; i++) {
            fscanf(ff,"%s", &o[i]);
        }
        for(i=0; i<n; i++) {
            fscanf(ff,"%s", &s[i]);
        }
        //printf("ok %d '%s' '%s'\n", l, o[0], s[0]);

        res = -1;

        dva[0] = 1;
        for(i=1; i<=l; i++) dva[i] = dva[i-1] * 2LL;

        num = 0;
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                //printf("%d %d\n", i, j);

                r = 0; br = 0;
                for(k=0; k<l; k++) {
                    if (s[i][k] != o[j][k]) {
                        r += dva[k];
                        br++;
                    }
                }

                a[num].a = r;
                a[num].b = br;
                num++;
            }
        }
        //printf("sad\n");

        sort(a,a+num,cmp);

        //printf("ok %d\n", num);


        i=0;
        while(i<num) {

            br = 1;
            while(i+1<num && a[i+1].a == a[i].a) {
                i++;
                br++;
            }

            if (br==n) {
                if (res == -1 || a[i].b < res) {
                    res = a[i].b;
                    //printf("-> %lld\n", a[i].a);
                }
            }

            i++;
        }
        //printf("ok\n");

        if (res == -1) {
            fprintf(gg,"Case #%d: NOT POSSIBLE\n", tt);
        } else {
            fprintf(gg,"Case #%d: %d\n", tt, res);
        }
    }

    fclose(ff); fclose(gg);

    return 0;
}
