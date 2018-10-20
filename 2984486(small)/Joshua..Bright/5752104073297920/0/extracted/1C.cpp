#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
const int lim=100000;
using namespace std;
int a[lim+2][1005],n,b[200000];
int randint(int l,int r)
{
	if (l==r) return l;
	return l+rand()%(r-l);
}
void RanA(int n,int a[1005])
{
	for (int k=0;k<=n-1;k++) a[k]=k;
	for (int k=0;k<=n-1;k++) {
		int p=randint(k,n);
		swap(a[k],a[p]);
	}
}
void RanB(int n,int a[1005])
{
	for (int k=0;k<=n-1;k++) a[k]=k;
	for (int k=0;k<=n-1;k++) {
		int p=randint(0,n);
		swap(a[k],a[p]);
	}
}
int main()
{
	freopen("1input.txt","r",stdin);
	freopen("1output.txt","w",stdout);
	srand((int)time(NULL));
	int T;
	cin>>T;
	for (int Case=1;T;T--,Case++) {
		printf("Case #%d: ",Case);
		scanf("%d",&n);
		for (int i=0;i<=n-1;i++) scanf("%d",&b[i]);
		int sum=0;
		for (int i=0;i<=n-1;i++) {
			sum+=(b[i]-i>10);
		}
		//cout<<sum<<endl;
		if (sum<n/2) {
			printf("GOOD\n");
		}
		else printf("BAD\n");
	}
	return 0;
}
