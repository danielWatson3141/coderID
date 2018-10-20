#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include<vector>
using namespace std;
int dp[1100][1100];
vector<int> edge[1100];
int n;
int fun(int cur , int f){
	if(dp[cur][f]!=0)return dp[cur][f];
	if(f==0){
		if(edge[cur].size()<2){
			return dp[cur][f] = 1;
		}
		int m1,m2;
		m1 = fun( edge[cur][0], cur);
		m2 = fun( edge[cur][1], cur);
		if(m1<m2){
			int temp = m1;
			m1 = m2;
			m2 = temp;
		}
		for(int i = 2;i<edge[cur].size();i++){
			int k = fun(edge[cur][i], cur);
			if (k<=m2)continue;
			if(k>m2 && k<m1){
				m2 = k;
				continue;
			}
			m2 = m1;
			m1 = k;
		}
		return dp[cur][f] = 1 + m1 + m2;
	}
	if(edge[cur].size()<=2){
		return dp[cur][f] = 1;
	}
	int m1 = -1, m2 = -1;
	for(int i = 0;i<edge[cur].size();i++)if(edge[cur][i]!=f){
		if(m1 == -1){
			m1 = fun(edge[cur][i], cur);
			continue;
		}
		if(m2 == -1){
			m2 = fun(edge[cur][i], cur);
			if(m1 <m2){
				int temp = m1;
				m1 = m2;
				m2 = temp;
			}
			continue;
		}
		int k = fun(edge[cur][i], cur);
		if (k<=m2)continue;
		if(k>m2 && k<m1){
			m2 = k;
			continue;
		}
		m2 = m1;
		m1 = k;
		
	}
	return dp[cur][f] = 1+m1+m2;

}
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int t;
	scanf("%d",&t);
	for(int casenum = 0; casenum<t;++casenum){
		for(int i = 0;i<1100;i++){
			edge[i].clear();
			for(int j = 0;j<1100;j++)dp[i][j] = 0;
		}
		scanf("%d",&n);
		for(int i = 0;i<n-1;i++){
			int u,v;
			scanf("%d%d",&u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int ans = -1;
		for(int i = 1;i<=n;i++){
			int m = fun(i,0);
			if(ans == -1 || ans < m ) ans = m;
		}
		printf("Case #%d: %d\n",casenum+1, n-ans);
	}
	getchar();
	return 0;
}