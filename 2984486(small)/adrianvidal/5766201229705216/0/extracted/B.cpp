#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<bitset>
#include<queue>
using namespace std;
#define pii pair<int,int>
int pred[2000];
int toposort[2000];
bitset<2000> complete;
int sz[2000];

vector<int> adj[2000];
int ind;

void dfs(int node){
   //cout<<node<<" ";
   for(int i=0; i<adj[node].size(); i++){
      int nxt=adj[node][i];
	  if (pred[nxt]==-1){
	     pred[nxt]=node;
		 dfs(nxt);
	  }
   }
   toposort[ind++]=node;
}

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int n; scanf("%d",&n);
	  for(int i=0; i<n; i++) adj[i].clear();
	  for(int i=0; i+1<n; i++){
	     int a,b; scanf("%d%d",&a,&b);
		 a--; b--;
		 adj[a].push_back(b);
		 adj[b].push_back(a);
	  }
	  /*
	  for(int i=0; i<n; i++){
	     printf("%d: ",i);
		 for(int j=0; j<adj[i].size(); j++) printf("%d ",adj[i][j]);
		 puts("");
	  }
	  puts("");*/
	  int maxval=0;
	  for(int i=0; i<n; i++){
	     fill(pred,pred+n,-1);
		 pred[i]=i;
		 ind=0;
		 dfs(i);
		 
		 for(int j=0; j<n; j++){
		    int here=toposort[j];
			sz[here]=1;
			vector<int> v;
			for(int k=0; k<adj[here].size(); k++){
			   int nxt=adj[here][k];
			   if (nxt==pred[here]) continue;
			   v.push_back(sz[nxt]);
			}
			if (v.size()<2) continue;
			sort(v.rbegin(),v.rend());
			sz[here]+=v[0]+v[1];
		 }
		 maxval=max(maxval,sz[i]);
		 //printf("root at %d: %d\n",i+1,sz[i]);
	  }
	  printf("Case #%d: %d\n",cs+1,n-maxval);
   }
}