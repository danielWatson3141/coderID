/*
ID: ahri1
PROG: C
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

template<typename T> string v_2_s(vector<T> &a) { stringstream sb; __typeof(a.begin()) i = a.begin(); if (i!=a.end()) { sb << *i; ++i; } for (; i!=a.end();++i) { sb << " " << *i; } return sb.str(); }


string bad = "BAD";
string good = "GOOD";
double avg= 9.6;
double calc(vector<int> X) {
  int swaps = 0;
  int64 dist = 0;
  int n = sz(X);
  for(int i=0;i<sz(X);++i){
    if (X[i]!=i) swaps++;
    // dist+=min(abs(i-X[i]), abs(i-X[i]-n/2));  
    dist+=min(abs(i-X[i])*abs(i-X[i]), abs(i-X[i]-n/2)*abs(i-X[i]-n/2));  
  }
  // cout << dist << endl;
  return sqrt(dist);
}

double all = 0;
void solve(){
  int n;
  cin >> n;
  double dist = 0;
  int swaps = 0;
  vector<int> X(n);
  for(int i=0;i<n;++i){
    cin >> X[i];
    if (X[i]!=i) swaps++;
  }
  dist = calc(X);
  all+=dist;
  if (swaps==0) {
    cout << good << endl;
  } else {    
//    if (dist>swaps) swap(swaps, dist);
    // cout << dist/swaps << endl;
    // dist/=n;
    dist/=swaps;
    // cout << dist/avg << endl;
    if (dist/avg < 0.98 || dist/avg > 1.02) {
      cout << bad << endl;
    } else {
      cout << good << endl;
    }
  }
}

void rek(vector<int> &v, int d, map<string, int> &sols, vector<vector<int> > &counts, map<string, double> &dists) {
  int n = sz(v);
  if (d==n) {
    for(int i=0;i<n;++i){
      counts[i][v[i]]++;
    }
    string sig  = v_2_s(v);
    sols[sig]++;
    dists[sig]=calc(v);
    return;
  }
  for(int i=0;i<n;++i){
    swap(v[d], v[i]);
    rek(v, d+1, sols, counts, dists);
    swap(v[d], v[i]);
  }
}



void gen(int n) {
  cout << "moo" << endl;
  vector<int> v;
  for(int i=0;i<n;++i){
    v.push_back(i);
  }
  map<string, int> sols;
  map<string, double> dists;
  vector<vector<int> > counts(n, vector<int>(n));
  rek(v, 0, sols, counts, dists);
  int sum=0;
  foreach(x, sols) {
    string moo = x->first;  
    int count=0;
    int dist = 0;
    int dist2 = 0;
    for(int i=0;i<sz(moo);i+=2){
      if (moo[i]!='0'+i/2) count++;
      dist+=abs(moo[i]-'0'-i/2);
      dist2+=abs(moo[i]-'0'-i/2)*abs(moo[i]-'0'-i/2);
    }    
    cout << x->first << " [" << x->second << "] <" << count << "> {" << dist << " " << dist2 << " " << dists[x->first] << "} :: " << dists[x->first]/count <<endl;
    sum+=x->second;
  }
  for(int i=0;i<n;++i){
    // cout << i << " :: " << v_2_s(counts[i]) << endl;
  }
  
  int norm = counts[0][0];
  
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      counts[i][j]=counts[i][j]*1000/norm;
    }
  }
  
  for(int i=0;i<n;++i){
    cout << i << " :: " << v_2_s(counts[i]) << endl;
  }
  
  cout << sum << " " << sz(sols) << " " << 1.0*sum/sz(sols) << endl;
}



int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  // cout << "ALL: " << all/1000/120 << endl;
  for(int j=3;j<6;++j){
    // gen(j);
  }
  
  return 0;
}
