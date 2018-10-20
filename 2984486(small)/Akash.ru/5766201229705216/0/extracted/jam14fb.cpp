#include<iostream>
#include<vector>
#include<map>
#include<stdio.h>
using namespace std;
int main()
{
    int I,K,L,M,N,P,Tcase;
    FILE *F;
    F=fopen("D:\\Out.txt","w");

    scanf("%d",&Tcase);
    for(I=1;I<=Tcase;I++){
        scanf("%d",&N);
        int Degree[1009]={0};
        vector<int>V[1009];

        for(K=1;K<N;K++)
        {
            scanf("%d %d",&L,&M);
            Degree[L]++;
            Degree[M]++;
            V[L].push_back(M);
            V[M].push_back(L);
        }
        int List[1009]={0},In,Len,R=0,Z=0;
        for(K=1;K<=N;K++){
            map<int,int>Map;
            Map[K]=1;
            List[1]=K;
            In=1;Len=1;
            Z=1;
              //printf("K=%d\n",K);
            if(Degree[K]<2){
                if(R<Len) R=Len;
            }

            else{
                for(;In<=Len;In++){
                        //printf("Now %d\n",List[In]);
                    if(V[List[In]].size()>=2){
                            L=0;M=0;
                    for(P=0;P<V[List[In]].size();P++){
                            //printf("Edge %d\n",V[List[In]][P]);
                        if(L<Degree[V[List[In]][P]]&&Map[V[List[In]][P]]==0){
                            L=V[List[In]][P];
                        }
                    }
                    for(P=0;P<V[List[In]].size();P++){
                         //printf("Edge2 %d\n",V[List[In]][P]);
                        if(M<Degree[V[List[In]][P]]&&Map[V[List[In]][P]]==0&&L!=V[List[In]][P]){
                            M=V[List[In]][P];
                        }
                    }
                   // printf("L=%d M=%d In=%d\n",L,M,In);
                    if(M!=0&&L!=0){
                        //P=In*2;
                        List[++Z]=L;
                        List[++Z]=M;
                        Map[L]=1;
                        Map[M]=1;
                        Len+=2;
                        //++In;
                    }
                    }
                }
                //printf("Len=%d\n",Len);
                if(R<Len) R=Len;
            }
        }
        fprintf(F,"Case #%d: %d\n",I,N-R);
    }
    return 0;
}
