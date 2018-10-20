#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
string in[151],out[151];
void init(){
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>in[i];
    for(i=1;i<=n;i++) cin>>out[i];
}
int s;
int ver[41];
int pan(){
    int i,s1,s2,j;
    for(i=0;i<m;i++){
        s1=s2=0;
        for(j=1;j<=n;j++){
            s1+=(in[j][i]-'0');
            s2+=(out[j][i]-'0');
        }
        if(s1!=s2&&s1+s2!=n) return(0);
        ver[i]=0;
        if(s1==s2&&s1+s2!=n) ver[i]=-1;
        if(s1+s2==n&&s1!=s2){
            ver[i]=2;
        }
    }
    return(1);
}
string S[151],T[151];
int pan2(int x){
    int i,j;
    for(j=1;j<=n;j++){
        S[j]=T[j]="";
        for(i=0;i<=x;i++){
            if(ver[i]>=1){
                S[j]=S[j]+(char)('0'+(1-(in[j][i]-'0')));
                //cout<<(char)('0'+(1-(in[j][i]-'0')))<<"XXX";
            }
            else S[j]=S[j]+in[j][i];
            T[j]=T[j]+out[j][i];
        }
    }
    sort(S+1,S+n+1);
    sort(T+1,T+n+1);
    //for(i=1;i<=n;i++) cout<<S[i]<<" "<<T[i]<<endl;
    for(i=1;i<=n;i++) if(S[i]!=T[i]) return(0);
    return(1);
}
int OK;
int minn;
void dfs(int x){
    //cout<<x<<endl;
    if(x>=m){
        int i,s=0;
        for(i=0;i<m;i++) s=s+(ver[i]>=1);
        minn=s;
        OK=1;
        return;
    }
    int i;
    if(ver[x]==2||ver[x]==-1){
        if(pan2(x)) dfs(x+1);
        return;
    }
    ver[x]=0;
    if(pan2(x)){
        dfs(x+1);
    }
    ver[x]=1;
    if(OK==0&&pan2(x)){
        dfs(x+1);
    }
}
void work(){
    if(pan()==0){
        cout<<"NOT POSSIBLE"<<endl;
        return;
    }
    OK=0;
    dfs(0);
    if(OK==0)cout<<"NOT POSSIBLE"<<endl;
    else cout<<minn<<endl;
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("1.out","w",stdout);
    int T,C;
    cin>>T;
    for(C=1;C<=T;C++){
        init();
        printf("Case #%d: ",C);
        work();
    }
}
