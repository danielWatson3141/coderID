#include<stdio.h>
#include<algorithm>
int tcn,tc;
int n;
int edge[1010][2];
int elist[2010];
int en[1010];
int chk[1010];
int parent[1010];
int mps[1010];
int mpsa[1010];
int root;
int ans;
void dfs(int x){
	int i,sn;
	chk[x]=1;
	for(i=en[x];i<en[x+1];i++){
		if(chk[elist[i]]==0){
			dfs(elist[i]);
			parent[elist[i]]=x;
		}
	}
	sn=0;
	for(i=en[x];i<en[x+1];i++){
		if(parent[elist[i]]==x){
			mpsa[sn]=mps[elist[i]];
			sn++;
		}
	}
	if(sn<2)mps[x]=1;
	else{
		std::sort(mpsa,mpsa+sn);
		mps[x]=mpsa[sn-1]+mpsa[sn-2]+1;
	}
}
int main(){
	int i,j,tans;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d",&n);
		for(i=0;i<n-1;i++){
			scanf("%d%d",&edge[i][0],&edge[i][1]);
		}
		for(i=0;i<n+5;i++){
			en[i]=0;
		}
		for(i=0;i<n-1;i++){
			en[edge[i][0]+2]++;
			en[edge[i][1]+2]++;
		}
		for(i=0;i<n+3;i++){
			en[i+1]+=en[i];
		}
		for(i=0;i<n-1;i++){
			elist[en[edge[i][0]+1]]=edge[i][1];
			en[edge[i][0]+1]++;
			elist[en[edge[i][1]+1]]=edge[i][0];
			en[edge[i][1]+1]++;
		}
		ans=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				chk[j]=0;
				mps[j]=0;
				parent[j]=0;
			}
			root=i;
			dfs(i);
			if(ans<mps[i]){
				ans=mps[i];
			}
		}
		printf("Case #%d: %d\n",tc,n-ans);
	}
}