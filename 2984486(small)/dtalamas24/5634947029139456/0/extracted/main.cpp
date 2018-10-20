#include <cstdio>
#include <iostream>

using namespace std;

bool sip, M[155], enc, sera;
char A[155][45], B[155][45], C[155][45];
int casos, ctos, mide, mejor, pa;

void copia(){
    for(int i=1; i<=ctos; i++){
        for(int e=0; e<mide; e++){
            C[i][e]=A[i][e];
        }
    }
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&casos);
    for(int v=1; v<=casos; v++){
        mejor=-1;
        scanf("%d%d",&ctos,&mide);
        for(int i=1; i<=ctos; i++)
            scanf("%s",A[i]);
        for(int i=1; i<=ctos; i++)
            scanf("%s",B[i]);

        for(int i=1; i<=ctos; i++){
            pa=0;
            copia();
            sip=true;
            for(int e=0; e<mide; e++){
                if(A[1][e]!=B[i][e]){
                    ++pa;
                    for(int d=1; d<=ctos; d++){
                        C[d][e]= C[d][e]=='0' ? '1' : '0';
                    }
                }
            }

            for(int e=1; e<=ctos; e++)
                M[e]=false;

            for(int a=1; a<=ctos; a++){
                enc=false;
                for(int b=1; b<=ctos; b++){
                    if(M[b])
                        continue;
                    sera=true;
                    for(int c=0; c<mide; c++){
                        if(C[a][c]!=B[b][c])
                            sera=false;
                    }
                    if(sera){
                        enc=true;
                        M[b]=true;
                        break;
                    }
                }
                if(!enc)
                    sip=false;
            }
            if(sip and (mejor==-1 or pa<mejor))
                mejor=pa;
        }
        printf("Case #%d: ",v);
        if(mejor==-1)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",mejor);
    }
    return 0;
}
