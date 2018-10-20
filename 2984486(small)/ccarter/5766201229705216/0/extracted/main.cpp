#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <strstream>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define FOR0(i,n) for(i=0;i<(n);++i)
#define FOR1(i,n) for(i=1;i<=(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define DEBUG(x) cout << #x << "=" << x << endl
#define CLR(x) memset((x),0,sizeof((x)))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

void RD(int &x){scanf("%d",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char *s){scanf("%s",s);}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(double x) {printf("%.6lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char x[]) {printf("%s\n",x);}
void PRI(char x[]) {printf("%s",x);}
vector<int> tree[1001];
int treesize(int fa,int root)
{
	int sum=0;
	sum+=1;
	int i;
	FOR0(i,tree[root].size())
	{
		if (tree[root][i]==fa)
			continue;
		else
		{
			sum+=treesize(root,tree[root][i]);
		}
	}
	return sum;

}
int calc(int fa,int root)
{
	int mi=10000;
	int arr[1000];
	if (fa!=-1)
	{
		int i;
		if (tree[root].size()==1)
		{
			return 0;
		}
		else if (tree[root].size()==2)
		{
			int next=tree[root][0]+tree[root][1]-fa;
			return treesize(root,next);
		}
		else if (tree[root].size()==3)
		{
			int sum=0;
			FOR0(i,3)
			{
				if (tree[root][i]==fa)
					continue;
				sum+=calc(root,tree[root][i]);
			}
			return sum;
		}
		else
		{
			int sum=0;
			int arr[1000],top=0;
			FOR0(i,tree[root].size())
			{
				if (tree[root][i]==fa)
					continue;
				int a=calc(root,tree[root][i]);
				int b=treesize(root,tree[root][i]);
				sum+=a;
				arr[top++]=b-a;
			}
			sort(arr,arr+top);
			FOR0(i,top-2)
				sum+=arr[i];
			return sum;
		}

	}
	else
	{
		int i;
		if (tree[root].size()==0)
		{
			return 0;
		}
		else if (tree[root].size()==1)
		{

			return treesize(root,tree[root][0]);
		}
		else if (tree[root].size()==2)
		{
			int sum=0;
			FOR0(i,2)
			{
				sum+=calc(root,tree[root][i]);
			}
			return sum;
		}
		else
		{
			int sum=0;
			int arr[1000],top=0;
			FOR0(i,tree[root].size())
			{
				if (tree[root][i]==fa)
					continue;
				int a=calc(root,tree[root][i]);
				int b=treesize(root,tree[root][i]);
				sum+=a;
				arr[top++]=b-a;
			}
			sort(arr,arr+top);
			FOR0(i,top-2)
				sum+=arr[i];
			return sum;
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc;
	int tt,n;
	RD(tt);
	FOR1(tc,tt)
	{
		RD(n);
		int i;
		FOR0(i,1001)
			tree[i].clear();

		FOR0(i,n-1)
		{
			int x,y;
			RD(x,y);
			tree[x].PB(y);
			tree[y].PB(x);
		}
		printf("Case #%d: ",tc);
		int mi=10000;
		FOR1(i,n)
		{
			int a;
			//n as root
			if ((a=calc(-1,i))<mi) mi=a;
		}
		PR(mi);
	}
	return 0;
}
