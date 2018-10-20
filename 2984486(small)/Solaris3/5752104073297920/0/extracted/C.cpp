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
typedef long double D;
const int MAXN = 1004;
vector<vector<D> >P,T;
int n;
void init()
{
	fru(i,n)P[i][i]=1.0;
	fru(h,n)
	{
		fru(i,n)
		{
			fru(j,n)
			{
				T[i][j]=0.0;
				if(i==h)
				{
					T[i][j]=1./n;
				}
				else
				{
					T[i][j]=1.*(n-1)/n*P[i][j];
					T[i][j]+=1./n*P[h][j];
				}
			}
		}
		swap(T,P);
	//fru(ii,n){fru(jj,n)printf("%.2lf ",P[ii][jj]);printf("\n");}
	}
}
void solve()
{
	int a;
	scanf("%d",&n);
	D pr=0.;
	fru(i,n)
	{
		scanf("%d",&a);
		pr+=P[i][a];
	}
	if(pr>1.)printf("BAD\n");
	else printf("GOOD\n");
}
int main()
{
	n=1000;
	P.resize(n);
	fru(i,n)P[i].resize(n);
	T.resize(n);
	fru(i,n)T[i].resize(n);
	init();
//	fru(i,n){fru(j,n)printf("%.6lf ",P[i][j]);printf("\n");}
	int t;
	scanf("%d",&t);
	fru(i,t){printf("Case #%d: ",i+1);solve();}

    return 0;
}
