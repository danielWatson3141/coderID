#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
template<class T> void atov(int n,T A[],vector<T> &vi){
  vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);
}//NOTES:atov(
template<class T> void stov(string s,vector<T> &vi){
  vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));
}
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template <typename T> inline T Gcd( T a, T b) {
  // a, b should be unnegative
  if ( b == 0) return a;
  return Gcd( b, a % b);
}


ifstream input;
ofstream output;

void init() {

}


bool is_btree(vector< vector<int> > a) {
  int s = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i].size() == 2) {
      ++s;
    }
    if (s > 1) {
      return false;
    }
    if (a[i].size() != 1 && a[i].size() !=2 && a[i].size() != 3) {
      return false;
    }
  }
  if (s == 0) {
    return false;
  }
  return true;
}
void build_tree(vector< vector<int> >&r_tree, \
                const vector< vector<int> >&adj,int r, int pa) {
  for(int i = 0; i< adj[r].size(); ++i) {
    int cur_c = adj[r][i];
    if (cur_c == pa)
      continue;
    r_tree[r].push_back(cur_c);
    build_tree(r_tree, adj, cur_c, r);
  }
}
int optimize(const vector< vector<int> >& r_tree, int r) {
  if (r_tree[r].size() < 2) {
    return 1;
  }
  vector<int> a;
  for (int i = 0; i< r_tree[r].size(); ++i) {
    a.push_back(optimize(r_tree, r_tree[r][i]));
  }
  sort(a.begin(), a.end(), std::greater<int>());
  return a[0] + a[1] + 1;
}
void Work() {
  int n;
  vector<vector<int>> adj;
  input>>n;
  for (int i = 0; i< n; ++i) {
    adj.push_back( vector<int>());
  }

  for (int i = 0; i< n - 1; ++i) {
    int t1, t2;
    input>>t1>>t2;
    --t1; --t2;                                // 
    adj[t2].push_back(t1);
    adj[t1].push_back(t2);
  }
  if (is_btree(adj)) {
    output<<0<<endl;
    return;
  }

  int best = 1;
  for (int i = 0; i< n; ++i) {
    vector< vector<int> >r_tree;
    r_tree.clear();
    for (int j = 0; j < n; ++j) r_tree.push_back( vector<int>());
    build_tree(r_tree, adj, i, -1);
    // for (int j = 0; j < n; ++j) {
    //   cout<<j<<" :";
    //   for (int k = 0; k < r_tree[j].size(); ++k) {
    //     cout<<r_tree[j][k]<<" ";
    //   }
    //   cout<<endl;
    // }
    int res = optimize(r_tree, i);
    if (res > best) {
      best = res;
    }
  }
  output<<n - best<<endl;
}
int main() {
  
int t = 0;
  string inputfile("input.in");
  string outputfile("output.out");
  input.open(inputfile.c_str());
  output.open(outputfile.c_str());
  input>>t;
  int tcase = 0;
  init();
  while( t--) {
    //    cout<<"Case"<<endl;
    ++tcase;
    output<<"Case #"<<tcase<<": "; 
    Work();
  }
}
