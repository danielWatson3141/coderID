#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef struct A{
	int id,cc;
	A(){}
	A(int _id,int _cc){
		id = _id, cc = _cc;
	}
}AA;
AA a[1005];
vector <int> v[1005];
int N,c[1005],f[1005];

void dfs(int x,int par){
	int cd = 0,ccc = 0;
	for(int i=0;i<v[x].size();i++){
		int y = v[x][i];
		if(y!=par){
			
			dfs(y,x);
			cd += c[y];
			ccc++;
		}
	}
	c[x] = cd+1;
	int T = c[x]-1;
	if(ccc==1)	f[x] = T;
	else if(ccc>=2){
		f[x] = 10000000;
		for(int i=0;i<v[x].size();i++){
			for(int j=i+1;j<v[x].size();j++){
				if(v[x][i]==par || v[x][j]==par)	continue;
				f[x] = min(f[x],T-c[v[x][i]]+f[v[x][i]]-c[v[x][j]]+f[v[x][j]]);
			}
		}
	}
}


int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
	scanf(" %d",&T);
	for(int t=0;t<T;t++){
		scanf(" %d",&N);
		for(int i=0;i<=N;i++)	v[i].clear();
		for(int i=0;i<N-1;i++){
			int x,y;	scanf(" %d %d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ans = N;
		for(int i=1;i<=N;i++){
			memset(c,0,sizeof(c));
			memset(f,0,sizeof(f));
			dfs(i,-1);
			/*for(int j=1;j<=N;j++)
				printf("%d ",c[j]);
			printf("\n");*/
			ans = min(ans,f[i]);
		}
		printf("Case #%d: %d\n",t+1,ans);
	}
    
    return 0;
}