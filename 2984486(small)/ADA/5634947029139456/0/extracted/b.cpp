#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<utility>	//pair
#include<iostream>
#include<algorithm>
#define MAXN 205
#define INF 0x3f3f3f3f
#define LL long long
#define DBL double
#define EPS 1e-6
#define PI acos(-1.0)
#define Test() cout<<"Test"<<endl;
#define Debug(a) cout<<#a<<" = "<<a<<endl;
#define Debug2(a,b) cout<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<endl;
using namespace std;

LL n, L, a[MAXN], b[MAXN], ca[MAXN], cb[MAXN], c[MAXN], ans;
bool f[MAXN];
void dfs(int dep, LL cnt){
	if(cnt >= ans)
		return ;
	if(dep == L){
		for(int i=0; i<n; i++)
			c[i] = a[i];
		for(int i=0; i<L; i++)
			for(int j=0; j<n; j++)
				if(f[i])
					c[j] ^= ((LL)1<<(L-1-i));
		sort(c, c+n);
		bool g=1;
		for(int i=0; i<n; i++)
			if(c[i]!=b[i]){
				g=0;
				break;
			}
		if(g)
			ans=min(ans, cnt);
		return ;
	}
	if(ca[dep] == cb[dep]){
		f[dep] = 0;
		dfs(dep+1, cnt);
	}
	if(ca[dep] == n-cb[dep]){
		f[dep] = 1;
		dfs(dep+1, cnt+1);
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, it=1;
	cin >> T;
	while(T--){
		
		cin >>n >>L;
		memset(ca, 0, sizeof(ca));
		memset(cb, 0, sizeof(cb));
		memset(f, 0, sizeof(f));
		for(int i=0; i<n; i++){
			string s;
			cin >> s;
			a[i]=0;
			for(int j=0; j<L; j++){
				if(s[j]-'0' == 1) ca[j]++;
				a[i] = a[i]*2+s[j]-'0';
			}
		}
		for(int i=0; i<n; i++){
			string s;
			cin >> s;
			b[i]=0;
			for(int j=0; j<L; j++){
				if(s[j]-'0' == 1) cb[j]++;
				b[i] = b[i]*2+s[j]-'0';
			}
		}
		bool f=1;
		sort(b, b+n);
		ans = INF;
		dfs(0, 0);		
		for(int i=0; i<n; i++)
			if(a[i] != b[i]){
				f=0;
				break;
			}
		printf("Case #%d: ", it++);
		if(ans==INF)
			puts("NOT POSSIBLE");
		else
			printf("%lld\n", ans);
		
	}
	
	return 0;
}


