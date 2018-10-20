#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define INF (1 << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
#define N 200
int n, m, l;
int T;
LL flow[N], dev[N];
char s[N];
LL con(char *s){
	LL ret = 0;
	FOR(i,0,l)  if (s[i] == '1') ret += (1LL << i);
	return ret;
}
int f(LL x){
	int ret = 0;
	while(x){
		ret++;
		x -= x & -x;
	}
	return ret;
}
int main(){
	scanf("%d", &T);
	FOE(cc,1,T){
		scanf("%d%d", &n, &l);
		FOR(i,0,n){
			scanf("%s", s);
			flow[i] = con(s);
		}
		FOR(i,0,n){
			scanf("%s", s);
			dev[i] = con(s);
		}
		int ans = 200, i = 0;
		FOR(j,0,n){
			int ok = 1;
			LL diff = dev[i] ^ flow[j];
			map<LL, int> mp;
			FOR(k,0,n){
				LL tmp = flow[k] ^ diff;
				if (!mp.count(tmp)) mp[tmp] = 0;
				mp[tmp]++;
			}
			//FOR(k,0,n) printf("%lld ", flow[k] ^ diff); puts("");
			//FOR(k,0,n) printf("%lld ", dev[k]); puts("");
			FOR(k,0,n){
				if (mp.count(dev[k])){
					if (mp[dev[k]]) mp[dev[k]]--;
					else ok = 0;
				}
				else ok = 0;
			}
			if (ok) ans = min(ans, f(diff));
		}
		printf("Case #%d: ", cc);
		if (ans < 200) printf("%d\n", ans);
		else puts("NOT POSSIBLE");

	}
	return 0;
}

