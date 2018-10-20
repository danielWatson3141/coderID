#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


int a[1010];

int main() {
    int kase = 0;
    int h = 1;
    freopen("C-small-attempt8.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d", &kase);
    while (kase--) {
          int n;
          scanf("%d", &n);
          for (int i = 0; i < n; ++i) {
              scanf("%d", &a[i]);
          }
          
          int origin = 0;
          for (int i = 0; i < n; ++i) {
              if (a[i] == i) {
                 origin++;   
              }
          }
          
          int mark = 0;
          for (int i = 0; i < n; i += 100) {
              int min = 10000, max = 0;
              int num = 0;
              for (int j = 0; j < 100; ++j) {
                  if (min > a[i+j]) min = a[i+j];
                  if (max < a[i+j]) max = a[i+j];
                  if (a[i+j] >= 500) num++;
              }
              if (max-min < 500) mark = true;
              if ( abs(50-num)*2 > 20) mark = true;
          }
          
          printf("Case #%d: ",h++);
          
    
          if (mark) {
             printf("BAD\n");
          }
          else {
               printf("GOOD\n");
          }
          
          
    }
    return 0;    
}
