#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10000;
int tmp[10][N];
bool check(int n){
    bool ww=true;
    for(int i=0;i<min(n-1,10);i++){
        bool w=true;
        for(int j=0;j<N;j++)if(tmp[n-1][j]!=tmp[i][j]){
            w=false;break;
        }
        if(w){ww=false;break;}
    }
    return ww;
}
int main(){
    int T,idx=0;
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&T);
    bool w=true;
    while(T--){
        int n;scanf("%d",&n);
        int trash;
        if(idx<10){
            for(int i=0;i<n;i++)scanf("%d",&tmp[idx][i]);
            w=w&&check(idx+1);            
        }
        else for(int i=0;i<n;i++)scanf("%d",&trash);
        idx++;
        
        printf("Case #%d: ",idx);
        if(false)puts("GOOD");
        else puts("BAD");
        
    }
}
