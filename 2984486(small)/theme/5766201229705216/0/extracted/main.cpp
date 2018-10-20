#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n;
vvi adjList;

int calc(int x);
ii dfs(int x,int prev);

int main() {
	int cases;
	scanf("%d",&cases);
	for(int round=1; round<=cases; round++) {
		scanf("%d",&n);
		adjList.assign(n,vi());
		for(int i=0; i<n-1; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}
		int ans=n-1;
		for(int i=0; i<n; i++)
			ans=min(ans,calc(i));
		printf("Case #%d: %d\n",round,ans);
	}
	return 0;
}

int calc(int x) {
	adjList[x].push_back(-1);
	int temp=dfs(x,-1).first;
	adjList[x].pop_back();
	return temp;
}

ii dfs(int x,int prev) {
	vii mem;
	mem.reserve(adjList[x].size()-1);
	for(int i=0; i<(int)adjList[x].size(); i++)
		if(adjList[x][i]!=prev) {
			mem.push_back(dfs(adjList[x][i],x));
		}
	if(mem.size()==0)
		return ii(0,1);
	else if(mem.size()==1)
		return ii(mem[0].second,mem[0].second+1);
	else {
		vi gain(mem.size());
		int allSize=0;
		for(int i=0; i<(int)mem.size(); i++) {
			allSize+=mem[i].second;
			gain[i]=mem[i].second-mem[i].first;
		}
		sort(gain.begin(),gain.end(),greater<int>());
		return ii(allSize-gain[0]-gain[1],allSize+1);
	}
}
