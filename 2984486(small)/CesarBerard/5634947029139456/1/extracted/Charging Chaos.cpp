#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<algorithm>
using namespace std;
long a,b,c,i,j,k,t,n,l,chafas[300],salir,res;
char flow[300][300],device[300][300],flow2[300][300];
long checar(){
    long c;
    for(int i=0;i<n;i++){
            c=0;
            for(int j=0;j<n;j++){
                if(strcmp(flow2[j],device[i])==0){
                    c++;
                    break;
                }
            }
            if(c==0) break;
        }
        return c;
}
void cambio(long i,long j){
    if(flow2[i][j]=='1') flow2[i][j]='0';
    else flow2[i][j]='1';
}
void regresar(){
    for(int i=0;i<n;i++) strcpy(flow2[i],flow[i]);
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-LARGE.out","w",stdout);
    scanf("%ld",&t);
    for (int w=1;w<=t;w++){
        res=999999999;
        for(i=0;i<300;i++){
            memset(flow[i],0,sizeof(flow[i]));
            memset(flow2[i],0,sizeof(flow2[i]));
            memset(device[i],0,sizeof(device[i]));
            chafas[i]=0;
        }
        a=0;
        b=0;
        scanf("%ld%ld",&n,&l);
        for(i=0;i<n;i++){
            scanf("%s",&flow[i]);
            strcpy(flow2[i],flow[i]);
        }
        for(i=0;i<n;i++) scanf("%s",&device[i]);
        for(i=0;i<n;i++){
            c=0;
            for(j=0;j<n;j++){
                if(strcmp(flow[j],device[i])==0){
                    c++;
                    break;
                }
            }
            if(c==0){
                chafas[a]=i;
                a++;
            }
        }
        if(a==0) printf("Case #%d: 0\n",w);
        else{
                for(j=0;j<n;j++){
                        b=0;
                    for(k=0;k<l;k++){
                        if(device[chafas[0]][k]!=flow2[j][k]){
                            for(int z=0;z<n;z++) cambio(z,k);
                            b++;
                        }
                    }
                    if(checar()!=0)                        res=min(res,b);
                    regresar();
                }
                if(res==999999999) printf("Case #%d: NOT POSSIBLE\n",w);
                else printf("Case #%d: %ld\n",w,res);
        }
    }
}
