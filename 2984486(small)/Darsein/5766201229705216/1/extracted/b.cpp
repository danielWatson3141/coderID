#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> pii;

int n;
vector<int> g[2000];

pii dfs(int v, int par){
  vector<int> child;
  rep(i,g[v].size()){
    if(g[v][i]!=par)child.push_back(g[v][i]);
  }

  if(child.size() == 0)return pii(1,0);

  vector<pii> cost;
  rep(i,child.size()){
    cost.push_back(dfs(child[i],v));
  }

  if(child.size()==1)return pii(cost[0].fs+1,cost[0].fs);
  if(child.size()==2){
    return pii(cost[0].fs+cost[1].fs+1,cost[0].sc+cost[1].sc);
  }

  pii res = pii(1,1e8);
  int sum = 0;
  rep(i,cost.size()){
    res.fs += cost[i].fs;
    sum += cost[i].fs;
  }

  int minv1 = 1e8, minv2 = 1e8;
  rep(i,cost.size()){
    int dif = cost[i].sc - cost[i].fs;
    if(minv1>dif)swap(minv1,dif);
    if(minv2>dif)swap(minv2,dif);
  }

  res.sc = sum+minv1+minv2;
  return res;
}

int main(){
  int testcase;
  int ans;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    cin >> n;
    rep(i,n)g[i].clear();
    ans = 1e8;

    int a,b;
    rep(i,n-1){
      cin >> a >> b; a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    rep(i,n){
      pii tmp = dfs(i,-1);
      ans = min(ans, tmp.sc);
    }

    cout << "Case #" << casenum << ": ";
    cout << ans << endl;
  }
}
