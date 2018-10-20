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
#define sz(_v) (int)((_v).size())
#define MOD = 1000000000 + 7

const int INF = 1200000000;

using namespace std;

vector< VI > g;

map<pair<int, int>, int > dyn;
map<pair<int, int>, int > cnt;

int getCnt(int v, int p) {
	pair<int, int> st(v,p);
	if (cnt.count(st))
		return cnt[st];

	int &ans=cnt[st];
	++ans;
	rept(i,sz(g[v])) {
		int to(g[v][i]);
		if (to!=p) {
			ans+=getCnt(to,v);
		}
	}
	return ans;
}

int getDyn(int v, int p) {
	// printf("getDyn %d %d\n",v,p);
	pair<int, int> st(v,p);
	if (dyn.count(st))
		return dyn[st];

	int &ans=dyn[st];
	int cnt(0);
	int sumCnt(0);
	rept(i,sz(g[v])) {
		int to(g[v][i]);
		if (to!=p) {
			++cnt;
			sumCnt+=getCnt(to,v);
		}
	}
	// printf("cnt = %d\n",cnt);
	if (cnt==0)
		return ans=0;
	if (cnt<2)
		return ans=sumCnt;
	ans=INF;
	rept(i,sz(g[v])) {
		int to1(g[v][i]);
		if (to1==p)
			continue;
		int tmp1(getDyn(to1,v));
		int dec1(getCnt(to1,v));
		// printf("tmp1 %d %d\n",to1,tmp1);
		if (tmp1==-1)
			continue;
		for (int j(i+1); j<sz(g[v]); ++j) {
			int to2(g[v][j]);
			if (to2==p)
				continue;
			int tmp2(getDyn(to2,v));
			int dec2(getCnt(to2,v));
			// printf("tmp2 %d %d\n",to2,tmp2);
			if (tmp2==-1)
				continue;
			int curAns(tmp1+tmp2);
			curAns+=sumCnt;
			curAns-=dec1+dec2;
			// printf("curAns %d",curAns);
			ans=min(ans,curAns);
		}
	}
	if (ans==INF)
		ans=-1;
	return ans;
}

void solvePart() {
	int n;
	scanf("%d",&n);
	g.clear();
	g.resize(n);
	dyn.clear();
	cnt.clear();
	rept(i,n-1) {
		int a,b;
		scanf("%d%d",&a,&b);
		--a,--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int ans(-1);
	rept(i,sz(g)) {
		int curAns(getDyn(i,-1));
		// printf("v %d %d\n",i,curAns);
		if (curAns==-1)
			continue;
		if (ans==-1)
			ans=curAns;
		else
			ans=min(ans,curAns);
	}
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
