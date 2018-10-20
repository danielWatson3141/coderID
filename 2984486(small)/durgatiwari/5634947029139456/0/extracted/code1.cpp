#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

/*typedef long long int64;
typedef unsigned long long uint64;*/
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
/*template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}*/
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ll long long int
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define nl printf("\n")
#define pl(x) printf("%lld",x)

int main()
{
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char a[50][50],w[50][50],arr[50][50];
	int loc[50],r;
	string ww="";
	int T,n,L;
	si(T);
	for(int t=1;t<=T;t++)
	{
		map<string,int> mp;
		r=100000;
		si(n);
		si(L);
		for(int i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",w[i]);
			ww=w[i];
			mp[ww]=1;
		}
		printf("Case #%d: ",t);
		int l=two(L);
		for(int set=0;set<l;set++)
		{
			int c=0;
			memset(loc,0,sizeof(loc));
			for(int i=0;i<L;i++)
			{
				if(contain(set,i))
				{
					loc[i]++;
					c++;
				}
			}
			for(int i=0;i<n;i++)
			{
				sscanf(a[i],"%s ",arr[i]);
			}
			
			for(int j=0;j<L;j++)
			{
				if(loc[j]==1)
				{
					for(int i=0;i<n;i++)
					{
						arr[i][j]=='0'?arr[i][j]='1':arr[i][j]='0';
					}
				}
			}
			int f=0;
			for(int i=0;i<n;i++)
			{
				ww=arr[i];
				if(mp[ww]!=1)
				{
					f=1;break;
				}
			}
			if(f==0)
			{
				r=min(r,c);
			}
		}
		if(r<100000)printf("%d\n",r);
		else printf("NOT POSSIBLE\n");
	}
}
