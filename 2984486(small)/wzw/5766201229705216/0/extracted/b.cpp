#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int n,ans,cnt;
struct edge{
    int u,v;
}g[2222];
int p[1111],o[1111],s[1111];

int cmp(edge a,edge b){return a.u<b.u;}

void dfs(int x,int fa){
    s[x]=1;
    o[x]=0;
    int m1=0,m2=0;
    for (int i=p[x];i<p[x+1];i++) if (g[i].v!=fa){
        dfs(g[i].v,x);
        o[x]++;
        s[x]+=s[g[i].v];
        if (s[g[i].v]>m1){
            m2=m1;
            m1=s[g[i].v];
        } else if (s[g[i].v]>m2) m2=s[g[i].v];
    }
    if (o[x]>2){
        cnt+=s[x]-1-m1-m2;
        s[x]=m1+m2+1;
    }
    if (o[x]==1){
        cnt+=s[x]-1;
        s[x]=1;
    }
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for (int _=1;_<=T;_++){
        int n;
        cin>>n;
        int t=0;
        for (int i=1;i<n;i++){
            scanf("%d%d",&g[t].u,&g[t].v);
            t++;
            g[t].u=g[t-1].v;
            g[t].v=g[t-1].u;
            t++;
        }
        sort(g,g+t,cmp);
        t=1;
        for (int i=0;i<n*2-2;i++) while (t<=g[i].u) p[t++]=i;
        p[n+1]=n*2-2;
        //for (int i=0;i<n*2-2;i++) cout<<"   "<<g[i].u<<' '<<g[i].v<<endl;
        ans=100000000;
        for (int i=1;i<=n;i++){
            cnt=0;
            dfs(i,0);
            if (cnt<ans) ans=cnt;
        }
        printf("Case #%d: %d\n",_,ans);
    }
    //system("pause");
}
/*
4
3
2 1
1 3
7
4 5
4 2
1 2
3 1
6 4
3 7
4
1 2
2 3
3 4
2
1 2

*/
