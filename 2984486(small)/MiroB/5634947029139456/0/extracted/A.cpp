#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<bitset>
#include<cmath>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef bitset<40> T;
void solve() {
  int n,l;
  cin>>n>>l;
  vector<T> outlet(n),device(n);
  REP(i,n) {
    string s;
    cin>>s;
    REP(j,l) outlet[i][j]=s[j]=='1';
  }
  REP(i,n) {
    string s;
    cin>>s;
    REP(j,l) device[i][j]=s[j]=='1';
  }
  vector<unsigned long long> dev(n);
  REP(i,n) dev[i]=device[i].to_ulong();
  sort(dev.begin(), dev.end());
  int rval=l+1;
  REP(first, n) {
    T xo=outlet[0]^device[first];
    vector<unsigned long long > out(n);
    REP(i,n) out[i]=(outlet[i] ^ xo).to_ulong();
    sort(out.begin(), out.end());
    int ok=1;
    REP(i,n) if(out[i]!=dev[i]) ok=0;
    if(ok) rval=min<int>(rval, xo.count());
  }
  if(rval==l+1) cout<<"NOT POSSIBLE";
  else cout<<rval;

}
int main() {
  int T;cin>>T;
  REP(i,T) {
    cout<<"Case #"<<(i+1)<<": ";
    solve();
    cout<<endl;
  }
}
