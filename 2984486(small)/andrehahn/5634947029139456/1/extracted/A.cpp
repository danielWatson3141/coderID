#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 160

using namespace std;

typedef long long ll;

int N, L;
ll ini[MAX];
ll fim[MAX];

int testa(ll mask){
	int cnt = 0;
	for(int i = 0; i < L; i++)
		if(mask & (1LL<<i))
			cnt++;
	ll tmp[MAX];
	for(int i = 0; i < N; i++)
		tmp[i] = ini[i]^mask;
	//printf("%lld\n", mask);

	sort(tmp, tmp + N);
	//for(int i = 0; i < N; i++)
	//	printf("%lld %lld\n", tmp[i], fim[i]);

	for(int i = 0; i < N; i++)
		if(tmp[i] != fim[i])
			return 100;
	return cnt;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d %d", &N, &L);
		char tmp[50];
		for(int i = 0; i < N; i++){
			scanf(" %s", tmp);
			ll k = 0;
			for(int j = 0; j < L; j++){
				k = (k << (1LL));
				if(tmp[j] == '1')
					k |= 1;
			}
			ini[i] = k;
		}
		sort(ini, ini+N);
		for(int i = 0; i < N; i++){
			scanf(" %s", tmp);
			ll k = 0;
			for(int j = 0; j < L; j++){
				k = (k << (1LL));
				if(tmp[j] == '1')
					k |= 1;
			}
			fim[i] = k;
		}
		sort(fim, fim+N);

		int cnt = 0;
		for(int i = 0; i < L; i++){
			int zi = 0, oi = 0;
			int zf = 0, of = 0;
			for(int j = 0; j < N; j++){
				if((1LL<<i) & ini[j]) oi++;
				else zi++;
				if((1LL<<i) & fim[j]) of++;
				else zf++;
			}
			if(zi == zf && oi == of) continue;
			if(zi == of && oi == zf){
				cnt++;
				continue;
			}
			cnt = 100;
			break;
		}


		int r = 99;
		if(cnt < 100){
			for(int i = 0; i < N; i++){
				int k = testa(ini[0] ^ fim[i]);
				if(k < r)
					r = k;
			}
		}
		printf ("Case #%d: ", t);
		if(r < 99) printf("%d\n", r);
		else printf("NOT POSSIBLE\n");

	}
	return 0;
}
