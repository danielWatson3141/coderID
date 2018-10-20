#include <stdio.h>
#include <string.h>

FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");

int t;
int a;
int p[1010] = {0,};
int ans = 10000;
int sond[1010] = {0,}; // son_direct
int sont[1010] = {0,}; // son_total
int d[1010] = {0,}; // have to delete
int sond_c[1010] = {0,}; // son_direct copy
int topoch[1010] = {0,};
int topo[1010] = {0,};

void makeroot(int x){
	if(p[x] == -1) return;
	makeroot(p[x]);
	p[p[x]] = x;
}
int main(){
	fscanf(input, "%d", &t);
	int tt;
	for(tt = 1; tt <= t; tt++){
		fscanf(input, "%d", &a);
		int i, j, k, l;
		for(i = 1; i <= a; i++) p[i] = -1;
		for(i = 0; i < a - 1; i++){
			int x, y;
			fscanf(input, "%d%d", &x, &y);
			makeroot(y);
			p[y] = x;
		}
		for(i = 1; i <= a; i++){ // root
			if(p[i] != -1){
				makeroot(p[i]);
				p[p[i]] = i;
				p[i] = -1;
			}
			for(j = 1; j <= a; j++) if(p[j] != -1) { sond[p[j]]++; sond_c[p[j]]++; }
			for(j = 1; j <= a; j++){
				k = j;
				for(;;){
					if(p[k] == -1) break;
					sont[p[k]]++;
					k = p[k];
				}
			}
			for(j = 0; j < a; j++){
				for(k = 1; k <= a; k++){
					if(sond_c[k] == 0 && topoch[k] == 0){
						topo[j] = k;
						if(p[k] != -1) sond_c[p[k]]--;
						topoch[k] = 1;
						break;
					}
				}
			}
			for(j = 0; j < a; j++){
				int x = topo[j];
				if(sond[x] == 0) d[x] = 0;
				if(sond[x] == 1) d[x] = sont[x];
				if(sond[x] > 1){
					int max0 = -1, max1 = -1;
					for(k = 1; k <= a; k++){
						if(p[k] == x){
							d[x] += sont[k] + 1;
							if(sont[k] + 1 - d[k] > max0){
								max1 = max0;
								max0 = sont[k] + 1 - d[k];
							}
							else if(sont[k] + 1 - d[k] > max1) max1 = sont[k] + 1 - d[k];
						}
					}
					d[x] -= max0 + max1;
				}
			}
			if(d[i] < ans) ans = d[i];

			for(j = 0; j <= a; j++){
				sond[j] = 0;
				sont[j] = 0;
				d[j] = 0;
				sond_c[j] = 0;
				topoch[j] = 0;
				topo[j] = 0;
			}
		}
		printf("%d\n", tt);
		fprintf(output, "Case #%d: %d\n", tt, ans);
		ans = 10000;
	}
	return 0;
}