#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<vector<int> > e;
vector<map<int,int> > dp;
vector<map<int,int> > nc;

int ncount(int n,int p){
  if(nc[n].count(p)){
    return nc[n][p];
  }else{
    int c=1;
    for(auto f:e[n]){
      if(f!=p){
	c+=ncount(f,n);
      }
    }
    return nc[n][p]=c;
  }
}

int rec(int n,int p){
  if(dp[n].count(p)){
    return dp[n][p];
  }else{
    int m=0;
    for(auto f:e[n]){
      if(f!=p){
	m+=ncount(f,n);
      }
    }
    int nsum=0;
    for(auto f:e[n]){
      if(f==p)continue;
      nsum+=ncount(f,n);
    }
    for(int i=0;i<e[n].size();i++){
      if(e[n][i]==p)continue;
      for(int j=i+1;j<e[n].size();j++){
	if(e[n][j]==p)continue;
	m=min(m,rec(e[n][i],n)+rec(e[n][j],n)+nsum-ncount(e[n][i],n)-ncount(e[n][j],n));
      }
    }
    return dp[n][p]=m;
  }
}

int main(){
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    int N;
    cin>>N;
    //    cerr<<i<<' '<<N<<endl;
    e.clear();
    e.resize(N);
    dp.clear();
    dp.resize(N);
    nc.clear();
    nc.resize(N);
    for(int j=0;j<N-1;j++){
      int x,y;
      cin>>x>>y;
      x--;
      y--;
      e[x].push_back(y);
      e[y].push_back(x);
    }
    int ans=1<<29;
    for(int j=0;j<N;j++){
      int nsum=0;
      for(auto f:e[j]){
	nsum+=ncount(f,j);
      }
      ans=min(ans,nsum);
      for(int k=0;k<e[j].size();k++){
	for(int l=k+1;l<e[j].size();l++){
	  ans=min(ans,rec(e[j][k],j)+rec(e[j][l],j)+nsum-ncount(e[j][k],j)-ncount(e[j][l],j));
	  // if(ans==0){
	  //   cout<<"*"<<j<<' '<<e[j][k]<<' '<<e[j][l]<<endl;
	  //   cout<<rec(9,1)<<endl;
	  //   return 0;
	  // }
	}
      }
    }
    cout<<"Case #"<<i<<": "<<ans<<endl;
  }
}
