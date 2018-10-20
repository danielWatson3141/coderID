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

ll readbin(string& s) {
  ll x = 0;
  int n = s.size();
  rep(i, n) {
    x <<= 1LL;
    x += (s[i] - '0');
  }
  return x;
}

int main(){
  int _T; cin>>_T; // 1-100
  rep(_t,_T){
    int N, L; cin >> N >> L; // num, bits

    int best = L+1;

    vector<long long> initial(N), required(N);
    rep(i, N) {
      string s; cin >> s;
      initial[i] = readbin(s);
    }
    rep(i, N) {
      string s; cin >> s;
      required[i] = readbin(s);
    }
    //cout << initial << endl;
    //cout << required << endl;

    ll P = 1LL << L;
    for (ll p=0; p<P; ++p) {
      rep(i,N) initial[i] ^= p;
      set<ll> s(all(initial));
      int c=0;
      rep(i,N) {
        if (found(s,required[i])) ++c;
      }
      if (c==N) {
        int bc = __builtin_popcountll(p);
        //printf("p=%llx | %d %d\n", p, bc, best);
        if (bc < best) best = bc;
      }
      rep(i,N) initial[i] ^= p;
    }

 answer:
    cout << "Case #" << (1+_t) << ": ";
    if (best <= L)
      cout << best << endl;
    else
      cout << "NOT POSSIBLE" << endl;
  }
  return 0;
}
