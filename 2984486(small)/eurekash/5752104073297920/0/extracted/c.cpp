#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<utility>
#include<random>
using namespace std;
typedef pair<int,int> pii;
const int maxt=120;
pii p[maxt+1];
int t,n,a[1000];
bool b[maxt];
mt19937 rnd(time(0));
uniform_int_distribution<int> d(0,999);

int main()
{
	scanf("%d",&t);
	int c2=0;
	for(int t1=1;t1<=t;t1++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",a+i);
		int cnt=0;
		for(int i=0;i<n;i++)
			if(a[i]>i) ++cnt;
			else --cnt;
		if(cnt>30)  printf("Case #%d: BAD\n",t1);
		else  printf("Case #%d: GOOD\n",t1),++c2;
	}
	return 0;
}
