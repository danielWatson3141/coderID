#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef long long int int64;
int64 ar[100];
int64 fn(string a,string b, vector <string> tm,  vector <string> tg){
  int i,j,n,nf=0,ln;
  memset(ar,0,sizeof(ar));
  ln = a.length();n = tm.size();
  for(i=0;i<ln;i++){
    if(a[i]!=b[i]){
      nf++;
      for(j=0;j<n;j++){
        if(tm[j][i]=='0')tm[j][i]='1';
        else tm[j][i]='0';
      }
    }
  }
  sort(tm.begin(),tm.end());
  sort(tg.begin(),tg.end());
  if(tm==tg)return nf;
  else return -1;
}
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int64 i,j,k,n,t,cnt=1,l,fl,ans,vl;
  cin>>t;
  while(t--){
    fl=0;ans=1000000;
    vector <string> u,v,tm;
    string st;
    scanf("%lld %lld",&n,&l);
    for(i=0;i<n;i++){cin>>st;u.push_back(st);}
    for(i=0;i<n;i++){cin>>st;v.push_back(st);}  
    //for(i=0;i<n;i++)cout<<u[i]<<endl;
    //for(i=0;i<n;i++)cout<<v[i]<<endl; 
    for(i=0;i<n;i++){
    tm = u;
    vl = fn(u[0],v[i],tm,v);
    //cout<<vl<<endl;
    if(vl<ans&&vl!=-1){ans=vl;fl=1;}
    }  
    if(fl==1)printf("Case #%lld: %lld\n",cnt,ans);
    else printf("Case #%lld: NOT POSSIBLE\n",cnt);
    cnt++;
  }
  return 0;
}

