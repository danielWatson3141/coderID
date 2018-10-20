#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector<int> edges[1111];
int treeSize[1111];

int dfs(int x,int fa=-1)
{
	treeSize[x] = 1;
	vector<int> subTree;
	for(auto& y: edges[x])
	{
		if(y == fa) continue;

		int tcost = dfs(y,x);
		subTree.push_back(treeSize[y]-tcost); // save
		treeSize[x] += treeSize[y];
	}
	sort(subTree.begin(),subTree.end());
	
	if(subTree.size() == 0) return 0;
	else if(subTree.size() == 1) return treeSize[x] - 1;
	return treeSize[x] - 1 - subTree[subTree.size()-1] - subTree[subTree.size()-2];
}

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++TK);
		int N = 0;
		scanf("%d",&N);
		for(int i = 0;i <= N;i++) edges[i].clear();
		for(int i = 0;i < N-1;i++)
		{
			int x = 0;
			int y = 0;
			scanf("%d %d",&x,&y);
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		int ans = N;
		for(int i = 1;i <= N;i++)
		{
			memset(treeSize,0,sizeof(treeSize));
			ans = min(ans, dfs(i));
		}
		printf("%d\n",ans);
	}
	while(getchar() != EOF);
	return 0;
}
