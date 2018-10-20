#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

void solve(){
  int N  = in();
  int cant = 0;
  
  int i;
  
  for(i=0;i<N;i++){
    int v = in();
    if(v==0) continue;
    
    if(v<i+N/2 && v>i) cant++;
    
  }
  cerr << cant << endl;
  
  if(cant>400) cout << "BAD" << endl;
  else cout<<"GOOD" << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<<i+1<<": ";
      solve();
    }
}
