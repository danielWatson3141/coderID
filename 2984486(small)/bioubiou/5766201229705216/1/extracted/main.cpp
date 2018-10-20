#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

struct edge{
    int to;
    int next;
}e[10000];
int head[10001],num;

void add(int u,int v){
    e[num].to=v;
    e[num].next=head[u];
    head[u]=num++;
}
void _add(int u,int v){
    add(u,v);
    add(v,u);
}
void init(){
    memset(head,-1,sizeof(head));
    num=0;
}
int d[10001];
int vis[10001];
void getnum(int &a,int &b,int c){
    if(c>=a){
        b=a;a=c;
    }
    else if(c>=b){
        b=c;
    }
    return ;
}
void dfs(int u,int fa){
    int nodenum=0;
    for(int i=head[u];i!=-1;i=e[i].next)if(e[i].to!=fa){
        dfs(e[i].to,u);
        nodenum++;
    }
    int flag=0;
    int a,b;
    if(nodenum<=1)d[u]=1;
    else{
        for(int i=head[u];i!=-1;i=e[i].next)if(e[i].to!=fa){
            if(flag==0){
                a=d[e[i].to];flag=1;
            }
            else if(flag==1){
                if(a>d[e[i].to])
                    b=d[e[i].to];
                else b=a,a=d[e[i].to];
                flag=2;
            }
            else getnum(a,b,d[e[i].to]);
        }
        d[u]=a+b+1;;
    }
    //cout<<u<<"   "<<d[u]<<endl;
    return ;
}
int main()
{
   //freopen("C://Users//Jo//Downloads//B-large (1).in","r",stdin);
    //freopen("C://Users//Jo//Downloads//out.txt","w",stdout);
    int t;
    int n;
    int cas=1;
    int u,v;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        init();
        for(int i=1;i<n;i++){

            scanf("%d%d",&u,&v);
            _add(u,v);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
          //  cout<<"cas"<<endl;
            dfs(i,0);
            ans=max(ans,d[i]);
        }
        printf("Case #%d: ",cas++);
        printf("%d\n",n-ans);
    }
    return 0;
}
