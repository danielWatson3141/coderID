#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> s, t;
ll read_bin(){
  string S;cin>>S;
  ll ret=0;
  for (int i=0;i<S.size();++i)
    ret = ret*2LL+ll(S[i]-'0');
  return ret;
}
int bit_count(ll mask){
  int ret=0;
  while (mask!=0){
    ret += mask%2;
    mask/=2;
  }
  return ret;
}
int main(){
  int tnum;cin>>tnum;int tcou=0;
  while (tnum--){
    s.clear();
    t.clear();
    int n, l;cin>>n>>l;
    for (int i=0;i<n;++i)
      s.push_back(read_bin());
    for (int i=0;i<n;++i)
      t.push_back(read_bin());
    vector<ll> masks;
    for (int i=0;i<n;++i)
      for (int j=0;j<n;++j)
        masks.push_back(s[i]^t[j]);
    sort(s.begin(), s.end());
    int best=1000;
    for (int i=0;i<masks.size();++i){
      ll mask=masks[i];
      for (int j=0;j<n;++j)
        t[j]^=mask;
      sort(t.begin(), t.end());
      if (s==t)
        best = min(best, bit_count(mask));
      for (int j=0;j<n;++j)
        t[j]^=mask;
    }
    cout<<"Case #"<<++tcou<<": ";
    if (best>900)
      cout<<"NOT POSSIBLE";
    else
      cout<<best;
    cout<<endl;
  }
  return 0;
}
