#include<stdio.h>
#include<vector>
using namespace std;

FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");

int n;
bool visited[1020];
int dy[1020];
vector<int>da[1020];

void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
}

int dfs(int w)
{
	int i,k;
	int hap=1;
	int max1=-1;
	int max2=-1;
	int t2;
	int sunnumber=0;

	visited[w]=1;

	for(i=0;i<da[w].size();i++)
	{
		if(visited[da[w][i]]==0)
		{
			sunnumber++;

			k=dfs(da[w][i]);
			t2=k-dy[da[w][i]];

			if(max2==-1 || max2<t2)
				max2=t2;
			if(max1==-1 || max1<max2)
				swap(max1,max2);

			hap+=k;
		}
	}

	if(sunnumber==0)
		dy[w]=0;
	if(sunnumber==1)
		dy[w]=hap-1;
	if(sunnumber>=2)
		dy[w]=hap-max1-max2-1;

	return hap;
}

int main()
{
	int case_n;
	int tc=1;
	int i,j;
	int s,e;
	int mini=-1;

	fscanf(in,"%d",&case_n);

	for(;case_n>0;case_n--)
	{
		if(case_n==1)
			int sp=1;

		mini=-1;

		fscanf(in,"%d",&n);

		for(i=0;i<n-1;i++)
		{
			fscanf(in,"%d%d",&s,&e);
			s--;
			e--;
			da[e].push_back(s);
			da[s].push_back(e);
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				dy[j]=0;
				visited[j]=0;
			}

			dfs(i);

			if(mini==-1 || mini>dy[i])
				mini=dy[i];
		}

		fprintf(out,"Case #%d: %d\n",tc++,mini);

		for(i=0;i<n;i++)
			da[i].clear();
	}
	return 0;
}