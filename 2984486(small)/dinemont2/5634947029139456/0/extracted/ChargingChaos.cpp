#include<stdio.h>
#include<string.h>

int bin[50];
char ar[160][50];
char br[160][50];
char tmp[160][50];


int add(int L) {
    int i;
    for (i=L-1; i>=0; i--) {
        if (bin[i] == 0) {
           bin[i] = 1;
           return 1;
        }
        bin[i] = 0;
    }
    return 0;
}

int compare(int N) {
    int i,j;
    
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (strcmp(tmp[i],br[j]) == 0) {
               break;
            }
        }
        if (j >= N) {
           return 0;
        }
    }
    return 1;
}

int count(int L) {
    int co = 0, i;
    for (i=0; i<L; i++) {
        if (bin[i]) {
           co++;
        }
    }
    return co;
}

void flip(int N, int L) {
     int i,j;
     for (i=0; i<N; i++) {
         strcpy(tmp[i], ar[i]);
     }
     
     for (i=0; i<L; i++) {
         if (bin[i]) {
            for (j=0; j<N; j++) {
                tmp[j][i] = (tmp[j][i]=='0')? '1' : '0';
            }
         }
     }
}

int main(int argc, char **argv) {
    int t,cas,i,N,L,ans,co;

    freopen(argv[1],"r",stdin);
    scanf("%d",&t);
    
    for (cas=1; cas<=t; cas++) {
        scanf("%d%d",&N,&L);
        for (i=0; i<N; i++) {
            scanf("%s",ar[i]);
        }
        for (i=0; i<N; i++) {
            scanf("%s",br[i]);
        }
        
        for (i=0; i<L; i++) {
            bin[i] = 0;
        }
        
        ans = L+1;
        while (1) {
              flip(N, L);
              if (compare(N)) {
                 co = count(L);
                 if (co < ans) {
                    ans = co;
                 }
              }
              if (!add(L)) {
                 break;
              }
        }
        if (ans > L) {
           printf("Case #%d: NOT POSSIBLE\n", cas);
        } else {
           printf("Case #%d: %d\n", cas, ans);
        }
    }

    return 0;
}
