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
#include <vector>
using namespace std;
#define N 1100
int n,ans;
vector<int> G[N];
int dfs(int cur,int fa){
    vector<int> son;
    son.clear();
    for(vector<int>::iterator it=G[cur].begin();it!=G[cur].end();it++){
        if(*it==fa)continue;
        int cc=dfs(*it,cur);
        son.push_back(cc);
    }
    if(son.size()==0 || son.size()==1)return 1;
    else{
        sort(son.begin(),son.end());
        reverse(son.begin(),son.end());
        int res=1;
        vector<int>::iterator it=son.begin();
        res+=*it;
        it++;
        res+=*it;
        return res;
    }
}
void solve(int no){
    cin>>n;
    ans=(1<<29);
    for(int i=0;i<N;i++)
        G[i].clear();
    for(int i=1,cx,cy;i<n;i++){
        scanf("%d%d",&cx,&cy);
        G[cx].push_back(cy);
        G[cy].push_back(cx);
    }
    for(int i=1,res;i<=n;i++){
        res=dfs(i,-1);
        ans=min(ans,n-res);
    }
    printf("Case #%d: %d\n",no,ans);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("B-large.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
}
