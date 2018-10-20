#include <iostream>
#include <map>
#include <vector>
using namespace std ;
vector<vector<int> > adj ;
vector<int> empty ;
vector<pair<int, int> > edges ;
map<pair<int, int>, int> benefit ;
map<pair<int, int>, int> cnt ;
int countem(int a, int b) {
  pair<int, int> e = make_pair(a, b) ;
  if (cnt.find(e) != cnt.end())
    return cnt[e] ;
  int r = 1 ;
  for (int i=0; i<adj[b].size(); i++)
    if (a != adj[b][i])
      r += countem(b, adj[b][i]) ;
  cnt[e] = r ;
  return r ;
}
int maketree(int a, int b) {
  pair<int, int> e = make_pair(a, b) ;
  if (benefit.find(e) != benefit.end())
    return benefit[e] ;
  int deg = adj[b].size() ;
  int r = 0 ;
  if (deg == 1) {
    r = 1 ;
  } else if (deg == 2) {
    r = 1 ;
  } else {
    vector<int> v ;
    for (int i=0; i<adj[b].size(); i++)
      if (a != adj[b][i])
	v.push_back(maketree(b, adj[b][i])) ;
    sort(v.begin(), v.end()) ;
    r = v[v.size()-1] + v[v.size()-2] + 1 ;
    //    cout << "Benefit of " << a << " " << b << " is " << r << endl ;
  }
  benefit[e] = r ;
  return r ;
}
int main(int argc, char *argv[]) {
  int kases ;
  cin >> kases ;
  for (int kase=1; kase<=kases; kase++) {
    cout << "Case #" << kase << ": " ;
    int N ;
    cin >> N ;
    adj.clear() ;
    edges.clear() ;
    benefit.clear() ;
    cnt.clear() ;
    for (int i=0; i<N; i++)
      adj.push_back(empty) ;
    for (int i=0; i<N-1; i++) {
      int a, b ;
      cin >> a >> b ;
      a-- ; b-- ;
      adj[a].push_back(b) ;
      adj[b].push_back(a) ;
      edges.push_back(make_pair(a, b)) ;
      edges.push_back(make_pair(b, a)) ;
    }
    for (int i=0; i<edges.size(); i++) {
      int a = edges[i].first ;
      int b = edges[i].second ;
      countem(a, b) ;
    }
    for (int i=0; i<edges.size(); i++) {
      int a = edges[i].first ;
      int b = edges[i].second ;
      maketree(a, b) ;
    }
    int r = 1 ;
    for (int i=0; i<N; i++) {
      int deg = adj[i].size() ;
      if (deg == 1)
	continue ;
      vector<int> v ;
      for (int j=0; j<adj[i].size(); j++)
	v.push_back(maketree(i, adj[i][j])) ;
      sort(v.begin(), v.end()) ;
      int t = v[v.size()-1] + v[v.size()-2] + 1 ;
      //      cout << "At " << i << " deg " << deg << " have " << t << endl ;
      if (t > r)
	r = t ;
    }
    r = N - r ;
    cout << r << endl ;
  }
}
