#include<iostream>
#include<string>
#include<vector>
#include<set>
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;

typedef unsigned long long LL;
string as[151];
string bs[151];

int main() {

  int cas;
  cin>>cas;
  for(int ca = 1; ca<=cas; ++ca) {
    set<LL> bset;
    vector<LL> aset;
    int n,l;
    cin>>n>>l;
    for(int i=0 ;i<n; ++i) {
      cin>>as[i];
      LL temp = 0;
      for(int j=0;j<l; ++j) {
        temp = (temp<<1) + ((LL)(as[i][j]-'0'));
      }
      aset.push_back(temp);
    }
    LL el;
    for(int i=0 ;i<n; ++i) {
      cin>>bs[i];
      LL temp = 0;
      for(int j=0;j<l; ++j) {
        temp = (temp<<1) + ((LL)(bs[i][j]-'0'));
      }
      bset.insert(temp);
      el = temp;
    }

    int rtn = 100000;
    for(int i=0 ;i<n; ++i){
      LL cur = aset[i];
      LL x = cur ^ el;
      int need = __builtin_popcountll(x);
//      cout<<el<<" "<<cur<<" "<<need<<endl;
      bool nope = false;
      for (int j=0 ;j<n; ++j) {
        if (i==j) continue;
        LL check = aset[j] ^ x;
        if (!bset.count(check)) {
 //         cout<<check<<" "<<aset[j]<<endl;
          nope = true;
          break;
        }
      }
      if (!nope) {
        rtn = MIN(rtn, need); 
      }
    }
    cout<<"Case #"<<ca<<": ";
    if (rtn == 100000) {
      cout<<"NOT POSSIBLE"<<endl; 
    } else {
      cout<<rtn<<endl;
    }
  }
}
