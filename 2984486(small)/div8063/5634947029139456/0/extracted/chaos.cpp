#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>
 
#define X first
#define Y second
#define gc getchar_unlocked
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()
 
#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527
#define MOD7 10000007
#define MOD9 1000000009
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;
 
template<class T>
T Mul(T x,T y,T P){
T F1=0;
while(y)
{
if(y&1)
{
F1+=x;
if(F1<0||F1>=P)F1-=P;
}
x<<=1;
if(x<0||x>=P)x-=P;
y>>=1;
}
return F1;
}
 
template<class T>
T Pow(T x,T y,T P){
T F1=1;x%=P;
while(y)
{
if(y&1)
{
F1=Mul(F1,x,P);
}
x=Mul(x,x,P);
y>>=1;
}
return F1;
}

template<class T>
T Swap(T &x,T &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
 
template<class T>
T Gcd(T x,T y){
if(y==0)return x;
T z;
while(z=x%y){
x=y,y=z;
}
return y;
}

template<class T>
T Abs(const T x){
return x<0?-x:x;
}

LL inline inp() {
    register LL N = 0, C;
    while ((C = gc()) < '0');
    do {
    N = (N<<3) + (N<<1) + C - '0';
    }while ((C = gc()) >= '0');
    return N;
    }
/*------------------------------------------------------------------------------------------------------------------------------------------*/
map<string,int>my;
LL n,l;
int chk(string s[],LL i)
{
	string s2;
	//REP(k,n)
		//cout<<s[k]<<" ";
	//cout<<endl;
	//cout<<i<<"---"<<endl;
	LL j,k;
	for(j=0;j<n;j++)
	{
		//cout<<s[j]<<endl;
		s2=s[j];
		for(k=0;k<l;k++)
			if(i&(1<<k))
			{
				s2[l-k-1]=s2[l-k-1]=='1'?'0':'1';
				//cout<<"en"<<endl;
			}
		//cout<<s[j]<<endl;
		if(my.count(s2)==1)
			;
		else
			return 0;
	}
	return 1;
}		
int main()
{
	LL i,j,tmp,t;
	int b[1000],cnt,f,min;
	char c;
	t=inp();
	for(j=1;j<=t;j++)
	{
		printf("Case #%lld: ",j);
		n=inp();
		scanf("%lld",&l);
		getchar();
		tmp=n;
		string s[n],s2;
		i=0;
		while(tmp--)
		{
			while(c=getchar())
			{
				if(c==' '||c=='\n') break;
				//cout<<c<<endl;
				s[i]+=c;
			}
			i++;
			//cout<<i<<endl;
		}
		tmp=n;
		i=0;
		while(tmp--)
		{
			while(c=getchar())
			{
				if(c==' '||c=='\n') break;
				s2+=c;
			}
			my[s2]=1;
			s2="";
		}
		f=0;min=10000;
		for(i=0;i<(1<<l);i++)
		{
			if(chk(s,i))
			{
				for(tmp=0,cnt=0;tmp<l;tmp++)
					if(i&(1<<tmp))
						cnt++;
				if(cnt<min)
					min=cnt;		
			}
		}
		//cout<<n<<"---"<<l<<endl;
		if(min!=10000)
		{
			printf("%d\n",min);
		}
		else
		{
			printf("NOT POSSIBLE\n");
		}
		my.clear();
	}
	return 0;
}
