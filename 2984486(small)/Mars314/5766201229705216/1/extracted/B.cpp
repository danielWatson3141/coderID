#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
int n;
struct Edge{
    int v,next;
}edge[2*N];
int head[N];
int cnt;
void addedge(int x,int y){
    edge[cnt].v=y;
    edge[cnt].next=head[x];
    head[x]=cnt++;
}
void relex(int &a,int &b,int &c){
    if(a<=c){
        b=a;a=c;
    }
    else
    if(b<=c){
        b=c;
    }
}
int dfs(int p,int father=-1){
    int ans1=0,ans2=0;
    int ds=0;
    int q=head[p];
    while(q){
        if(edge[q].v!=father)ds++;
        q=edge[q].next;
    }
    if(ds<2)return 1;
    q=head[p];
    while(q){
        int tmp=0;
        if(edge[q].v!=father)tmp=dfs(edge[q].v,p);
        relex(ans1,ans2,tmp);
        q=edge[q].next;
    }
    return ans1+ans2+1;
}
int init(){
    memset(head,0,sizeof(head));
    cnt = 1;
    cin >> n;
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        addedge(x,y);
        addedge(y,x);
    }
}
int ans(){
    int Ans=0;
    for(int i=1;i<=n;i++){
        Ans=max(Ans,dfs(i));

    }
    cout << n-Ans << endl;
}
int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
    init();
    printf("Case #%d: ",t);
    ans();
    }
}
