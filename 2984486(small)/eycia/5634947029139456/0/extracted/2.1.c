#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int res, n, l;
int l1[200], l2[200];
bool v[200];
int f[200];

int test(int n) 
{ 
    n = (n&0x55555555) + ((n>>1)&0x55555555); 
    n = (n&0x33333333) + ((n>>2)&0x33333333); 
    n = (n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f); 
    n = (n&0x00ff00ff) + ((n>>8)&0x00ff00ff); 
    n = (n&0x0000ffff) + ((n>>16)&0x0000ffff); 
  
    return n; 
}

void docheck() {
	int i, j;
	int t = l1[0] ^ l2[f[0]];
	for (i = 1; i < n; i++) {
		j = l1[i] ^ l2[f[i]];
		if (j != t) {
			return;
		}
	}
	t = test(t);
	if (t < res) {
		res = t;
	}
}

void tt(int k) {
	int i;
	if (k == n) {
		docheck();
		return;
	}
	for (i = 0; i < n; i++) {
		if (!v[i]) {
			f[k] = i;
			v[i] = true;
			tt(k+1);
			v[i] = false;
		}
		
	}
}

int tobin(char *s) {
	int i;
	int k = 0;
	for (i = 0; i < strlen(s); i++) {
		k *= 2;
		if (s[i] == '1') {
			k += 1;
		}
	}
	return k;
}

int main() {
	int t, k, i, j;
	char s[45];
	
	scanf("%d", &t);
	for (k = 1; k <= t; k++) {
		scanf("%d %d", &n, &l);
		res = 30000;
		for (i = 0; i < n; i++) {
			scanf("%s", &s);
			l1[i] = tobin(s);
		}
		for (i = 0; i < n; i++) {
			scanf("%s", &s);
			l2[i] = tobin(s);
		}
		tt(0);
		if (res == 30000) {
			printf("Case #%d: NOT POSSIBLE\n", k);
		}else{
			printf("Case #%d: %d\n", k, res);
		}
	}
}