#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> eg[2000];
int u[2000],uid;
int w[2000];
int n;

void cw(int x){
    w[x] = 1;
    u[x] = uid;
    for( int i=0; i<eg[x].size(); i++ ){
        int y = eg[x][i];
        if(u[y]==uid) continue;
        cw(y);
        w[x]+=w[y];
    }
}

int check(int x){
    if(eg[x].size()==1){
        return 0;
    }
    int d1,d2,dd,df;
    d1 = d2 = 1000000;
    dd = 0;
    df = 0;
    u[x] = uid;
    for( int i=0; i<eg[x].size(); i++ ){
        int y = eg[x][i];
        if(u[y]==uid) continue;
        int d = check(y)-w[y];
        if(d<d2) d2 = d;
        if(d2<d1) swap(d1,d2);
        dd += w[y];
        df++;
    }
    if(df==1){
        return dd;
    }
    return dd+d1+d2;
}

int main(){
    int tt,TT,x,y;
    scanf("%d",&TT);
    for( int tt=0; tt<TT; tt++ ){
        scanf("%d",&n);
        for( int i=0; i<n; i++ ){
            eg[i].clear();
        }
        for( int i=0; i<n-1; i++ ){
            scanf("%d %d",&x,&y);
            x-- ;y--;
            eg[x].push_back(y);
            eg[y].push_back(x);
        }
        int md = n-1;
        for( int i=0; i<n; i++ ){
            if(eg[i].size()==1) continue;
            uid++;
            cw(i);
            uid++;
            int d = check(i);
            if(d<md) md = d;
        }
        printf("Case #%d: %d\n",tt+1,md);
    }
    return 0;
}
