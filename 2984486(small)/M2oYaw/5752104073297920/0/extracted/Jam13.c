#include<stdio.h>
int data[1000];
int main(){
    int t;
    FILE *fp;
    fp = fopen("./answer6.txt","w");
    scanf("%d",&t);
    int h,i,j;
    for(i=0;i<t;i++){
        scanf("%d",&h);
        for(j=0;j<h;j++){
            scanf("%d",&data[j]);
        }
        if(data[0] == 0)
            fprintf(fp,"Case #%d: BAD\n",i+1);
        else
            fprintf(fp,"Case #%d: GOOD\n",i+1);
    }
    fclose(fp);
    return 0;
}
