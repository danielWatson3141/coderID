#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010],n;
double val[1010],p[1010],vals[1010];
double abs(double x)
{
 	if(x>0)return x;
 	return -x;
}
double check()
{
 	int i;
	 double ret1=0,ret2=0;
 	 for(i=0;i<300;++i)
 	 {
 	 ret2+=abs(a[i]-i)*abs(a[i]-i)*(a[i]-i);
 	 
	 }
	 for(i=0;i<300;++i)
 	 {
 	 ret1+=abs(a[i]-i)*abs(a[i]-i)*(i-a[i]);
 	 
	 }
 	 return abs(ret2-ret1);
}
int main()
{
 	//freopen("good.in","r",stdin);
 	//freopen("bad.in","r",stdin);
 	freopen("c.in","r",stdin);
 	freopen("c.out","w",stdout);
 	int t,tt,i;
 	scanf("%d",&tt);
 	for(t=1;t<=tt;++t)
 	{
  	     scanf("%d",&n);
  	     for(i=0;i<n;++i)
  	     scanf("%d",a+i);
  	     if(check()<75000.0*1e6)
  	     printf("Case #%d: BAD\n",t);
  	     else
  	     printf("Case #%d: GOOD\n",t);
  	}
 	return 0;
}
