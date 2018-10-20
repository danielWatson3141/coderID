/*************************************************************************
    > File Name: b.cpp
    > Author: implus
    > Mail: 674592809@qq.com
    > Created Time: 六  4/26 10:03:29 2014
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson l,m,ls
#define rson m+1,r,rs

const int maxn = 1111;
int dp[maxn];
int sz[maxn];
vector<int> mp[maxn];

void gaosz(int s, int f){
  sz[s] = 1;
  for(int i = 0; i < mp[s].size(); i++){
    int ns = mp[s][i];
    if(ns == f) continue;
    gaosz(ns, s);
    sz[s] += sz[ns];
  }
}

int gaodp(int s, int f){

  if(dp[s] != -1) return dp[s];

  int cnt = 0, ns = 0;
  vector<int> son;
  for(int i = 0; i < mp[s].size(); i++){
    if(mp[s][i] == f) continue;
    cnt++;
    ns = mp[s][i];
    son.push_back(ns);
  }

  if(cnt == 0) return dp[s] = 0;
  if(cnt == 1) return dp[s] = sz[ns];
  for(int i = 0; i < mp[s].size(); i++){
    int ns = mp[s][i];
    if(ns == f) continue;
    gaodp(ns, s);
  }
  int all = 0;
  int ans = (1<<30);
  vector<int> v;
  for(int i = 0; i < son.size(); i++) all += sz[son[i]], v.push_back(dp[son[i]] - sz[son[i]]);
  sort(v.begin(), v.end());
  /*
  for(int i =0; i < son.size(); i++){
    for(int j = i + 1; j < son.size(); j++){
      ans = min(ans, all - sz[son[i]] - sz[son[j]] + dp[son[i]] + dp[son[j]]);
    }
  }*/
  return dp[s] = all + v[0] + v[1];
}

int main(){
  int T, n, x, y, icase = 1;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) mp[i].clear();
    for(int i = 0; i < n - 1; i++){
      scanf("%d%d", &x, &y);
      x--, y--;
      mp[x].push_back(y);
      mp[y].push_back(x);
    }
    int ans = n;
    for(int i = 0; i < n; i++){
      fill(dp, dp + n, -1);
      gaosz(i, -1);
      ans = min(ans, gaodp(i, -1));
      //if(ans == 0) cerr<<i<<endl;
      //cerr<<"after i = "<<i<<endl; for(int j = 0; j < n; j++){ cerr<<"dp["<<j<<"] = "<<dp[j]<<" "; }cerr<<endl;
    }
    printf("Case #%d: %d\n", icase++, ans);
  }
  return 0;
}
