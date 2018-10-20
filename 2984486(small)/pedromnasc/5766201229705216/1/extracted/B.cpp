#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define MAX 1010

using namespace std;

const int INF = 1<<29;

int T,N,a,b;
int pd[MAX],sub[MAX];
vector<int> lista[MAX];


int dfs(int atual,int ant){

    if(sub[atual]!=-1) return sub[atual];

    int tot=1;
    for(int i=0;i<lista[atual].size();i++){
        int prox=lista[atual][i];
        if(prox == ant) continue;
        tot+=dfs(prox,atual);
    }

    return sub[atual]=tot;
}

int doit(int atual,int ant){

    if(lista[atual].size() == 1 && atual!=ant){
        return pd[atual]=0;
    }

    if(atual!=ant){
        if(lista[atual].size() == 2){
            for(int i=0;i<lista[atual].size();i++){
                int prox=lista[atual][i];
                if(prox == ant) continue;
                return pd[atual]=sub[prox];
            }
        }
    }

    if(pd[atual]!=-1) return pd[atual];

    int resp=sub[atual]-1;

    for(int i=0;i<lista[atual].size();i++){
        int prox=lista[atual][i];
        if(prox == ant) continue;
        for(int j=i+1;j<lista[atual].size();j++){
            int prox2=lista[atual][j];
            if(prox2 == ant) continue;
           // printf("prox:%d , prox2:%d\n",prox,prox2);
        //    if(atual!=ant) resp=min(resp,(int)lista[atual].size()-3 + doit(prox,atual)+doit(prox2,atual));
          //  else resp=min(resp,(int)lista[atual].size()-2 + doit(prox,atual)+doit(prox2,atual));
            resp=min(resp,sub[atual]-sub[prox]-sub[prox2]-1 + doit(prox,atual)+doit(prox2,atual));

        }
    }

    return pd[atual]=resp;
}


int main(void){

    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);


    scanf("%d",&T);

    for(int caso=1;caso<=T;caso++){
        printf("Case #%d: ",caso);
        scanf("%d",&N);
        for(int i=0;i<=N;i++)
            lista[i].clear();

        for(int i=0;i<N-1;i++){
            scanf("%d %d",&a,&b);
            lista[a].push_back(b);
            lista[b].push_back(a);
        }

        int resp=N-1;
        for(int i=1;i<=N;i++){
        //for(int i=2;i<=2;i++){

            memset(pd,-1,sizeof pd);
            memset(sub,-1,sizeof sub);
            dfs(i,i);
    //        for(int j=1;j<=N;j++){
      //          printf("sub[%d]:%d\n",j,sub[j]);
        //    }
            resp=min(resp,doit(i,i));
          //  for(int j=1;j<=N;j++){
            //    printf("pd[%d]:%d\n",j,pd[j]);
            //}

            //break;
        }

        printf("%d\n",resp);


    }



    return 0;
}
