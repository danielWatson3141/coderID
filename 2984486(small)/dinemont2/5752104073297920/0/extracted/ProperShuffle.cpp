#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    int ar[1000];
    int t, cas, i, n, j, p, tmp;
    
    freopen(argv[1],"r",stdin);
    scanf("%d",&t);

    
    for (cas=1; cas<=t; cas++) {
        scanf("%d",&n);
        for (i=0; i<n; i++) {
            scanf("%d",&ar[i]);
        }
        
        srand(time(NULL));
        if (rand() % 2) {
           printf("Case #%d: GOOD\n", cas);
        } else {
          printf("Case #%d: BAD\n", cas);
        }
    }

    return 0;
}
