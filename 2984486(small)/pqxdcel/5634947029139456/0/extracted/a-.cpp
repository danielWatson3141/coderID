// powered by xpd1  /i love shimokawa_mikuni and i haven't touch my devc for 3 months. 
// All of these left only broken history after 12.4.22. sacrifice for my  love.
// on 2012-10-
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <ctype.h>
#include <memory>
#include <fstream>
#include <string>
#include <utility>
#include <iomanip>
#define oo 2000000000
#define ol 200000000000000000ll
#define md 1000000007 
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <set>
//#include <conio.h>
#define oo 2000000000
#define ol 200000000000000000ll //=2E17
#define ooo 1E14
#define EPS 1E-10
#define mp make_pair
#define pb push_back
#define eps EPS
#define mem(x,y) (memset((x),y,sizeof((x))))
#define debug(x) cout << #x<<" = "<<x<<endl;
#ifdef __int64
 #define fmt64 "%I64d"
#else 
 #define fmt64 "%lld"
#endif
#define fi first
#define se second
using namespace std;
using namespace rel_ops;
const double PI=acos((double)-1);
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
int ts,ts2,ts3,ts4;
int n,m,L;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
char ss[100];
void trans(char *a, int *b)
{
	for(int i =1 ;i<=L;i++)b[i]=a[i]-48;
}
string st[200],en[200];
bool cmp1(const string &a,const string &b)
{
	 return a<b;
}
string tp[200];
int ans;
int main()
{
  int i,j,k,l,t1,t2,t3,t4,t5,t6,t7,t8,t9,t,nw;
  int tt1,tt2,tt3,tt4;
  double u1,u2,u3,u4,u5,u6,u7,u8,u9;
  char c1,c2,c3;
  srand((unsigned)time(0));//srand(72888306);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  #endif
  int T,T2;
  cin>>T;
  for(T2=1;T2<=T;T2++)
  {
  	ans=oo;
  	cin>>n>>L;
  	for(i=1;i<=n;i++)
  	 scanf("%s",ss),st[i]=ss;
  	for(i=1;i<=n;i++)
  	 scanf("%s",ss),en[i]=ss;
  	sort(en+1,en+n+1,cmp1);
  	for(i=1;i<=n;i++)
  	{
  		int nwa=0;
  		for(k=0;k<L;k++)
				  if (en[1][k]!=st[i][k])nwa++;
				if (nwa>=ans)continue;
  	 nw=0;
  		for(j=1;j<=n;j++)
  		{
  			if (j==i)continue;else nw++;
  			tp[nw]=st[j];
				 for(k=0;k<L;k++)
				  if (en[1][k]!=st[i][k])
				   tp[nw][k]=(tp[nw][k]=='1'?'0':'1');
  		}
  		sort(tp+1,tp+nw+1,cmp1);
  		nw=0;
				for(j=1;j<n;j++)
  		{
  			if (en[j+1]!=tp[j])break;
  		}
  		if (j>=n)
  		 ans=nwa;
  	}
  	printf("Case #%d: ",T2);
  	if (ans>=oo)
  	 printf("NOT POSSIBLE\n");
  	 else cout <<ans<<endl;
  }
  return 0;
}
