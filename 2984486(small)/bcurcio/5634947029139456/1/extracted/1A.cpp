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

#define FE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int xrs[200][200];

void solve(){
  int N = in();
  int L = in();
  
  vector<int> out;
  vector<int> flow;
  
  
  
  int ans = -1;
  int i,j;
  
  for(i=0;i<N;i++){
    string s;
    cin >> s;
    int aux = 0;
    for(j=0;j<L;j++) if(s[j]=='1') aux|=(1<<j);
    out.push_back(aux);
  }
  
  for(i=0;i<N;i++){
    string s;
    cin >> s;
    int aux = 0;
    for(j=0;j<L;j++) if(s[j]=='1') aux|=(1<<j);
    flow.push_back(aux);
  }
  
  set<int> cands;
  
  for(i=0;i<N;i++)
    for(j=0;j<N;j++){
      xrs[i][j] = flow[j]^out[i];
      cands.insert(xrs[i][j]);
    }
  
  FE(cands,itr){
    int num = *itr;
    bool present = true;
    
    for(i=0;i<N;i++){
      bool current = false;
      for(j=0;j<N;j++) if(xrs[i][j]==num){
        current = true;
        break;
      }
      if(!current){
        present = false;
        break;
      }
    }
    
    
    if(present){
      int v = __builtin_popcount(num);
      if(ans==-1 || v<ans) ans = v;
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
