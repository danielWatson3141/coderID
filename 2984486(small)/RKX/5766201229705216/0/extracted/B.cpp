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
int test,N;
vector<vector<int> >graph;
bool flag[2000];
bool flag2[2000];
bool init;

bool isBinary(int index){
  bool res = true;
  flag2[index] = true;
  if(graph[index].size() - 1 == 2){
    rep(i,graph[index].size()){
      if(!flag2[graph[index][i]]){
	res &= isBinary(graph[index][i]);
      }
    }
  }else if(graph[index].size() - 1 == 0){
    return true;
  }
  return false;
}

bool Test(int index){
  rep(i,2000) flag2[i] = flag[i];
  return isBinary(index);
}

int search(int index,int cut){
  flag[index] = true;
  int sum = 0;
  if(cut == 0){
    if(init){
      init = false;
      if(graph[index].size() == 0) return 0;
      if(graph[index].size() == 2){
	rep(i,graph[index].size()){
	  if(!flag[graph[index][i]])
	    sum += search(graph[index][i],0);
	}
	return sum;
      }
    }else{
      if(graph[index].size() - 1 == 0) return 0;
      if(graph[index].size() - 1 == 2){
	//	cout<<index + 1<<" OK,";
	rep(i,graph[index].size()){
	  if(!flag[graph[index][i]])
	    sum += search(graph[index][i],0);
	}
	return sum;
      }
    }
    //    cout<<index + 1<<" Cut,";
    vector<int>sums;
    int all_sum = 0;
    rep(i,graph[index].size()){
      if(!flag[graph[index][i]]){
	int tsum = search(graph[index][i],1) + 1;
	all_sum += tsum;
	if(Test(graph[index][i])) sums.pb(tsum);
      }
    }
    sort(sums.rbegin(),sums.rend());
    if(sums.size() >= 2){
      sum = all_sum - sums[0] - sums[1];
    }else{
      sum = all_sum;
    }
    return sum;
  }else{
    rep(i,graph[index].size()){
      if(!flag[graph[index][i]]){
	sum += search(graph[index][i],1) + 1;
      }
    }
    return sum;
  }
  return 0;
}


int main(){
  cin>>test;
  rep(t,test){
    graph.clear();
    cin>>N;
    graph.resize(N,vector<int>());
    rep(i,N - 1){
      int x,y;
      cin>>x>>y;
      x--,y--;
      graph[x].pb(y);
      graph[y].pb(x);
    }
    int res = INF;
    for(int root = 0; root < N; root++){
      memset(flag,false,sizeof(flag));
      init = true;
      int tmp = search(root,0);
      res = min(res,tmp);
      //      cout<<tmp<<endl;
    }
    // init = true;
    // res = min(res,search(1,0));

    printf("Case #%d: %d\n",t + 1,res);    
  }
}
