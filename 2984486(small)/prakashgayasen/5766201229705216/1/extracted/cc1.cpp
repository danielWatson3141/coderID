#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long int int64;
int64 ar[50];
int64 fn(int64 a,int64 n){
  int64 i,ans=0;
  memset(ar,0,sizeof(ar));
  for(i=0;i<n;i++){
    ar[i]=a%2;
    if(ar[i]==0)ans++;
    a/=2;
  }
  return ans;
}
int64 pwr(int64 a){
  int64 i,ans=1;
  for(i=1;i<=a;i++)ans*=2;
  return ans;
}
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int64 i,j,k,n,t,cnt=1,l,fl,ans,vl,u,v,edge[100][2],ind[20],ln,twos,edg;
  cin>>t;
  while(t--){
    scanf("%lld",&n);
    ans = n-1;
    for(i=0;i<n-1;i++){
      scanf("%lld %lld",&edge[i][0],&edge[i][1]);
      //if(cnt==70)cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
    }
    ln = pwr(n);
    for(i=1;i<ln;i++){
      vl = fn(i,n);
      //for(j=0;j<n;j++)cout<<ar[j]<<" ";cout<<endl;
      //cout<<vl<<endl;
      memset(ind,0,sizeof(ind));
      edg=0;
      for(j=0;j<n-1;j++){
        if(ar[edge[j][0]-1]==1&&ar[edge[j][1]-1]==1){ind[edge[j][0]]++;ind[edge[j][1]]++;edg++;}
      }
      fl = 1;twos=0;
      if(((n-vl)-1)!=edg)fl=0;
      for(j=1;j<=n;j++){
        if(ar[j-1]==0)continue;
        if(ind[j]==1||ind[j]==3)continue;
        else if(ind[j]==2)twos++;
        else fl=0;
      }

      if(fl==1&&twos==1)if(vl<ans){ans=vl;
        //for(j=;j<=n;j++)cout<<ar[j]<<" ";cout<<endl;
      }
    }
    printf("Case #%lld: %lld\n",cnt,ans);
    cnt++;
  }
  return 0;
}

