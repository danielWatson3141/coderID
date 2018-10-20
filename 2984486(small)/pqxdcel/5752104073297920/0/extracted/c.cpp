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
int n,m;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
LL s[200];
int a[1005];
int ran[100005][1005];
int ans[150];
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
  FILE *fp;
  fp=fopen("data.txt","r");
  int T,T2;
  /*
  for(i=1;i<=100000;i++)
   for(j=1;j<=1000;j++)
			 fscanf(fp,"%d",&ran[i][j]);*/
			for(j=1;j<=1000;j++)
  	{
  		a[j]=j;
  		t1=rand()%j+1;
  		swap(a[j],a[t1]);
  	}
  cerr<<"finish~~part 1."<<endl;
		cin>>T;
		for(T2=1;T2<=T;T2++)
		{
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			 cin>>a[i];
			s[T2]=0;
			for(i=1;i<=100000;i++)
			 for(j=1;j<=1000;j++)
			  if (a[j]==ran[i][j])
			   s[T2]++;
   cerr<<T2<<' '<<s[T2]<<endl;
		}
		for(T2=1;T2<=T;T2++)
		 if (s[T2]>100799) ans[T2]=1;
		for(T2=1;T2<=T;T2++)
		{
			printf("Case #%d: ",T2);
			if (ans[T2]) printf("BAD\n");
			else 
			 printf("GOOD\n");
		}
  return 0;
}
