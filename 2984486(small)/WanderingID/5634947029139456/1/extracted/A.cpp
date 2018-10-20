#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define out(x) cout<<(#x)<<'='<<x<<endl
typedef long long LL;
LL a[201], b[201];
string s;
void read(LL &x){
	cin>>s;
	x=0;
	REP(i,s.size())
		x|=LL(s[i]=='1')<<i;
}
int main(){
	int T;
	scanf("%d", &T);
	REP(tt, T){
		int n, l;
		set<LL> sll;
		scanf("%d%d", &n, &l);
		REP(i,n)read(a[i]);
		REP(i,n){
			read(b[i]);
			sll.insert(b[i]);
		}
		int ans=-1;
		REP(i,n){
			LL x=a[i]^b[0];
			bool flag=1;
			REP(j,n)if(!sll.count(x^a[j])){flag=0;break;}
			if(flag){
				if(~ans)ans=min(ans, __builtin_popcount(x));
				else ans=__builtin_popcount(x);
			}
		}
		printf("Case #%d: ", tt+1);
		if(~ans)printf("%d\n", ans);
		else puts("NOT POSSIBLE");
	}
}
