#include<stdio.h>
char a[10][11];
char b[10][11];
int n,l;
int x[10];
int sum = -1;
int min;
FILE *fp;
void print(int num){
    int i,j,k,o,p;
    int check = 0;
    int count = 0;
    for(i=1;i<=l;i++){
        if(x[i-1] == 1 ){
        for(j=0;j<n;j++){
            if(a[j][i-1] == '0')
                a[j][i-1] = '1';
            else
                a[j][i-1] = '0';
        }
        }
    }
    check = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                count = 0;
            for(k=0;k<l;k++){
                if(a[i][k] == b[j][k])
                    count++;
            }
            if(count == l){
                check++;
                break;
            }
        }
    }
    if(check == n){
        sum = 0;
        for(i=0;i<l;i++)
        sum = sum + x[i];
        if(sum < min)
            min = sum;
    }
    for(i=1;i<=l;i++){
        if(x[i-1] == 1 ){
        for(j=0;j<n;j++){
            if(a[j][i-1] == '0')
                a[j][i-1] = '1';
            else
                a[j][i-1] = '0';
        }
        }
    }
    return;

}


void permu(int c,int num){
   int i;
    if(c == l){
        print(num);
        return;
    }
    for(i=0;i<2;i++){
        x[c] = i;
        permu(c+1,num);
    }
}


int main(){
    int T;
    fp = fopen("./answer5.txt","w");
    scanf("%d",&T);
    int i,j,k,o,p;
    for(i=0;i<T;i++){
        sum = -1;
        scanf("%d %d",&n,&l);
        for(j=0;j<n;j++){
            scanf(" %s",a[j]);
        }
        for(j=0;j<n;j++){
            scanf(" %s",b[j]);
        }
        min = 2000;
        permu(0,i+1);
        if(min == 2000)
            fprintf(fp,"Case #%d: NOT POSSIBLE\n",i+1);
        else
            fprintf(fp,"Case #%d: %d\n",i+1,min);
    }
    return 0;
}
