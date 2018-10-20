#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define INF 1000000000
#define X first
#define Y second
#define mp make_pair

int now=1;
int C;
int tmp[50];
int idxt;
//---------------------------
char s1[155][45],s2[155][45];
struct node
{
	int a[45];
	int idx;
}p;
int b[45];
vector<node> v[155][45];

struct xxx
{
	//int u;
	bool leaf;
	bool chk[155];
}T[100005];
vector<int> E[100005];
map<pair<int,int>,int> M;

void dfs(int cur,int idx,int L)
{
	if(idx==L)
	{ 
		//printf("-%d--%d\n",cur,C);
		T[cur].chk[C]=true;
		T[cur].leaf=true;
		return;
	}
	
	int nxt=tmp[idx];
	//printf("---%d\n",nxt);
	if(M[mp(cur,nxt)]==0)
	{
		//T[now].u=nxt;

		E[cur].push_back(now);
		M[mp(cur,nxt)]=E[cur].size()-1;
		
		now++;
		dfs(E[cur][M[mp(cur,nxt)]],idx+1,L);
	}
	else dfs(E[cur][M[mp(cur,nxt)]],idx+1,L);
	return;
}
main()
{
 	freopen("A-small-attempt0.in","r",stdin);
	freopen("xxx.out","w",stdout);
	int n,l;
	int t;
	int i,j,k,m;
	int tcase_=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&l);
		for(i=0;i<n;i++) scanf("%s",s1[i]);
		for(i=0;i<n;i++) scanf("%s",s2[i]);
		
		for(i=0;i<n;i++)
			for(j=0;j<=l;j++)
				v[i][j].clear();
				
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				int cnt=0;
				memset(b,0,sizeof b);
				for(k=0;k<l;k++)
				{
					if(s1[i][k]!=s2[j][k]){ cnt++; b[k]=1; } 
				}
				//printf("%d %d | %d\n",i,j,cnt);
				for(k=0;k<l;k++)
				{
					p.a[k]=b[k];
				}
				p.idx=j;
				v[i][cnt].push_back(p);
			}
		}
		for(i=0;i<=l;i++)
		{
			M.clear();
			for(j=0;j<now;j++) 
			{
				T[j].leaf=false;
				for(k=0;k<n;k++) T[j].chk[k]=false;
			}
			now=1;
			
			//printf("#### %d ####\n",i);
			for(j=0;j<n;j++)
			{
				for(k=0;k<v[j][i].size();k++)
				{
					//v[j][i][k].a[]
					//v[j][i][k].idx
					idxt=0;
					for(m=0;m<l;m++)
					{
						if(v[j][i][k].a[m]==1) tmp[idxt++]=m;
					}
					C=v[j][i][k].idx;
					dfs(0,0,idxt);
				}
			}
			
			bool yes=0;
			for(j=0;j<now;j++)
			{
				if(T[j].leaf==true)
				{
					//printf("J %d\n",j);
					yes=0;
					for(k=0;k<n;k++)
					{
						//printf("%d ",T[j].chk[k]);
						if(T[j].chk[k]==0) 
						{
							//printf("K %d\n",k);
							break;
						}
					}
					//printf("\n");
					if(k==n) yes=1;
					//printf("%d\n",yes);
				}
				if(yes) break;
			}
			if(yes) break;
		}
		if(i==l+1) printf("Case #%d: NOT POSSIBLE\n",tcase_++);
		else printf("Case #%d: %d\n",tcase_++,i);
	}
}

