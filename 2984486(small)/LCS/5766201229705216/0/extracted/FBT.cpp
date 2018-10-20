#include<stdio.h>
#include<vector>

using namespace std;

#define MAX 1011

vector<int>edge[MAX];

FILE *input=freopen("input.txt","r",stdin);
FILE *output=freopen("output.txt","w",stdout);

int n;
bool is_gone[MAX];
int dp[MAX];

void sw(int &a,int &b){
	int c;
	c=a;
	a=b;
	b=c;
}

int dfs(int w){
	int i,k;
	int sum=1;
	int max1=-1;
	int max2=-1;
	int qq;
	int gs=0;

	is_gone[w]=1;

	for(i=0;i<edge[w].size();i++){
		if(is_gone[edge[w][i]])
			continue;
		gs++;
		k=dfs(edge[w][i]);
		qq=k-dp[edge[w][i]];
		if(max2==-1||max2<qq){
			max2=qq;
		}
		if(max1==-1||max1<max2)
			sw(max1,max2);
		sum+=k;
	}
	if(gs==0)
		dp[w]=0;
	if(gs==1){
		dp[w]=sum-1;
	}
	if(gs>=2){
		dp[w]=sum-max1-max2-1;
	}
	return sum;
}

int main(){
	int T;
	int tc=1;
	int i,j;
	int s,e;
	int mini=-1;

	scanf("%d",&T);
	for(;T>0;T--){
		if(T==1)
			int sp=1;
		mini=-1;
		scanf("%d",&n);
		for(i=0;i<n-1;i++){
			scanf("%d%d",&s,&e);
			s--;
			e--;
			edge[e].push_back(s);
			edge[s].push_back(e);
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				is_gone[j]=0;
				dp[j]=0;
			}
			dfs(i);
			if(mini==-1||mini>dp[i])
				mini=dp[i];
		}
		printf("Case #%d: %d\n",tc++,mini);
		for(i=0;i<n;i++){
			edge[i].clear();
		}
	}
	return 0;
}