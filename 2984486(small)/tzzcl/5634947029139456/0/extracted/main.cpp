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
int n,l;
string a[155];
string b[155];
string c[155];
set<string> ans;
int now[222];
int main(){
	ios::sync_with_stdio(false);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;cin>>t;
	for (int tt=1;tt<=t;tt++){
		cin>>n>>l;
		int answ=1e9;
		for (int i=0;i<n;i++) cin>>a[i];
		ans.clear();
		for (int i=0;i<n;i++) cin>>b[i],ans.insert(b[i]);
		for (int i=0;i<n;i++)
			for (int j=i;j<n;j++)
			{
				int cnt=0;
				for (int k=0;k<l;k++)
					if (a[i][k]!=b[j][k]) now[cnt++]=k;
				for (int k=0;k<n;k++)
					c[k]=a[k];
				for (int k=0;k<n;k++)
					for (int p=0;p<cnt;p++)
						if (c[k][now[p]]=='0')c[k][now[p]]='1';
						else c[k][now[p]]='0';
				set<string> temp(c,c+n);
				if (temp==ans) answ=min(answ,cnt);
			}
		cout<<"Case #"<<tt<<": ";
		if (answ==1e9) cout<<"NOT POSSIBLE"<<endl;
		else cout<<answ<<endl;
	}
	return 0;
}