#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int _ = 1; _ <=T; _++){
        int N;
        scanf("%d",&N);
        int sc = 0;
        for(int i = 0 ; i < N;i++){
            int x;
            scanf("%d",&x);
            if(i+1 <=x) sc++;
        }
        printf("Case #%d: ",_);
        if(sc >N/2){
            puts("BAD");
        }else{
            puts("GOOD");
        }
    }
    return 0;
}
