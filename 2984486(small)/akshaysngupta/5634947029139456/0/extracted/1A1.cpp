//includes
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

//typedefs
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

//defines-general
#define to(a) __typeof(a)
#define all(vec)  vec.begin(),vec.end()
#define fill(a,val)  memset(a,val,sizeof(a))

//defines-iteration
#define repi(i,a,b) for(__typeof(b) i = a;i<b;i++)
#define repii(i,a,b) for(__typeof(b) i = a;i<=b;i++)
#define repr(i,b,a) for(__typeof(b) i = b;i>a;i--)
#define repri(i,b,a) for(__typeof(b) i = b;i>=a;i--)
#define tr(vec,it)  for(__typeof(vec.begin())  it = vec.begin();it!=vec.end();++it)

//defines-pair
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

string R[200];
string P[200];
vector<int> f;
int n,l,countflip=0,oneR,oneP;
bool flag;

string tP[200];

void strcopy()
{
	repi(i,0,n)
		tP[i]=P[i];
}

int power(int n,int r)
{
	if(r==0)	return 1;
	if(r==1)	return n;
	int temp;
	if(r%2==0){
		temp = power(n,r/2);
		return (temp*temp);
	}
	else{
		temp = power(n,(r-1)/2);
		return ((temp*temp)*n);
	}
}

void init()
{
	f.clear();
	flag = false;
	countflip=0;
}

int countone(string *A,int idx)
{
	int count_=0;
	for(int i=0;i<n;i++)
	{
		if(A[i][idx]=='1')
		count_++;
	}
	return count_;
}

void flipbit(int idx)
{
	repi(i,0,n)
	{
		if(P[i][idx]=='1')
			P[i][idx]='0';
		else
			P[i][idx]='1';
	}
}

void fliptbit(int idx)
{
	repi(i,0,n)
	{
		if(tP[i][idx]=='1')
			tP[i][idx]='0';
		else
			tP[i][idx]='1';
	}
}

bool check(string *A,string *B)
{
	sort(A,A+n);
	sort(B,B+n);
	repi(i,0,n)
	{
		//cout << A[i] << " " << B[i] << endl;
		if(A[i]!=B[i])
		{
			//cout << "f" << i << endl;
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w+",stdout);
	int test,t;
	cin >> test;
	t=test;
	while(test--)
	{
		init();
	cin >> n >> l;
	repi(i,0,n)
	cin >> P[i];
	repi(i,0,n)
	cin >> R[i];

	repi(i,0,l)
	{
		oneR=countone(R,i);
		oneP=countone(P,i);
		if(oneR==oneP)
		{
			if(oneR==n-oneP)
				f.push_back(i);
			continue;
		}
		else if(oneR==n-oneP)
		{
			flipbit(i);
			countflip++;
		}
		else
		{
			flag=true;
			break;
		}
	}

	int ways = power(2,f.size()),count_=0,temp,countft=0;

	repi(i,0,ways)
	{
		strcopy();
		temp = i;
		count_=countft=0;
		while(temp>0)
		{
			if(temp&1)
			{
				fliptbit(f[count_]);
				countft++;
				//cout << f[count_] << endl;
			}
			temp>>=1;
			count_++;
		}
		if(check(tP,R))
		{
			//cout << i << " " << countft << endl;
			countflip += countft;
			flag=false;
			break;
		}
		flag=true;
	}

	printf("Case #%d: ",t-test);
	if(flag==true)
		printf("NOT POSSIBLE\n");
	else
		printf("%d\n",countflip);
	}
	return 0;
}