#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<cstring>
#include<climits>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#define LL long long
using namespace std;
int cnt,snt,n,L,m,times;
int a[1010],b[1010];
int data1[1000010],data2[1000010];
double pi=3.1415926535897;
void produce1()
{
	for (int i=0;i<n;i++) a[i]=i;
	for (int i=0;i<n;i++)
	{
		int p=rand()%(n-i)+i;
		swap(a[i],a[p]);
	}
}
void produce2()
{
	for (int i=0;i<n;i++) a[i]=i;
	for (int i=0;i<n;i++)
	{
		int p=rand()%n;
		swap(a[i],a[p]);
	}
}
void prepare()
{
	srand(time(NULL));
	memset(data1,0,sizeof(data1));
	memset(data2,0,sizeof(data2));
	m=1000000;
	for (int k=1;k<=m;k++)
	{
		produce1();
		int t=0;
		for (int i=0;i<n;i++) t+=abs(a[i]-i);
		data1[t]++;
	}
	for (int k=1;k<=m;k++)
	{
		produce2();
		int t=0;
		for (int i=0;i<n;i++) t+=abs(a[i]-i);
		data2[t]++;
	}
}
void work(int lab)
{
	printf("Case #%d: ",lab);
	if (lab!=1) scanf("%d",&n);
	int symbol=0;
	for (int i=0;i<n;i++) scanf("%d",&b[i]),symbol+=abs(b[i]-i);
	if (data1[symbol]>data2[symbol]) printf("GOOD\n");
	else printf("BAD\n");
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&times);
	scanf("%d",&n);
	prepare();
	for (int i=1;i<=times;i++)
	work(i);
	return 0;
}
