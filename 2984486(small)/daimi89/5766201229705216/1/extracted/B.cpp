#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > adj;

int size[1000];
int cost[1000];

void dfs(int u,int p) {
  size[u]=1;
  int v1=-1, v2=-1;
  for (int d=0; d<adj[u].size(); d++){
    int v=adj[u][d];
    if (v!=p) {
      dfs(v,u);
      size[u]+=size[v];
      if (v1<0) v1=v;
      else if (v2<0) v2=v;
      else {
	if (cost[v1] + size[v] > size[v1] + cost[v] ||
	    cost[v2] + size[v] > size[v2] + cost[v])
	  if (cost[v1] + size[v2] < cost[v2] + size[v2])
	    v2=v;
	  else
	    v1=v;
      };
    };
  };
  if (v2<0)
    cost[u]=size[u]-1; // keep only u
  else
    cost[u]=size[u]-1-size[v1]-size[v2] + cost[v1] + cost[v2];
};

main () {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int N;
    cin >> N;
    adj=vector< vector<int> >(N,vector<int>(0));
    for (int i=1; i<N; i++) {
      int X,Y;
      cin >> X >> Y;
      adj[X-1].push_back(Y-1);
      adj[Y-1].push_back(X-1);
    }
    int result=N;

    for (int r=0; r<N; r++) {
      dfs(r,-1);
      result = min(result, cost[r]);
    }

    cout << "Case #" << t << ": " << result << endl;
  };
};
