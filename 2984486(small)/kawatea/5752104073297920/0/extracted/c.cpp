#include <cstdio>
#include <cmath>

using namespace std;

double a[1001][1000];
double b[1000][1000];
int d[1000];

int main()
{
    int c = 1000, t, i, j, k, l;
    
    for (i = 0; i < c; i++) {
        for (j = 0; j <= c; j++) {
            for (k = 0; k < c; k++) {
                a[j][k] = 0;
            }
        }
        
        a[0][i] = 1;
        
        for (j = 0; j < c; j++) {
            for (k = 0; k < c; k++) {
                if (a[j][k] == 0) continue;
                
                if (j == k) {
                    for (l = 0; l < c; l++) a[j + 1][l] += a[j][k] / c;
                } else {
                    a[j + 1][j] += a[j][k] / c;
                    a[j + 1][k] += a[j][k] * (c - 1) / c;
                }
            }
        }
        
        for (j = 0; j < c; j++) b[i][j] = a[c][j];
    }
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n;
        double sum = 0;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) scanf("%d", &d[j]);
        
        for (j = 0; j < n; j++) sum += log10(b[d[j]][j]);
        
        if (sum > -3000) {
            printf("Case #%d: BAD\n", i + 1);
        } else {
            printf("Case #%d: GOOD\n", i + 1);
        }
    }
    
    return 0;
}
