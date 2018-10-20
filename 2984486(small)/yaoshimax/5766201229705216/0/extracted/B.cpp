#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;

vector<int> edge[1024];
bool arrived[1024];
int dp[1024][1024];
int dfs(int cur,int par){
  if( dp[cur][par]!= -1 ) return dp[cur][par];
  int ans=1;
  int size = edge[cur].size();
  arrived[cur]=true;
  int left=-1;
  int right=-1;
  for( int i = 0 ; i < size; i++ ){
   int next = edge[cur][i];
   if( !arrived[next] ){
    int curscore = dfs(next,cur);
    if( curscore > left ){
      right = left;
      left = curscore;
    }else if( curscore > right ){
      right = curscore;
    }
   }
  }
  arrived[cur]=false;
  if( left != -1 && right != -1 ){
    ans += left + right;
  }
  return dp[cur][par]=ans;
}
int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
      int N;
      cin >> N;
      for( int i = 0 ; i < 1024; i++ )edge[i].clear();
      for( int i = 0 ; i < N-1; i++ ){
        int x,y;
        cin >>x >>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
      }
      int ans = INT_MAX;
      memset(dp,-1,sizeof(dp));
      for( int i = 1 ; i <= N; i++ ){
        memset(arrived,0,sizeof(arrived));
        int score = dfs(i,0);
        ans = min(ans,N-score);
      }
      cout << "Case #" << loop+1 << ": " <<ans<< endl;
  }
  return 0;
}
