#include <cstdio>
#include <cstring>
#include <vector>

#define MAXL 45
#define MAXN 155

using namespace std;

const int INF = 1<<29;

int T,N,L;
char ini[MAXN][MAXL],fim[MAXN][MAXL];
int a[MAXL],b[MAXL];
int pd[MAXL];


int doit(int atual){
    if(atual == L) return 0;
    if(pd[atual]!=-1) return pd[atual];
    if(b[atual] == a[atual]) return doit(atual+1);
    if(b[atual] == N-a[atual]) return 1+doit(atual+1);
    return pd[atual]=INF;
}


int main(void){

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);


    scanf("%d",&T);

    for(int caso=1;caso<=T;caso++){
        printf("Case #%d: ",caso);
        memset(pd,-1,sizeof pd);
        scanf("%d %d",&N,&L);
        for(int i=0;i<N;i++){
            scanf(" %s",ini[i]);
        }

        for(int i=0;i<N;i++){
            scanf(" %s",fim[i]);
        }

        for(int i=0;i<L;i++){
            a[i]=0;
            b[i]=0;
            for(int j=0;j<N;j++){
                if(ini[j][i] == '1') a[i]++;
                if(fim[j][i] == '1') b[i]++;
            }
        }

        int resp=doit(0);

        if(resp >= INF) printf("NOT POSSIBLE\n");
        else printf("%d\n",resp);
    }



    return 0;
}
