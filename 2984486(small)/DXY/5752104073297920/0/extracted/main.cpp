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
#define eps (1e-7)
#define N 1100
#define INF (1<<29)
int n,ans,x[N];
int dp[N];
void solve(int no){
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
    for(int i=0;i<n;i++)
        dp[i]=INF;
    for(int i=0;i<n;i++){
        *lower_bound(dp,dp+n,x[i])=x[i];
    }
    int len=lower_bound(dp,dp+n,INF)-dp;
    reverse(x,x+n);
    for(int i=0;i<n;i++)
        dp[i]=INF;
    for(int i=0;i<n;i++){
        *lower_bound(dp,dp+n,x[i])=x[i];
    }
    int lln=lower_bound(dp,dp+n,INF)-dp;
    len=max(len,lln);
    if(len>n*3/4 || len<n/4)
        printf("Case #%d: BAD\n",no);
    else{
        printf("Case #%d: GOOD\n",no);
    }
}
int main(){
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
}
