#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int N;
int child[1005];
vector<int> cd[1005],E[1005];

void dfs(int u, int p){
  child[u] = 1;
  for(int c = 0 ; c < E[u].size() ; c++){
    int v = E[u][c];
    if(v != p){
      dfs(v,u);
      child[u] += child[v];
    }
  }
}

int fullize(int u, int p){
  // printf("%d %d %d\n",u,p,E[u].size());
  if(p == -1){
    if(E[u].size() == 0)
      return 0;
    else if(E[u].size() == 1)
      return child[E[u][0]];
    else if(E[u].size() >= 2){
      for(int c = 0 ; c < E[u].size() ; c++){
	int v = E[u][c];
	cd[u].push_back(fullize(v,u)-child[v]);
      }
      sort(cd[u].begin(),cd[u].end());
      return child[u]-1+cd[u][0]+cd[u][1];
    }
  }
  else{
    if(E[u].size() == 1)
      return 0;
    else if(E[u].size() == 2){
      for(int c = 0 ; c < E[u].size() ; c++)
	if(E[u][c] != p)
	  return child[E[u][c]];
    }
    else if(E[u].size() >= 3){
      for(int c = 0 ; c < E[u].size() ; c++){
	int v = E[u][c];
	if(v != p)
	  cd[u].push_back(fullize(v,u)-child[v]);
      }
      sort(cd[u].begin(),cd[u].end());
      return child[u]-1+cd[u][0]+cd[u][1];
    }
  }
}

int main(){
  scanf("%d",&T);
  for(int cc = 1 ; cc <= T ; cc++){
    scanf("%d",&N);
    for(int c = 1 ; c <= N ; c++)
      E[c].clear();
    for(int c = 1 ; c < N ; c++){
      int a,b;
      scanf("%d %d",&a,&b);
      E[a].push_back(b), E[b].push_back(a);
    }
    int sol = N;
    for(int c = 1 ; c <= N ; c++){
      for(int d = 1 ; d <= N ; d++)
	cd[d].clear();
      dfs(c,-1);
      int jjj = fullize(c,-1);
      sol = min(sol,jjj);
      // printf("%d: %d\n",c,jjj);
      // printf("---------\n");
    }
    printf("Case #%d: %d\n",cc,sol);
  }
}
