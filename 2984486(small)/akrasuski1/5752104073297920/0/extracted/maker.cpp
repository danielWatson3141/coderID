//Author: Adam Krasuski

#include <cstdio>
#include <cstdlib>

using namespace std;

#define n 1000
#define N 1000000

int tab[n][n];

int main(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tab[i][j]=0;
        }
    }

    for(int i=0;i<N;i++){
        int a[n];
        for(int k=0;k<n;k++)
            a[k] = k;
        for(int k=0;k<n;k++){
            int p = rand()%n;
            int temp=a[k];
            a[k]=a[p];
            a[p]=temp;
        }
        for(int j=0;j<n;j++){
            tab[a[j]][j]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //printf(" %4d",tab[i][j]*n*100/N);
        }
       // printf("\n");
    }

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int trash;
        scanf("%d",&trash);
        int permut[n];
        for(int j=0;j<n;j++){
            scanf("%d",&permut[j]);
        }
        double odds=1;//1 means equal chances, >1 means bad is more likely
        for(int j=0;j<n;j++){
            odds*=(double)tab[permut[j]][j]*n/N;
        }
        printf("Case #%d: ",i+1);
        if(odds>1){
            printf("BAD\n");
        }
        else{
            printf("GOOD\n");
        }
    }

}
