#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int INF=1<<29;

int N,L;
vector<string> ol,dv;

int rec(int x,vector<string> o,vector<string> d){
  if(x==L){
    return 0;
  }else{
    int res=INF;
    sort(begin(d),end(d));
    {
      sort(begin(o),end(o));
      bool f=false;
      for(int i=0;i<N;i++){
	f|=o[i][x]!=d[i][x];
      }
      if(!f){
	res=min(res,rec(x+1,o,d));
      }
    }
    {
      for(auto &e:o){
	e[x]=(e[x]=='0')?'1':'0';
      }
      sort(begin(o),end(o));
      bool f=false;
      for(int i=0;i<N;i++){
	f|=o[i][x]!=d[i][x];
      }
      if(!f){
	res=min(res,rec(x+1,o,d)+1);
      }
    }
    return res;
  }
}

int main(){
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    cin>>N>>L;
    ol.resize(N);
    dv.resize(N);
    for(int j=0;j<N;j++){
      cin>>ol[j];
    }
    for(int j=0;j<N;j++){
      cin>>dv[j];
    }
    int res=rec(0,ol,dv);
    cout<<"Case #"<<i<<": ";
    if(res==INF){
      cout<<"NOT POSSIBLE"<<endl;
    }else{
      cout<<res<<endl;
    }
  }
}
