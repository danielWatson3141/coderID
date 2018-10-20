#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

int E;
int lst[3000];
int nxt[3000];
int  vec[3000];

void add_edge(int u,int v){
  nxt[E] = lst[u]; vec[E] = v; lst[u] = E++;
  swap(u,v);
  nxt[E] = lst[u]; vec[E] = v; lst[u] = E++;
}

typedef pair<int,int> pii;

pii dfs(int x, int p){
  int i;
  //*cerr << "x " << x << endl;
  //*in();
  vector<pii> ve;
  int acum = 1;
  for(i=lst[x];i!=-1;i=nxt[i]) if(vec[i]!=p){
    //*cerr << vec[i] << ' ' << x << ' ' << p <<  ' ' << i <<endl;
    pii aux = dfs(vec[i],x);
    //*cerr << aux.first << ' ' << aux.second << endl;
    ve.push_back(aux);
    acum+=aux.first;
  }
  
  sort(ve.begin(),ve.end());
  
  int n = ve.size();
  //*cerr << "D " << n << endl;
  if(n==0) return make_pair(acum,0);
  if(n==1) return make_pair(acum,ve[0].first);
  if(n>1)  return make_pair(acum,(acum-1)-ve[n-1].first-ve[n-2].first+ve[n-1].second+ve[n-2].second);
  cout << "error" << endl;
  return make_pair(0,0);
}

int sol(int x){
  //*cerr << "asd "<<x  << endl;
  return dfs(x,-1).second;
  
}

void solve(){
  E = 0;
  memset(lst,-1,sizeof lst);
  
  int i;
  
  int N = in();
  
  for(i=0;i<N-1;i++){
    int u = in()-1;
    int v = in()-1;
    //*cerr << u << ' ' << v << endl;
    add_edge(u,v);
    //*cerr << lst[i*2] << ' ' << nxt[i*2] << ' ' << vec[i*2] << endl;
    //*cerr << lst[i*2+1] << ' ' << nxt[i*2+1] << ' ' << vec[i*2+1] << endl;
  }
  
  int ans = N+1;
  for(i=0;i<N;i++){
    int v = sol(i);
    if(v<ans) ans = v;
  }
  
  cout << ans << endl;
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<<i+1<<": ";
      solve();
    }
}
