#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define L_MAX 50
#define N_MAX 160
using namespace std;
typedef long long ll;

int N, L;
ll bin[L_MAX], pre[L_MAX];
ll reqi[N_MAX], flow[N_MAX];
int numf[L_MAX], numr[L_MAX];

int rec(int lev){
	if(lev < 0) return 0;
	int ret = 100;
	sort(flow, flow + N);
	bool ok = true;
	for(int i = 0; i < N; i++){
		if((flow[i] & pre[lev]) != (reqi[i] & pre[lev])) ok = false;
	}
	if(ok) ret = min(ret, rec(lev - 1));

	for(int i = 0; i < N; i++) flow[i] = (flow[i] ^ bin[lev]);
	sort(flow, flow + N);
	ok = true;
	for(int i = 0; i < N; i++){
		if((flow[i] & pre[lev]) != (reqi[i] & pre[lev])) ok = false;
	}
	if(ok) ret = min(ret, rec(lev - 1) + 1);

	for(int i = 0; i < N; i++) flow[i] = (flow[i] ^ bin[lev]);
	return ret;
}

int main(){
	//freopen("A-large.in", "r", stdin);
	//freopen("pA_la.txt", "w", stdout);
	bin[0] = 1;
	for(int i = 1; i < L_MAX; i++) bin[i] = bin[i - 1] * 2;
	pre[L_MAX - 1] = bin[L_MAX - 1];
	for(int i = L_MAX - 2; i >= 0; i--) pre[i] = pre[i + 1] + bin[i];

	int T;
	scanf("%d", &T);
	for(int cnt = 1; cnt <= T; cnt++){
		printf("Case #%d: ", cnt);
		memset(reqi, 0, sizeof(reqi));
		memset(flow, 0, sizeof(flow));
		memset(numf, 0, sizeof(numf));
		memset(numr, 0, sizeof(numr));
		scanf("%d%d", &N, &L);
		char ipt[L_MAX];
		for(int i = 0; i < N; i++){
			scanf("%s", &ipt);
			for(int j = L - 1; j >= 0; j--){
				flow[i] *= 2;
				flow[i] += ipt[L - j - 1] - '0';
				numf[j] += ipt[L - j - 1] - '0';
			}
		}
		for(int i = 0; i < N; i++){
			scanf("%s", &ipt);
			for(int j = L - 1; j >= 0; j--){
				reqi[i] *= 2;
				reqi[i] += ipt[L - j - 1] - '0';
				numr[j] += ipt[L - j - 1] - '0';
			}
		}

		sort(reqi, reqi + N);
		int ans = rec(L - 1);
		if(ans >= 100) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
	return 0;
}
