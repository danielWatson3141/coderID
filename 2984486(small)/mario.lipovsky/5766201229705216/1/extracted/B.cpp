#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define For(i,N) for(int i=0; i<N; i++)
#define Fore(i,C) for(__typeof((C).begin()) i =(C).begin(); i != (C).end(); ++i)
#define FOR(i,j,k) for(int i=j; i<k; i++)
#define Fors(i,s) for(int i=0; s[i]; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
using namespace std;

int T,N,x,y;
vector<vector<int> > G;

pair<int,int> uprav(int x, int o){
  vector<pair<int,int> > V;
  For(i, G[x].size()) if(G[x][i] != o) V.pb( uprav(G[x][i], x));
  if (V.size() == 0) return mp(1,0);
  if (V.size() == 1) return mp(1,V[0].first+V[0].second);
  if (V.size() == 2) return mp(1+V[0].first+V[1].first, V[0].ss + V[1].ss);
  sort(V.begin(), V.end());
  int vyh = 0;
  For(i, V.size()-2) vyh += V[i].ff+V[i].ss;
  vyh += V[V.size()-2].ss + V[V.size()-1].ss;
  return mp(1 + V[V.size()-2].ff + V[V.size()-1].ff, vyh);
}

int main(){
  scanf("%d", &T);
  For(t,T){
    scanf(" %d", &N);
    G.clear(); G.resize(N, vector<int>(0));
    For(i,N-1){
      scanf(" %d %d", &x, &y);
      G[x-1].pb(y-1);
      G[y-1].pb(x-1);
    }
    int mini = N-1;
    For(i,N) mini = min(mini, uprav(i,-1).second);
    printf("Case #%d: %d\n",t+1,mini);
  }
  return 0;
}