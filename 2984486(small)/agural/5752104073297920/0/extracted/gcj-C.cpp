/*
LANG: C++
ID: 2012agura1
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <ctime>

using namespace std;
FILE *fin  = fopen("c.in",  "r");
FILE *fout = fopen("gcj-c.out", "w");

int main () {
    float pmat[7][7] = {{.143,.143,.143,.143,.143,.143,.143},
                        {.179,.132,.133,.135,.137,.140,.143},
                        {.162,.171,.125,.129,.133,.137,.143},
                        {.147,.156,.167,.123,.129,.135,.143},
                        {.134,.143,.154,.167,.125,.133,.143},
                        {.123,.132,.143,.156,.171,.132,.143},
                        {.113,.123,.134,.147,.162,.179,.143}};
	int T, N, x[1005];

	fscanf(fin, "%d", &T);

    for(int t = 1; t <= T; t++) {
        fscanf(fin, "%d", &N);
        for(int i = 0; i < N; i++) {
            fscanf(fin, "%d", &x[i]);
        }

        double d = 0;
        for(int i = 0; i < N; i++) {
            int j = x[i];
            int sx = (int) (i * 6.0 / N);
            int sy = (int) (j * 6.0 / N);
            float fx = i * 6.0 / N - sx;
            float fy = j * 6.0 / N - sy;
            float p = pmat[sx][sy] * (1 - fx) * (1 - fy)
                    + pmat[sx][sy+1] * (1 - fx) * (fy)
                    + pmat[sx+1][sy] * (fx) * (1 - fy)
                    + pmat[sx+1][sy+1] * (fx) * (fy);
            d += p;
        }
        cout << d << " " << .143*N << endl;

        if(d <= 0.143*N)
            fprintf(fout, "Case #%d: GOOD\n", t);
        else
            fprintf(fout, "Case #%d: BAD\n", t);
    }

	return 0;
}


