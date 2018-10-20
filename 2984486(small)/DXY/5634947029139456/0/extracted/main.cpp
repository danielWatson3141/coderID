#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define N 200
int n,l,ans;
string pp[N],in[N],cur[N];
bool flip[N];
void judge(int no){
    int res=0;
    for(int i=0;i<l;i++){
        if(in[no][i]==pp[0][i]){
            flip[i]=false;
        }else{
            flip[i]=true;
            res++;
        }
    }
    if(ans!=-1 && res>=ans)return;
    for(int i=0;i<n;i++){
        cur[i]=in[i];
        for(int j=0;j<l;j++){
            if(flip[j]){
                if(cur[i][j]=='0')cur[i][j]='1';
                else cur[i][j]='0';
            }
        }
    }
    sort(cur,cur+n);
    for(int i=0;i<n;i++)
        if(cur[i]!=pp[i])return;
    ans=res;
}
void solve(int no){
    ans=-1;
    cin>>n>>l;
    for(int i=0;i<n;i++)
        cin>>in[i];
    for(int i=0;i<n;i++)
        cin>>pp[i];
    sort(pp,pp+n);
    for(int i=0;i<n;i++){
        judge(i);
    }
    if(ans==-1){
        printf("Case #%d: NOT POSSIBLE\n",no);
    }else{
        printf("Case #%d: %d\n",no,ans);
    }
}
int main(){
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
}
