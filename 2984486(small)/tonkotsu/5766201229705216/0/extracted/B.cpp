#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstdio>
#include <queue>
#include <sstream>
using namespace std;

const int INF = 1<<29;
typedef pair<int,int> P;
typedef long long ll;

struct Edge {
   int to;
   Edge(int _t):to(_t){}
};

map<int,int>selectedNode;
vector<int>nodes;
vector<Edge>G[20];
vector<int>deleted;
bool used[20][20];
bool f;
int cnt,N;

void dfs(int n){
   if(!f)return;

   cnt++;
   int c = 0;
   
   for(int i=0; i<G[n].size(); i++){
      int from = n, to = G[n][i].to;
      if(used[from][to])continue;
      if(selectedNode[to])continue;
      c++;
   }

   if(c == 0)return;
   
   if(c != 2){
      f = false;
      return;
   }


   for(int i=0; i<G[n].size(); i++){
      int from = n, to = G[n][i].to;
      if(used[from][to])continue;
      if(selectedNode[to])continue;
      used[from][to] = used[to][from] = true;
      dfs(to);
   }
   
}

int isOk(int size){
   
   for(int i=0; i<(int)nodes.size(); i++){
      f = true;
      cnt = 0;
      if(selectedNode[nodes[i]])continue;
      memset(used,0,sizeof(used));
      dfs(nodes[i]);
      if(f && cnt == N - size){
//	 cout << "ok = " << nodes[i] << " size = " << size << endl;
//	 for(int j=0; j<deleted.size(); j++) cout << deleted[j] << " ";
//	 cout << endl;
	 return size;
      }
   }
   return -1;
}

int main(){
   int T;
   cin >> T;

   for(int t=1; t<=T; t++){

      nodes.clear();
      for(int i=0; i<20; i++) G[i].clear();
      
      cin >> N;
      set<int>se;
      
      for(int i=0; i<N-1; i++){
	 int from, to;
	 cin >> from >> to;
	 G[from].push_back(Edge(to));
	 G[to].push_back(Edge(from));
	 
	 if(!se.count(from)){
	    nodes.push_back(from);
	    se.insert(from);
	 }

	 if(!se.count(to)){
	    nodes.push_back(to);
	    se.insert(to);
	 }
      }

      int ans = 1<<29;
      
      for(int i=0; i<(1<<N); i++){
	 selectedNode.clear();
	 deleted.clear();
	 int size = 0;
	 for(int j=0; j<N; j++){
	    if(i & (1<<j)){
	       size++;
	       selectedNode[nodes[j]]++;
	       deleted.push_back(nodes[j]);
	    }
	 }

	 int tmp = isOk(size);
	 if(tmp != -1) ans = min(ans,tmp);
      }

      
      cout << "Case #" << t << ": " << ans << endl;
   }
   return 0;
}
