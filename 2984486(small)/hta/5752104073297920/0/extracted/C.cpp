#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
inline int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
typedef long long LL;
const int maxn=1003;
int T,n,a[maxn];
double p[maxn];
int main()
{
	freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int T=get();n=1000;
    for(int i=0;i<n;i++)p[i]=n-i;
    for(int t=1;t<=T;t++)
    {
		printf("Case #%d: ",t);
		n=get();
		for(int i=0;i<n;i++)a[i]=get();
		double tp=0;
		for(int i=0;i<n;i++)tp+=pow(a[i]*p[i],0.666666666);
		//printf("%.10lf\n",tp);
		if(tp<3575000)puts("GOOD");else puts("BAD");
	}
    return 0;
}
