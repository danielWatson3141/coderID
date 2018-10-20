#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define rept(i,n) for (int i(0); i<n; ++i)
#define VI vector<int>
#define pb push_back
#define mp make_pair
#define INF = 1200000000
#define MOD = 1000000000 + 7

using namespace std;

int dyn[45][150][150];
vector<string> from,to;

void doS(vector<string> &s, VI &sw) {
	rept(i,s.size()) {
		rept(j,sw.size()) {
			if (sw[j])
				s[i][j]='0'+(1-(s[i][j]-'0'));
		}
	}
}

void solvePart() {
	int n,m;
	scanf("%d%d\n",&n,&m);
	vector<string> data[2];
	rept(i,2) {
		data[i].resize(n);
		rept(j,n) {
			cin>>data[i][j];
		}
		sort(data[i].begin(),data[i].end());
	}
	from=data[0],to=data[1];
	int ans(-1);
	rept(i,to.size()) {
		VI switches(m);
		int cur(0);
		rept(j,m) {
			if (from[0][j]!=to[i][j])
				switches[j]=1,++cur;
			else
				switches[j]=0;
		}
		vector<string> tmp(n);
		rept(j,tmp.size())
			tmp[j]=data[1][j];
		doS(tmp, switches);
		sort(tmp.begin(), tmp.end());
		bool ok(true);
		rept(j,n)
			if (tmp[j]!=data[0][j])
				ok=false;
		if (ok)
			if (ans==-1)
				ans=cur;
			else
				ans=min(cur,ans);
	}
	if (ans==-1)
		puts("NOT POSSIBLE");
	else
		printf("%d\n",ans);
}

void solve() {
	int tst;
	scanf("%d",&tst);
	rept(t,tst) {
		printf("Case #%d: ",t+1);
		solvePart();
	}
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	solve();
}
