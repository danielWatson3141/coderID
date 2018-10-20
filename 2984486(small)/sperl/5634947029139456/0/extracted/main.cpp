#include <stdio.h>

#include <map>

#define N_MAX 151
#define ll long long


ll devices[N_MAX];
ll outlets[N_MAX];

ll results[N_MAX];

int N;
int L;

ll field[N_MAX][N_MAX];

int getOnes(ll num) {
	int res = 0;
	for (int i = 0; i < L; i++) {
		if ((num & (1<<i)) != 0) {
			res++;
		}
	}
	return res;
}

int main() {
	
	int T = 0;
	scanf("%d\n", &T);

	for (int t = 1; t <= T; t++)  {
		scanf("%d %d\n", &N, &L);
		for (int i = 0; i < N; i++) {
			ll number = 0;
			for (int j = 0; j < L; j++) {
				char bit;
				scanf("%c", &bit);
				
				number = number << 1;
				if (bit == '0') {
				}
				else if (bit == '1') {
					number |= 1;
				}
				else {
					printf("error1 %d %d %d\n", i, j, t);
				}
			}
			if (i != N-1)
				scanf(" ");	
			outlets[i] = number;
		}
		scanf("\n");
		for (int i = 0; i < N; i++) {
			ll number = 0;
			for (int j = 0; j < L; j++) {
				char bit;
				scanf("%c", &bit);
				 
				number = number << 1;
				if (bit == '0') {
				}
				else if (bit == '1') {
					number |= 1;
				}
				else {
					printf("error2 %d %d %d\n", i, j, t);
				}
			}
			if (i != N-1)
				scanf(" ");	
			devices[i] = number;
		}
		scanf("\n");
		
		std::map<ll,int> valMap;
	
		std::map<ll, int>::iterator it;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ll val = devices[i]^outlets[j];
				it = valMap.find(val);
				int count = 1;
				if (it != valMap.end()) {
					count += it->second;
					valMap.erase(it);
				}
					valMap.insert( std::pair<ll, int>(val, count));			
			}
		}
		
		int min = -1;
		
		for (it=valMap.begin(); it!=valMap.end(); ++it) {
			if(it->second == N) {
				int ones = getOnes(it->first);
				//printf("sol = %lld, %d\n", it->first, it->second);
				if (min == -1 || ones < min) {
					min = ones;
				}
			}
		}
		
		printf("Case #%d: ", t);
		
		if (min == -1) {
			printf("NOT POSSIBLE\n");
		}
		else {
			printf("%d\n", min);
		}
	}
}


