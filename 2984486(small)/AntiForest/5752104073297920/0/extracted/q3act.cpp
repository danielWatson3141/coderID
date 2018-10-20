#include <cstdio>


using namespace std;

int _T;
int cutOff(400);

int N;
int p[1005];

int numOcc, numLOcc;

int totNOcc, totNLOcc;

int totCheck;

int main() {
    freopen ("q3.in", "r", stdin);
    freopen ("q3.out", "w", stdout);
    scanf ("%d", &_T);
    for (int _z=1; _z<=_T; _z++) {
        printf ("Case #%d: ", _z);
        scanf ("%d", &N);
        for (int i=0; i < N; i++) {
            scanf ("%d", &p[i]);
        }
        numOcc = numLOcc = 0;
        for (int i = 0; i < N-1; i++) {
            if (i < N-cutOff) {
                if (p[i] > i && p[i] <= i+cutOff) {
                    numOcc++;
                }
            } else {
                if (p[i] > i) {
                    numLOcc++;
                    numOcc++;
                }
            }
        }
        
        if (numOcc <= 342) {
            printf ("GOOD\n");
            totCheck++;
        } else {
            printf ("BAD\n");
        }
        //printf ("%d %d\n", numOcc, numLOcc);
        totNOcc += numOcc;
        totNLOcc += numLOcc;
    }
    //printf ("TOTCHECK:%d\n", totCheck);
    return 0;
}
