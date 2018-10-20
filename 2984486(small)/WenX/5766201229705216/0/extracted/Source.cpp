#pragma warning(disable:4996)
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int ans;
int n,root;
int neib[1111][1111];
int neib_n[1111];

int full_size[1111];
int tree_size[1111];

void search(int node, int father){
	if(neib_n[node]==1){
		full_size[node]=1;
		tree_size[node]=1;
		return;
	}
	
	int son_num=0;
	tree_size[node]=1;

	for(int i=0;i<neib_n[node];i++)
		if(neib[node][i]!=father){
			son_num++;
			search(neib[node][i],node);
			tree_size[node]+=tree_size[neib[node][i]];
		}

	int max_i1=-1,max_i2=-1;
	if(son_num>=2){
		full_size[node]=1;//+two biggest
		for(int i=0;i<neib_n[node];i++)
			if(neib[node][i]!=father)
				if(max_i1==-1){
					max_i1=neib[node][i];
				}else if(max_i2==-1){
					max_i2=neib[node][i];
				}else if(full_size[neib[node][i]]>full_size[max_i1]){
					swap(max_i1,max_i2);
					max_i1=neib[node][i];
				}else if(full_size[neib[node][i]]>full_size[max_i2]){
					max_i2=neib[node][i];
				}
		full_size[node]+=full_size[max_i1]+full_size[max_i2];
	}else{
		//del all son
		full_size[node]=1;
	}
}

int main(){
	int tt;
	scanf("%d",&tt);
	for(int cc=1;cc<=tt;cc++){
		scanf("%d",&n);
		memset(neib_n,0,sizeof(neib_n));
		for(int i=0;i<n-1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			neib[u][neib_n[u]++]=v;
			neib[v][neib_n[v]++]=u;
		}

		ans=-1;
		for(int i=1;i<=n;i++){
			root=i;
			search(i,-1);
			if(ans==-1 || ans<full_size[root]){
				ans=full_size[root];
			}
		}

		printf("Case #%d: ",cc);
		printf("%d",n-ans);
		printf("\n");
	}
	return 0;
}