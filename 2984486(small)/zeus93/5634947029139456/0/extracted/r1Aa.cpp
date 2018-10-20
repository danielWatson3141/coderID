#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 15
#define L 15

int v1[N];
int v2[N];
int v3[N];

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int num[1 << L];
void init(){
	for(int i = 0; i < 1 << L; i++){
		int sum = 0;
		for(int j = 0; j < L; j++){
			if(i & (1 << j)){
				sum++;
			}
			num[i] = sum;
		}
	}
}
int get(char *s, int l){
	int ans = 0;
	for(int i = 0; i < l; i++){
		ans *= 2;
		ans += (s[i] - '0');
	}
	return ans;
}
int main(){
	init();
	int t, icase = 0;
	char s[L];
	scanf("%d", &t);
	while(t--){
		int n, l, sum;
		scanf("%d%d", &n, &l);
		for(int i = 0; i < n; i++){
			scanf("%s", s);
			v1[i] = get(s, l);
		}
		for(int i = 0; i < n; i++){
			scanf("%s", s);
			v2[i] = get(s, l);
		}
		qsort(v2, n, sizeof(int), cmp);
		int ans = l + 1;
		bool flag = false;
		for(int i = 0; i < 1 << l; i++){
			for(int k = 0; k < n; k++){
				v3[k] = v1[k];
			}
			for(int j = 0; j < l; j++){
				if(i &( 1 << j)){
					for(int k = 0; k < n; k++){
						v3[k] ^= (1 << j);
					}
				}
			}
			qsort(v3, n, sizeof(int), cmp);
			int j;
			for(j = 0; j < n; j++){
				if(v3[j] != v2[j]){
					break;
				}
			}
			if(j == n){
				flag = true;
				ans = min(ans, num[i]);
			}
		}
		if(flag){
			printf("Case #%d: %d\n", ++icase, ans);
		}
		else{
			printf("Case #%d: NOT POSSIBLE\n", ++icase);
		}
	}
	return 0;
}

