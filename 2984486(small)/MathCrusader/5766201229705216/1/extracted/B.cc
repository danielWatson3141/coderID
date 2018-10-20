#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 1030;

vector<int> adj[MAX_N];

pair<int,int> A[MAX_N][MAX_N];

pair<int,int> f(int v,int par){
  if(A[v][par].first != -1) return A[v][par];
  
  multiset<int> S;
  
  int anc = 1;
  //int going_to_delete = 0;
  for(int i=0;i<adj[v].size();i++){
    int w = adj[v][i];
    if(w == par) continue;
    pair<int,int> tmp = f(w,v);
    //going_to_delete += tmp.first;
    S.insert(tmp.second - tmp.first);
    anc += tmp.second;
  }
  
  // You must delete everything except me
  if(S.size() <= 1) return A[v][par] = make_pair(anc-1,anc);
  
  // Use the largest differences.
  set<int>::reverse_iterator it = S.rbegin();
  int x = *it; ++it;
  int y = *it;
  
  return A[v][par] = make_pair(anc - x - y - 1,anc);
}

void do_case(){
  int n,x,y;
  cin >> n;
  
  for(int i=0;i<n;i++)
    adj[i].clear();
  
  for(int i=0;i<n-1;i++){
    cin >> x >> y; x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
    
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      A[i][j].first = -1;
  
  int best = n-1; // Delete all but one...
  for(int r=0;r<n;r++){
    pair<int,int> tmp = f(r,r);
    if(tmp.first < best){
      best = tmp.first;
    }
  }

  cout << best << endl;
}

int main(){
  int T,C=1;
  cin >> T;
  while(T--){
    cout << "Case #" << C++ << ": ";
    do_case();
  }
  
  return 0;
}
