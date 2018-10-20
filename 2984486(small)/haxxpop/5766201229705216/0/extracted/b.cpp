#include<stdio.h>
#include<vector>
using namespace std;
int dfs_dp(int k);
int n;
vector<int> g[2000];
int all_size[2000];
int ch[2000];
int dfs_size(int k){
	ch[k] = 1;
	int sum = 1;
	for(int i = 0 ; i < g[k].size() ; i++ ){
		if( ch[g[k][i]] == 0 )
			sum += dfs_size(g[k][i]);
	}
	all_size[k] = sum;
	return sum;
}
int solve(int root){
	for(int i = 0 ; i < n ; i++ ) ch[i] = 0;
	return dfs_dp(root);
}
int dfs_dp(int k){
	ch[k] = 1;
	int num_child = 0;
	int max1 = 0;
	int max2 = 0;
	for(int i = 0 ;i < g[k].size() ; i++ ){
		if( ch[g[k][i]] == 0 ){
			num_child++;

			int tmp = dfs_dp(g[k][i]);
			if( tmp >= max1 ) {
				max2 = max1;
				max1 = tmp;
			}
			else if( tmp >= max2 ){
				max2 = tmp;
			}
		}
	}
	if( num_child == 0 || num_child == 1 ) return 1;
	return max1+max2+1;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e < t ; e++ ){
		scanf("%d",&n);
		for(int i = 0 ; i < n ;i++ ) g[i].clear();
		for(int i = 0 ; i < n-1 ; i++ ){
			int x,y;
			scanf("%d %d",&x,&y);
			x--;y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans = 10000;
		for(int k = 0 ; k < n ; k++ ){
			for(int i = 0 ;i < n ; i++ ) ch[i] = 0;
			dfs_size(k);
			int tmp = solve(k);
			if( n-tmp < ans ) ans = n-tmp;
		}
		printf("Case #%d: ",e+1);
		printf("%d\n",ans);
	}
}
