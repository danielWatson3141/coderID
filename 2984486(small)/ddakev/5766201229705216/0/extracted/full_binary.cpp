#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
long long t,n,x,y;
vector<int> z[1001];
int count_nodes(int x, int par)
{
    int ans=0;
    int m=z[x].size();
    for(int i=0; i<=m-1; i++)
    {
        if(z[x][i]!=par)
            ans+=count_nodes(z[x][i],x);
    }
    return ans+1;
}
int dfs(int x, int par)
{
    if(z[x].size()==1) return 0;
    else if(z[x].size()==2&&par!=0)
    {
        return count_nodes(x,par)-1;
    }
    int min1=0, min2=0, m=z[x].size();
    int minpos1=0, minpos2=0;
    for(int i=0; i<=m-1; i++)
    {
        if(z[x][i]!=par)
        {
            int k=count_nodes(z[x][i],x)-dfs(z[x][i],x);
            if(min1<k) {min2=min1; min1=k; minpos2=minpos1; minpos1=i;}
            else if(min2<k) {min2=k; minpos2=i;}
        }
    }
    int sum=count_nodes(x,par)-1;
    //cout<<x<<" "<<min1<<" "<<min2<<" "<<sum<<endl;
    return sum-min1-min2;
}
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&t);
	for(int o=1; o<=t; o++)
	{
		printf("Case #%d: ",o);
		scanf("%lld",&n);
		for(int i=1; i<=n; i++) z[i].clear();
		for(int i=1; i<=n-1; i++)
        {
            scanf("%lld%lld",&x,&y);
            z[x].push_back(y);
            z[y].push_back(x);
        }
        int min1=n-1;
        for(int i=1; i<=n; i++)
        {
            if(z[i].size()!=1) min1=min(min1,dfs(i,0));
        }
        printf("%d",min1);
		printf("\n");
	}
	return 0;
}
