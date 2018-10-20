#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> ngb[1000];
int dfs(int v, int par){
  vector<int> c;
  for (int i=0;i<ngb[v].size();++i){
    int w=ngb[v][i];
    if (w==par)
      continue;
    c.push_back(dfs(w, v));
  }
  int ans=1;
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  if (c.size()>=2){
    ans+=c[0]+c[1];
  }
  return ans;
}
int main(){
  int tnum;cin>>tnum;int tcou=0;
  while (tnum--){
    cin>>n;
    for (int i=0;i<1000;++i)
      ngb[i].clear();
    for (int i=0;i<n-1;++i){
      int a, b;cin>>a>>b;--a;--b;
      ngb[a].push_back(b);
      ngb[b].push_back(a);
    }
    int ans=0;
    for (int i=0;i<n;++i)
      ans=max(ans, dfs(i, -1));
    cout<<"Case #"<<++tcou<<": "<<n-ans<<endl;
  }
  return 0;
}
