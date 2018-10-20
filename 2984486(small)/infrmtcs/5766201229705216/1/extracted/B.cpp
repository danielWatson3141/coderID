#include <bits/stdc++.h>
#define fi "B.INP"
#define fo "B.OUT"
#define nmax 1000+5
#define INF 1000000000
using namespace std;
typedef vector<int> VI;
//VARIABLES
int n,test,b[nmax],d[nmax],turn,check[nmax],res;
VI c[nmax];
//PROTOTYPES

void Process();

//MAIN
int main()
{
	int tc;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       scanf("%d",&tc);
       while (tc--)
	{
		Process();
		fprintf(stderr,"%d\n",test);
	}
       return 0;
}

//FUNCTIONS
void DFS(int i)
{
	int x=-1,y=-1;
	check[i]=turn;
	b[i]=1;
	for (VI::iterator it=c[i].begin();it!=c[i].end();++it)
	if (check[*it]!=turn)
	{
		DFS(*it);
		b[i]+=b[*it];
		if (x<b[*it]-d[*it])
		{
			y=x;
			x=b[*it]-d[*it];
		} else
		if (y<b[*it]-d[*it]) y=b[*it]-d[*it];
	}
	d[i]=b[i]-1;
	if ((x!=-1) && (y!=-1)) d[i]=d[i]-x-y;
}
void Process()
{
	int p,q;
	scanf("%d",&n);
	for (int i=1;i<=n;++i) c[i].clear();
	for (int i=1;i<n;++i)
	{
		scanf("%d%d",&p,&q);
		c[p].push_back(q);
		c[q].push_back(p);
	}
	res=INF;
	for (int root=1;root<=n;++root)
	{
		++turn;
		DFS(root);
		res=min(res,d[root]);
	}
	printf("Case #%d: %d\n",++test,res);
}
