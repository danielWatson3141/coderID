#include<iostream>
#define MAXN 151
#define MAXL 41
using namespace std;
int a[2][MAXN][MAXL],N,L,ans;
bool flag;
void sort(int k,int i,int j,int c)
{
	int p=i,q=j,y,temp,x=a[k][(p+q)/2][c];
	while (p<=q)
	{
		while (a[k][p][c]<x) p++;
		while (a[k][q][c]>x) q--;
		if (p<=q)
		{
			for (y=0;y<L;y++)
			{
				temp=a[k][p][y];
				a[k][p][y]=a[k][q][y];
				a[k][q][y]=temp;
			}
			p++;
			q--;
		}
	}
	if (p<j) sort(k,p,j,c);
	if (i<q) sort(k,i,q,c);
}
bool check(int x,int y,int k)
{
	if (k<0) return true;
	for (int i=0;i<=k;i++)
		if (a[1][x][i]!=a[1][y][i]) return false;
	return true;
}
void manage(int k,int can,int cnt)
{
	if (k>=L)
	{
		if (cnt<ans) ans=cnt;
		return;
	}
	int i,j=0,p,q,temp;
	for (i=1;i<=N;i++)
	{
		if (i==N||check(i,i-1,k-1)==false)
		{
			sort(0,j,i-1,k);
			sort(1,j,i-1,k);
			if (can==1)
			{
				for (p=j;p<=i-1;p++)
				{
					if (i-1-(p-j)<=p) break;
					for (q=0;q<L;q++)
					{
						temp=a[1][p][q];
						a[1][p][q]=a[1][i-1-(p-j)][q];
						a[1][i-1-(p-j)][q]=temp;
					}
				}
			}
			for (p=j;p<=i-1;p++)
				if (a[0][p][k]!=((a[1][p][k]+can)%2)) return;
			j=i;
		}
	}
	manage(k+1,0,cnt+can);
	manage(k+1,1,cnt+can);
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int i,j,k,T;
	char ch;
	cin>>T;
	for (int k=0;k<T;k++)
	{
		cin>>N>>L;
		for (i=0;i<N;i++)
			for (j=0;j<L;j++)
			{
				cin>>ch;
				a[0][i][j]=ch-'0';
			}
		for (i=0;i<N;i++)
			for (j=0;j<L;j++)
			{
				cin>>ch;
				a[1][i][j]=ch-'0';
			}
		ans=L+1;
		manage(0,0,0);
		manage(0,1,0);
		cout<<"Case #"<<k+1<<": ";
		if (ans<L+1) cout<<ans<<endl;
		else cout<<"NOT POSSIBLE"<<endl;
	}
	return 0;
}