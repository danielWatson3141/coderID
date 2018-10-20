#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T;
vector<int> v[1001];
int N;
bool mark[1001];

struct abc {
	int n;
	int v;
	bool operator<(const abc &t) const {
		return v < t.v;
	}
};

int dfs(int root, int parent){
	int num = 1;
	for(int i=0;i<v[root].size();i++){
		if(v[root][i] != parent)
			num += dfs(v[root][i],root);
	}
	return num;
}

int bfs(int root){
	queue<int> Q;
	Q.push(root);
	mark[root] = true;
	int num = 0;
	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		vector<int> child;
		for(int i=0;i<v[node].size();i++){
			if(mark[v[node][i]]) continue;
			child.push_back(v[node][i]);
		}
		if(child.size()==1){			
			num += dfs(child[0],node);
		}
		else if(child.size()>2){
			vector<abc> v1;
			
			for(int i=0;i<child.size();i++){
				abc a;
				a.n = child[i];
				a.v = dfs(child[i],node);
				//printf("a:%d %d\n",a.n,a.v);
				v1.push_back(a);
			}
			sort(v1.begin(),v1.end());
			for(int i=0;i<v1.size()-2;i++){
				num += v1[i].v;
			}
			Q.push(v1[v1.size()-1].n);
			mark[v1[v1.size()-1].n] = true;
			Q.push(v1[v1.size()-2].n);
			mark[v1[v1.size()-2].n] = true;
		}
		else {
			for(int i=0;i<child.size();i++){
				Q.push(child[i]);
				mark[child[i]] = true;
			}
		}
	}
	return num;
}

int main(){
	scanf("%d",&T);
	for(int Case = 1; Case<=T;Case++){
		//fprintf(stderr,"Case %d\n",Case);
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			v[i].clear();
		}
		for(int i=1;i<N;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int min = 123123;
		for(int i=1;i<=N;i++){
			for(int i=1;i<=N;i++){
				mark[i] = false;
			}
			int num = bfs(i);
			//printf("%d\n",num);
			if(num<min)
				min = num;
		}
		printf("Case #%d: %d\n",Case,min);
	}
}