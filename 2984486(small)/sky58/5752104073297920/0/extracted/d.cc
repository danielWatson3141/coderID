#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int a[1010];
int main()
{
	int t,n;
	cin>>t;
	rep(i,t){
		cin>>n;double f=0;
		rep(j,n){
			cin>>a[j];
			if(j>n-2 || a[j]==0) continue;
			int x=(j-a[j]+n-1)%(n-1);
			f+=x;f-=0.5*(n-2);
			cerr<<x-0.5*(n-2)<<endl;
		}
		if(f>0.0) printf("Case #%d: BAD\n",i+1);
		else printf("Case #%d: GOOD\n",i+1);
	}
}
