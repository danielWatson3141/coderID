#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<int> i[1000];
int b[1000][3];
int dfs(int x,int z)
{
	int mx1=-1,mx2=-1;
	for(int a=0;a<i[x].size();a++)
	{
		int y=i[x][a];
		if( y==z ) continue;
		int t=dfs(y,x);
		if( t>mx1 ){ mx2=mx1; mx1=t; }
		else if( t>mx2 ){ mx2=t; }
	}
//printf("%d %d %d\n",x,mx1,mx2);
	if( mx2==-1 ) return 1;
	return mx1+mx2+1;
}
/*void dfs(int x,int z)
{
	for(int a=0;a<i[x].size();a++)
	{
		int y=i[x][a];
		if( y==z ) continue;
		dfs(y,x);
		if( b[y][0]==-1 ) t=0;
		else if( b[y][1]==-1 ) continue;
		else t=min(b[y][0],b[y][1])+1;
		
	}
}*/
int main()
{
int N;
scanf("%d",&N);
for(int T=1;T<=N;T++)
{
	int n;
	scanf("%d",&n);
	for(int a=0;a<n;a++) i[a].clear();
	for(int a=0;a<n-1;a++)
	{
		int x,y;
		scanf("%d%d",&x,&y); x--; y--;
		i[x].push_back(y);
		i[y].push_back(x);
	}
	for(int a=0;a<n;a++) for(int s=0;s<3;s++) b[a][s]=-1;
	printf("Case #%d: ",T);
//printf("\n");
	int o=-1;
	for(int a=0;a<n;a++)
	{
		int t=dfs(a,a);
//		printf("----- %d %d\n",a,t);
		if( t>o ) o=t;
	}
	printf("%d",n-o);
done:;
	printf("\n");
}
	return 0;
}
