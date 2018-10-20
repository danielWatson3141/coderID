#include<iostream>
#define MAXN 1000
using namespace std;
int edge[MAXN][2],del[MAXN],num[MAXN],N;
bool used[MAXN];
void buildtree(int root)
{
	int child[MAXN][2];
	used[root]=false;
	del[root]=0;
	num[root]=1;
	int cnt=0,i;
	for (i=0;i<N-1;i++)
	{
		if (edge[i][1]==root)
		{
			edge[i][1]=edge[i][0];
			edge[i][0]=root;
		}
		if (edge[i][0]==root&&used[edge[i][1]])
		{
			child[cnt][0]=edge[i][1];
			buildtree(edge[i][1]);
			del[root]+=del[child[cnt][0]];
			num[root]+=num[child[cnt][0]];
			child[cnt++][1]=num[child[cnt][0]]-del[child[cnt][0]];
		}
	}
	if (cnt==1)
	{
		del[root]+=child[0][1];
	}
	if (cnt>2)
	{
		int max1=0,max2=1,sum=0;
		for (i=2;i<cnt;i++)
			if (child[i][1]>child[max1][1])
			{
				max1=i;
				sum+=child[max1][1];
			}
			else
			{
				if (child[i][1]>child[max2][1])
				{
					max2=i;
					sum+=child[max2][1];
				}
				else sum+=child[i][1];
			}
		del[root]+=sum;
	}
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,k,i,j,ans;
	cin>>T;
	for (int k=0;k<T;k++)
	{
		cin>>N;
		for (i=0;i<N-1;i++)
		{
			cin>>edge[i][0]>>edge[i][1];
			edge[i][0]--;
			edge[i][1]--;
		}
		ans=N;
		for (i=0;i<N;i++)
		{
			for (j=0;j<N;j++) used[j]=true;
			buildtree(i);
			if (del[i]<ans) ans=del[i];
		}
		cout<<"Case #"<<k+1<<": "<<ans<<endl;
	}
	return 0;
}