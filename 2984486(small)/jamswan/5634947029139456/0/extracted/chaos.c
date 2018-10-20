#include <stdio.h>

int minm;
int same(char ele[][40], char dev[][40], int n, int l) {
        int i,j,k;
        int flag;
        for(i=0;i<n;i++){
                flag = 0;
                for(j=0;j<n;j++){
                        for(k=0;k<l;k++){
                                if(ele[i][k] != dev[j][k]){
                                        break;
                                }
                        }
                        if(k==l){
                                flag = 1;
                                break;
                        }
                }
                if(flag == 0) return 0;
        }
        
        return 1;
}
void mins(char ele[][40], char dev[][40], int ind, int n, int l, int num){
        if(same(ele, dev, n, l)&&num<minm) {minm = num;}
        int i;
       // printf("%d\n", ind);
        for(i=ind;i<l;i++){
                char nele[150][40],mele[150][40];
                int p,q;
                for(p=0;p<n;p++){
                        for(q=0;q<l;q++){
                                nele[p][q] = ele[p][q];
                                mele[p][q] = ele[p][q];
                                if(q==i){
                                        if(nele[p][q]=='0'){
                                                nele[p][q] = '1';
                                        }
                                        else
                                                nele[p][q]='0';
                                }
                        }
                }
                mins(nele, dev, i+1, n, l, num+1);
                mins(mele, dev, i+1, n, l, num);
        }
}
int main() {
	FILE *fp;
	fp = freopen("A-small-attempt0.in","r",stdin);
        
        int t;
        scanf("%d", &t);
        int i,j,k;
        for(i=1;i<=t;i++) {
                int n,l;
                char ele[150][40], dev[150][40];
                scanf("%d%d",&n,&l);
                getchar();
                for(j=0;j<n;j++) {
                        for(k=0;k<l;k++) {
                                scanf("%c", &ele[j][k]);
                        }
                        getchar();
                }
                for(j=0;j<n;j++) {
                        for(k=0;k<l;k++) {
                                scanf("%c", &dev[j][k]);
                        }
                        getchar();
                }
                minm = 200;
                mins(ele,dev,0,n,l,0);
                if(minm>40) printf("Case #%d: NOT POSSIBLE\n", i);
                else    printf("Case #%d: %d\n", i, minm);
        }
        return 0;
        
}