#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define out(x) cout<<(#x)<<'='<<x<<endl
typedef long long LL;
typedef vector<int> vi;
vector<vi> E;
int ans;
int go(int x, int pre){
	vi &e=E[x];
	vi tmp;
	REP(i,e.size())if(e[i]!=pre)
		tmp.push_back(go(e[i], x));
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	if(tmp.size()>=2)return tmp[0]+tmp[1]+1;
	return 1;
}
int main(){
	int T;
	scanf("%d", &T);
	REP(tt, T){
		int n;
		scanf("%d", &n);
		E.clear();
		E.resize(n);
		REP(i,n-1){
			int x, y;
			scanf("%d%d",&x,&y);
			x--; y--;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		ans=0;
		REP(i,n)ans=max(ans, go(i, -1));
		printf("Case #%d: %d\n", tt+1, n-ans);
	}
}
