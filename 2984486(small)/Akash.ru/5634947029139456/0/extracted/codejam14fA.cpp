#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

struct Data{
    char Ary[200][100];
    int R,Bit;
};

int main()
{
    int I,K,L,M,N,Tcase,P;
    char C[100];
    FILE *F;
    F=fopen("D:\\Out.txt","w");

    scanf("%d",&Tcase);
    for(I=1;I<=Tcase;I++){
        scanf("%d",&N);
        scanf("%d",&L);

        Data Org,New,Tst;
        map<string,int>Map;

        for(K=0;K<N;K++){
            scanf("\n");
            scanf("%s",C);
            strcpy(Org.Ary[K],C);
        }
        for(K=0;K<N;K++){
            scanf("\n");
            scanf("%s",C);
            Map[C]=1;
        }
        Org.R=0;
        Org.Bit=0;
        queue<Data>Q;
        Q.push(Org);

        bool Flag=false;

        while(!Q.empty())
        {
            New=Q.front();
            Q.pop();
            P=0;
            for(K=0;K<N;K++){
            //for(M=0;M<N;M++){
                //if(K!=M){
                        //printf("New %s\n",New.Ary[K]);
                    if(Map[New.Ary[K]]==1){
                        ++P;
                        //break;
                    }
                //}
            }
            //printf("P=%d  N=%d\n",P,N);
            if(P==N){
                M=New.R;
                Flag=true;
                break;
            }
            else{
                //for(K=0;K<N;K++){
                    for(M=New.Bit;M<L;M++){
                        for(P=0;P<N;P++){
                            strcpy(Tst.Ary[P],New.Ary[P]);
                            if(Tst.Ary[P][M]=='1') Tst.Ary[P][M]='0';
                            else Tst.Ary[P][M]='1';
                        }
                        Tst.R=New.R+1;
                        Tst.Bit=M+1;
                        Q.push(Tst);
                    }
                //}
            }
        }
        if(Flag){
            fprintf(F,"Case #%d: %d\n",I,M);
        }
        else{
            fprintf(F,"Case #%d: NOT POSSIBLE\n",I);
        }
    }
    return 0;
}
