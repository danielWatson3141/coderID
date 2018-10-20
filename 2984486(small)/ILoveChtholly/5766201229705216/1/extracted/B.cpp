#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
vector<int> s[1005];
int in[1005],tmp[1005],add;
int dfs(int u,int fa){
	int i,sum=1;
	vector<int> arr;
	for(i=0;i<s[u].size();i++){
		int v=s[u][i];
		if(v==fa) continue;
		tmp[v]--;
		int k=dfs(v,u);
		arr.push_back(k);
		sum+=k;
	}
	if(arr.size()>2){
		sort(arr.begin(),arr.end());
		for(i=0;i<arr.size()-2;i++)
			add+=arr[i],sum-=arr[i];
	}
	if(arr.size()==1)
		add+=arr[0],sum-=arr[0];
	return sum;
}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,m,i,j,k,x,y,c=0;
	scanf("%d",&t);
	//t=1;
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			//in[i]=0;
			s[i].clear();
		}
		for(i=0;i<n-1;i++){
			scanf("%d%d",&x,&y);
			s[x].push_back(y);
			s[y].push_back(x);
			//in[x]++;
			//in[y]++;
		}
		int flag=1,ans;
		for(i=1;i<=n;i++){
			add=0;
			dfs(i,-1);
			//printf("%d...",add);
			if(flag || add<ans){
				flag=0;
				ans=add;
			}
		}
		printf("Case #%d: %d\n",++c,ans);
	}
}