#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define mset(a) memset(a,0,sizeof(a))
#define mmset(a) memset(a,-1,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
const int inf=1e9+7;
const long long linf=1e18;
const double pi=acos(-1.0);
typedef long double lf;
typedef vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
const double eps = 1e-10;
int a[1111];
int main(){
	ios::sync_with_stdio(false);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;cin>>t;
	for (int tt=1;tt<=t;tt++){
		int n;cin>>n;
		for (int i=0;i<n;i++) cin>>a[i];
		int t=0;
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				if (a[i]>a[j]) t++;
		cout<<"Case #"<<tt<<": ";
		if (t>=n-2&&t<=2*n-1) cout<<"BAD"<<endl;else cout<<"GOOD"<<endl;
	}
	return 0;
}