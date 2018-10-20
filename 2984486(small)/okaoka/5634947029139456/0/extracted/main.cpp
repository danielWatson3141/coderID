#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f

#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
#include <cctype>
#include <utility>
  
using namespace std;
  
typedef long long ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;
  
static const double EPS = 1e-8;
  
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

int main(){
  int T;
  while(~scanf("%d",&T)){
    for(int test_idx = 1; test_idx <= T; test_idx++){
      int N,L;
      scanf("%d %d",&N,&L);

      vector<ll> init_outlet;
      for(int i=0;i<N;i++){
	ll outlet = 0;
	string str;
	cin >> str;
	ll pow = 1;
	for(int j=str.size()-1;j>=0;j--){
	  outlet += (str[j]-'0') * pow;
	  pow *= 2;
	}
	init_outlet.push_back(outlet);
      }
      
      map<ll,int> freq;
      vector<ll> goal_outlet;
      for(int i=0;i<N;i++){
	ll outlet=0;
	string str;
	cin >> str;
	ll pow = 1;
	for(int j=str.size()-1;j>=0;j--){
	  outlet += (str[j]-'0') * pow;
	  pow *= 2;
	}
	goal_outlet.push_back(outlet);
	// cout << outlet << endl;
	freq[outlet]++;
      }
      
      int res = INF;
      for(ll S=0;S<=(1<<L)-1;S++){
	// cout << S << endl;
	map<ll,int> tmp_freq;
	for(int i=0;i<init_outlet.size();i++){
	  ll next = init_outlet[i] ^ S;
	  tmp_freq[next]++;
	  // cout << "pop:" << __builtin_popcount(S) << endl;
	}
	bool isok = true;
	for(map<ll,int>::iterator it = freq.begin();
	    it != freq.end();
	    it++){
	  if(tmp_freq[it->first] != it->second){
	    isok = false;
	  }
	}
	
	if(isok){
	  res = min(res,__builtin_popcount(S));
	}
      }
      if(res == INF){
	printf("Case #%d: NOT POSSIBLE\n",test_idx);
      }
      else{
	printf("Case #%d: %d\n",test_idx,res);
      }
    }
  }
}
