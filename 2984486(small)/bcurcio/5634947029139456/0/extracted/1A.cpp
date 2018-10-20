#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

string np = "NOT POSSIBLE";

typedef vector<string> vstr;

void solve(){
  int N = in();
  int L = in();
  
  vector<int> out;
  set<int> flow;
  
  
  
  int ans = -1;
  int i,j;
  
  for(i=0;i<N;i++){
    string s;
    cin >> s;
    int aux = 0;
    for(j=0;j<L;j++) if(s[j]=='1') aux|=(1<<j);
    //*cerr << " o " << aux << endl;
    out.push_back(aux);
  }
  
  for(i=0;i<N;i++){
    string s;
    cin >> s;
    int aux = 0;
    for(j=0;j<L;j++) if(s[j]=='1') aux|=(1<<j);
    //*cerr << " f " << aux << endl;
    flow.insert(aux);
  }
  
  for(i=0;i<(1<<L);i++){
    
    for(j=0;j<N;j++){
      //*cerr << i << ' ' << (j^i) << endl;
      if(flow.find(out[j]^i)==flow.end()) break;
    }
    
    if(j==N){
      int res = __builtin_popcount(i);
      if(ans==-1 || res<ans) ans = res;
    }
    
  }
  
  if(ans == -1) cout << np << endl;
  else cout << ans << endl;
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<<i+1<<": ";
      solve();
    }
}
