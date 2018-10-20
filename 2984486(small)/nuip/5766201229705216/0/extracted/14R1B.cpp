#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;
typedef pair<int,int> P;

int N;
vector<int> edge[1123];

P solve(int n,int pre){
  int i,j,k,remain=0,sum=0,fir,sec;
  fir=sec=0;
  P tmp;
  for(i=0;i<edge[n].size();i++){
    if(edge[n][i]==pre)
      continue;
    tmp=solve(edge[n][i],n);
    sum+=tmp.X+tmp.Y;
    remain+=tmp.X>0;
    if(tmp.X>fir){
      sec=fir;
      fir=tmp.X;
    }else if(tmp.X>sec){
      sec=tmp.X;
    }
  }
  if(remain==0){
    return P(1,sum);
  }else if(remain==1){
    return P(1,sum);
  }else{
    return P(fir+sec+1,sum-fir-sec);
  }
}

int main(){
  int t,T;
  cin>>T;
  for(t=1;t<=T;t++){
    int i,j,k,a,b,re=11234;
    cin>>N;
    re=N-1;
    for(i=0;i<N;i++)
      edge[i].clear();
    for(i=0;i<N-1;i++){
      cin>>a>>b;
      edge[a-1].pb(b-1);
      edge[b-1].pb(a-1);
    }
    for(i=0;i<N;i++){
  //-    cout<<i<<endl;
      if(edge[i].size()<2)continue;
      int tmp=0,fir,sec;
      fir=sec=0;
  //    cout<<"root "<<i<<":"<<endl;
      for(j=0;j<edge[i].size();j++){
        tmp=solve(edge[i][j],i).X;
 //       cout<<"\t"<<edge[i][j]<<","<<tmp<<endl;
        if(tmp>fir){
          sec=fir;
          fir=tmp;
        }else if(tmp>sec){
          sec=tmp;
        }
      }
  //    cout<<N-1-fir-sec<<endl;
      re=min(re,N-1-fir-sec);
    }
    cout<<"Case #"<<t<<": "<<re<<endl;
  }
  return 0;
}