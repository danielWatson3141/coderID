#pragma warning (disable: 4530) 
#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<climits>


#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
 
using namespace std;
 
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;

typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
 
const int INF=1<<29;
const double EPS=1e-9;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};//right down left up
int test,N,L;
bool Same(vector<string>x,vector<string>y){
  sort(all(x));
  sort(all(y));
  rep(i,x.size()){
    if(x[i] != y[i]) return false;
  }
  return true;
}
int main(){
  cin>>test;
  rep(t,test){
    cin>>N>>L;
    vector<string>bits(N);
    vector<string>req(N);
    rep(i,N) cin>>bits[i];
    rep(i,N) cin>>req[i];

    int res = INF;
    for(int i = 0; i < 1; i++){
      for(int j = 0; j < bits.size(); j++){
	vector<string>tmp = bits;
	int sum = 0;
	rep(k,bits[j].size()){
	  if(bits[j][k] != req[i][k]){
	    rep(l,tmp.size()){
	      char c = tmp[l][k];
	      tmp[l][k] = (c == '0' ? '1' : '0');
	    }
	    sum++;
	  }
	}
	//	cout<<bits[j]<<","<<req[i]<<"="<<sum<<endl;
	if(Same(tmp,req)) res = min(res,sum);	
      }
    }

    if(res == INF) printf("Case #%d: NOT POSSIBLE\n",t + 1);
    else printf("Case #%d: %d\n",t + 1,res);
  }
}
