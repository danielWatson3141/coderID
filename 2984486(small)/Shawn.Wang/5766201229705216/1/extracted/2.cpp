#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int a[1001][1001];
int n;
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) a[i][0]=0;
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][++a[x][0]]=y;
        a[y][++a[y][0]]=x;
    }
}
int del[1001];
int done[1001];
int maxn;
int dfs(int x){
    int i,m1,m2,s;
    done[x]=1;
    m1=m2=0;
    for(i=1;i<=a[x][0];i++){
        int y=a[x][i];
        if(done[y]==0){
            s=dfs(y);
            if(s>m1){
                m2=m1;
                m1=s;
            }
            else if(s>=m2){
                m2=s;
            }
        }
    }
    //cout<<x<<" "<<m1<<" "<<m2<<endl;
    if(m2==0) m1=0;
    return(1+m1+m2);
}

void work(){
    memset(del,0,sizeof(del));
    memset(done,0,sizeof(done));
    int i,j,sum=0;
    maxn=0;
    for(i=1;i<=n;i++){
        memset(done,0,sizeof(done));
        maxn=max(maxn,dfs(i));
    }
    cout<<n-maxn<<endl;
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("2.out","w",stdout);
    int T,C;
    cin>>T;
    for(C=1;C<=T;C++){
        init();
        printf("Case #%d: ",C);
        work();
    }
}

