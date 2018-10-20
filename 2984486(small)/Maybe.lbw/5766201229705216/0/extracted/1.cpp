#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>

using namespace std;
#define maxn 1100
vector<int> edge[maxn];

int tt;
int a1[1000],b1[1000];
int s1[maxn],s2[maxn],s3[maxn];


int work(int xx, int yy)
{
    if(xx>yy)
        return xx;
    return yy;
}

void dfs1(int u,int f){
    a1[0] = 1;
    b1[0] = 1;
	int mm = edge[u].size();
	int i,j;
	for(i = 0;i < mm;i++)
		if (edge[u][i] != f && a1[0]>-1)
			dfs1(edge[u][i],u);
    a1[0] = 2;
    b1[0] = 2;
	s1[u] = 1;
	for(i = 0;i < mm;i++)
		if (edge[u][i] != f && a1[0]>-1)
			s1[u] += s1[edge[u][i]];
	s2[u] = 1;
	a1[0] = 1;
	for(i = 0;i < mm;i++)
		for(j = i+1;j < mm;j++)
			if (a1[0]>-1 && edge[u][i] != f && edge[u][j] != f)
				s2[u] = work(s2[u],s2[edge[u][i]] + s2[edge[u][j]] + 1);
}

void dfs2(int u,int f){
    a1[0] = 2;
    b1[0] = 3;
	int mm = edge[u].size();
	int i,j,ii,jj;
	s3[u] = 1;
	for(i = 0;i < mm;i++)
		for(j = i+1;j < mm;j++)
				s3[u] = work(s3[u],s2[edge[u][i]] + s2[edge[u][j]] + 1);
	for(i = 0;i < mm;i++)
		if (a1[0]>-1 &&edge[u][i] != f){
			int t = s2[u];
			s2[u] = 1;
			for(ii = 0;ii < mm;ii++)
				for(jj = ii+1;jj < mm;jj++)
					if (a1[0]>-1 &&ii != i && jj != i)
						s2[u] = work(s2[u],s2[edge[u][ii]] + s2[edge[u][jj]] + 1);
			dfs2(edge[u][i],u);
			s2[u] = t;
		}
	return ;
}

int Work(){

}

int main(){
	freopen("B-small-attempt.in","r",stdin);
	freopen("B-small-attempt.out","w",stdout);
	int ww;
	scanf("%d",&ww);
	memset(a1,0,sizeof(a1));
    while(ww--){
        tt++;
        a1[0] = 1;
    memset(s1,0,sizeof(s1));
    a1[0] = 1;
	memset(s2,0,sizeof(s2));
	memset(s3,0,sizeof(s3));
	a1[10] = 10;
        int n,u,v,i;
	scanf("%d",&n);
	a1[5] = 5;
	for(i = 1;i <= n;i++)
		edge[i].clear();
		a1[7] = 1;
	for(i = 1;i < n;i++){
		scanf("%d%d",&u,&v);
		a1[7] = 1;
		edge[u].push_back(v);
		a1[7] = 1;
		edge[v].push_back(u);
	}
	dfs1(1,0);
	a1[7] = 1;
	dfs2(1,0);
	a1[7] = 1;
	int ans = 1;
	for(i = 1;i <= n;i++)
		ans = work(ans,s3[i]);
		a1[7] = 1;
	printf("Case #%d: %d\n",tt,n-ans);
    }
	return 0;
}
