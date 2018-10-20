#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int used[1024], N;
int cnt[1024];
int f[1024];
vector<int> v[1024];


int cmp(int t1, int t2){
  int f1 = f[t1] - cnt[t1], f2 = f[t2] - cnt[t2];
  
  return f1 < f2;
}

int dfs(int i){
//  cout << i << " ";
  used[i] = 1;
  
  vector<int> children;
  cnt[i] = 1;
  
  for(int j = 0; j < (int)v[i].size(); ++j)
    if(!used[v[i][j]]){
      dfs(v[i][j]);
      children.push_back(v[i][j]);
      cnt[i] += cnt[v[i][j]];
    }
    
    
  sort(children.begin(), children.end(), cmp);
  
  if(children.size() == 0){
    return f[i] = 0;
  }
  
  if(children.size() == 1){
    return f[i] = cnt[children[0]];
  }
  
  f[i] += f[children[0]] + f[children[1]];
  
  for(int j = 2; j < (int)children.size(); ++j)
    f[i] += cnt[children[j]];
  
  return f[i];
}

int go(int root){
  memset(used, 0, sizeof(used));
  memset(f, 0, sizeof(f));
  memset(cnt, 0, sizeof(cnt));
  dfs(root);
//   cout << endl;
  return f[root];
}
void solve(int t){
  
  cin >> N;
  
  for(int i = 0; i < 1024; ++i)
    v[i].erase(v[i].begin(), v[i].end());
  
  for(int i = 0; i < N - 1; ++i){
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  
  int res = 1e9;
  
  for(int i = 1; i <= N; ++i){
    res = min(go(i), res);/*
    for(int j = 1; j <= N; ++j)
      cout << cnt[j] << " ";
    for(int j = 1; j <= N; ++j)
      cout << f[j] << " ";
    cout << "\n\n";*/
  }
  
  cout << "Case #" << t << ": ";
  cout << res << endl;
}

int main(){
  int tests;
  
  cin >> tests;
  
  for(int i = 0; i < tests; ++i){
    solve(i + 1);
  }
}