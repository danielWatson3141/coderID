#include <stdio.h>
#include <string.h>
int n, l;

void readbin(int l, int *x);
void flip(int x, int *a);
int try(int x, int *a, int *b);
int main()
{
	int tot, i, j, t, ans, temp;
	int a[155], b[155];
	scanf("%d", &tot);
	for(i = 1; i <= tot; i++){
		scanf("%d%d", &n, &l);
		for(j = 1; j <= n; j++){
			readbin(l, &a[j]);
		}
		for(j = 1; j <= n; j++){
			readbin(l, &b[j]);
		}
		
		t = 1 << l;
		ans = l + 1;
		for(j = 0; j < t; j++){
			temp = try(j, a, b);
			flip(j, a);
			if(temp < ans ){
				ans = temp;	
			}
		}

		if(ans == l + 1){
			printf("Case #%d: NOT POSSIBLE\n", i);
		}
		else{
			printf("Case #%d: %d\n", i, ans);
		}
	}
	return 0;
}
void readbin(int l, int *x){
	char str[50];
	int sum, i;
	scanf("%s", str);
	sum = 0;
	for(i = 0; i < l; i++){
		if(str[i] == '1'){
			sum += 1;
		}
		sum <<= 1;
	}
	*x = sum >> 1;
}
void flip(int x, int *a){
	int i;
	for(i = 1; i <= n; i++){
		a[i] ^= x;
	}
}
int try(int x, int *a, int *b){
	int s[1025];
	int i, sum;
	flip(x, a);
	memset(s, 0, sizeof(int) * 1025);
	for(i = 1; i <= n; i++){
		s[a[i]] = 1;
	}
	for(i = 1; i <= n; i++){
		if(0 == s[b[i]]){
			return l + 1;
		}
	}
	
	sum = 0;
	while(x != 0){
		sum += (x & 1);
		x >>= 1;
	}

	return sum;

}
