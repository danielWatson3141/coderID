#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <bitset>
using namespace std;
typedef long long lld;
typedef lld real;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
const double pi = 3.14159265358979323846;
real eps=1e-8;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
inline int rand(int a, int b) {if(a >= b) return a; return rand() % (b-a) + a;}//NOTES:rand(
//Numberic Functions
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
{vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
{if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T eularFunction(T n)//NOTES:eularFunction(
{vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
template<class T> inline int dblcmp(T a,const T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
template<class T> inline int sgn(T a){return a>eps?1:(a<-eps?-1:0);}
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define FOR(I,A,B)    for(int I = (A); I < (B); ++I)
#define REP(I,N)    FOR(I,0,N)
#define shl(i)      ((lld)1 << (i))

const int N = 1100;

struct node{
	int a[N];
	int n;
	node(){};
	node(int b[], int n):n(n){
		for (int i=0; i<n; ++i) a[i] = b[i];
	}
	bool operator<(const node &B) const{
		for (int i=0; i<n; ++i){
			if (a[i] != B.a[i]){
				return a[i] < B.a[i];
			}
		}
		return false;
	}
	void print() const{
		for (int i=0; i<n; ++i){
			printf("%d ", a[i]);
		}
		int c = 0;
		for (int i=0; i<n; ++i){
			if (a[i] == i) c ++;
		}
		printf("%d ", c);
	}
};

int a[N];
void wrong(int n){
	for (int i=0; i<n; ++i) a[i] = i;
	for (int i=0; i<n; ++i){
		int p = rand() % n;
		swap(a[i], a[p]);
	}
}

void print(double a){
	double r = rand() % 10000 / 10000.0;
	if (r > a) puts("BAD");
	else puts("GOOD");
}
int main(){
	srand(time(0));
	/*
	int cas;
	map<node, int> mp;
	int test = 10000000;
	int n = N;
	for (int i=0; i<test; ++i){
		wrong(n);
		mp[node(a, n)] ++;
	}
	int fac = 1;
	for (int i=1; i<=n; ++i) fac *= i;
	for (map<node, int>::iterator it=mp.begin(); it!=mp.end(); ++it){
		(it->first).print();
		double t = it->second * 1.0 / test - 1.0 / fac;
		printf("%d %lf\n", t>0? 1:0,  it->second * 1.0 / test);
	}
	return 0;
	*/
	int cas;
	cin >> cas;
	int t, n;
	int sum=0;
	for (int I=1; I<=cas; ++I){
		printf("Case #%d: ", I);
		cin >> n;
		int cnt = 0;
		for (int j=0; j<n; ++j) {
			cin >> a[j];
			if (a[j] == j) cnt ++;
		}
		if (cnt >= 1) print(0.6);
		else print(0.4);
	}
	//cout << sum << endl;
	return 0;
}
