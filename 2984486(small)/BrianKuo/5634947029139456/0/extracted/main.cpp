#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("A-small-attempt1.in");
    ofstream fout("A-small-attempt1.out");
    int n;
    fin>>n;
    for(int t=1;t<=n;t++){
        int ans=-1;
        int N,L;
        fin>>N>>L;
        string A[N];
        string B[N];
        for(int i=0;i<N;i++){
            fin>>A[i];
        }
        for(int i=0;i<N;i++){
            fin>>B[i];
        }
        int b[L];
        for(int i=0;i<L;i++){
            b[i]=0;
        }
        sort(A,A+N);
        while(1){
            sort(B,B+N);
            int same=1,x=0;
            for(int j=0;j<N;j++){
                //cout<<A[j]<<' '<<B[j]<<endl;
                if(A[j]!=B[j]){
                    same=0;
                    break;
                }
            }
            if(same==1){
                for(int j=0;j<L;j++){
                    x+=b[j];
                }
                if(x<ans||ans==-1)ans=x;
            }
            int p=0,pn=0;
            for(int i=0;i<L;i++){
                if(p==0){
                    b[i]++;
                    p=1;
                    for(int j=0;j<N;j++){
                        B[j][i]=(B[j][i]=='0'?'1':'0');
                    }
                }
                if(pn==1){
                    pn=0;
                    b[i]++;
                    for(int j=0;j<N;j++){
                        B[j][i]=(B[j][i]=='0'?'1':'0');
                    }
                }
                if(b[i]==2){
                    pn=1;
                    b[i]-=2;
                }
                //cout<<b[i]<<' ';
            }
            //cout<<endl;
            if(pn==1)break;
        }
        char ansstr[500];
        if(ans==-1)
            sprintf(ansstr,"Case #%d: NOT POSSIBLE\n",t);
        else
            sprintf(ansstr,"Case #%d: %d\n",t,ans);
        fout<<ansstr<<endl;
    }
    return 0;
}
