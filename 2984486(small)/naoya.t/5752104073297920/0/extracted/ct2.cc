#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

//#include "cout.h"

;
int K;

vector<double> prepare(int w){
  vector<double> at(K, 0); // vd[w][a]: wがaにある率
  at[w] = 1.0;

  double g = (double)(K-1) / K;
  rep(pivot, K) {//pivot
    vector<double> nx(K, 0);
    double d = at[pivot]/K;
    rep(i,K) {
      if(i==pivot)continue;
      nx[i] = d + at[i] * g;
    }

    double u = 0;
    rep(i,K) u += at[i];
    nx[pivot] = u / K;

    rep(i,K) at[i] = nx[i];
    //cout << ":" << pivot << ":" << at << endl;
  }

  vector<double> lat(K, 0);
  rep(i,K) lat[i] = log(at[i] * K);
  return lat;
}

#define LIM 0.1


int main(){
  int _T; cin>>_T; // 1-100

  vector<vector<double> > lats(1000, vector<double>(1000));

  K = 1000;
  rep(i, 1000) {
    vector<double> lat = prepare(i);
    lats[i].assign(all(lat));
  }

  rep(_t,_T){
    int N; cin >> N;

    K = N;

    vector<int> a(N), ra(N);
    rep(i,N) {
      cin >> a[i];
      ra[a[i]] = i;
    }

    //cout << ra << endl;

    double lsum = 0;
    if (K == 1000) {
      rep(i, K) {
        lsum += lats[i][ra[i]];
      }
    } else {
      rep(i, K) {
        vector<double> lat = prepare(i);
        // cout << w << vd << endl;
        lsum += lat[ra[i]];
      }
    }
    cout << lsum << endl;

    cout << "Case #" << (1+_t) << ": ";
    if (lsum > log(1.1))
      cout << "BAD" << endl;
    else
      cout << "GOOD" << endl;
  }
}
