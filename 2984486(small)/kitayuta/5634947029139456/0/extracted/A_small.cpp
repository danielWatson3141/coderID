#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    for(int ix=1;ix<=T;ix++){
        printf("Case #%d: ",ix);
        int N,L;
        scanf("%d%d",&N,&L);
        vector<string> os(N),ds(N);
        string ins;
        for(int i=0;i<N;i++) cin>>os[i];
        for(int i=0;i<N;i++) cin>>ds[i];
        sort(begin(ds),end(ds));
        int mi=100;
        for(int i=0;i<(1<<L);i++){
            vector<string> nos(os);
            int cnt=0;
            for(int j=0;j<L;j++){
                if(i&(1<<j)){
                    cnt++;
                    for(int k=0;k<N;k++){
                        if(nos[k][j]=='1') nos[k][j]='0';
                        else nos[k][j]='1';
                    }
                }
            }
            sort(begin(nos),end(nos));
            if(nos==ds) mi=min(mi,cnt);
        }
        if(mi==100) printf("NOT POSSIBLE");
        else printf("%d",mi);
        printf("\n");
    }
}
