#include <cstdio>
#include <algorithm>
#include <vector>
#include<iostream>
#include<map>
#define fru(j,n) for(int j=0;j<n;++j)
#define tr(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
const int MAXN = 153;
map<vector<int>,int> M;
vector<int> V[MAXN],T[MAXN];
int n,k;
char c;
vector<int> Z;
int change(int a)
{
	Z.resize(k);
	int ile=0;
	fru(i,k){Z[i]=V[a][i]^T[0][i];ile+=Z[i];}
	bool ok=true;
	fru(i,n)
	{
		fru(j,k)if(Z[j])V[i][j]=1-V[i][j];
		if(M[V[i]]==0)ok=false;
		fru(j,k)if(Z[j])V[i][j]=1-V[i][j];
	}
	if(!ok)return 200;
	return ile;
}
void solve()
{
	scanf("%d%d",&n,&k);
	M.clear();
	fru(i,n)V[i].clear();
	fru(i,n)T[i].clear();
	fru(i,n)
		fru(j,k)
		{
			scanf(" %c",&c);
			V[i].push_back(c-'0');
		}
	fru(i,n)
		fru(j,k)
		{
			scanf(" %c",&c);
			T[i].push_back(c-'0');
		}
	fru(i,n)M[T[i]]=1;
	if(0)fru(i,n)
	{
		fru(j,k)printf("%d",V[i][j]);printf("\n");
	}
	if(0)fru(i,n)
	{
		fru(j,k)printf("%d",T[i][j]);printf("\n");
	}
	int wyn=200;
	fru(i,n)
	{
	//	printf("%d ",i);
		wyn=min(change(i),wyn);
	}
//	printf("wyn %d\n",wyn);
	if(0)fru(i,n)
	{
		fru(j,k)printf("%d",V[i][j]);printf("\n");
	}
	vector<vector<int> > S;
	fru(i,n)S.push_back(V[i]);
	sort(S.begin(),S.end());
	int num=unique(S.begin(),S.end())-S.begin();
	if(num!=n)wyn=200;
	S.clear();
	if(wyn==200)printf("NOT POSSIBLE\n");
	else printf("%d\n",wyn);

}
int main()
{
	int t;
	scanf("%d",&t);
	fru(i,t){printf("Case #%d: ",i+1);solve();}

    return 0;
}
