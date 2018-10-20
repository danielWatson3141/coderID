#include <stdio.h>
#include <string.h>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");
int t;
int a, b;
char p[160][50] = {0,};
char q[160][50] = {0,};
char s[160][50] = {0,};
int ans = 50;
int main(){
	fscanf(input, "%d", &t);
	int tt;
	for(tt = 1; tt <= t; tt++){
		fscanf(input, "%d%d", &a, &b);
		int i, j, k;
		for(i = 0; i < a; i++) fscanf(input, "%s", &p[i]);
		for(i = 0; i < a; i++) fscanf(input, "%s", &q[i]);
		for(i = 0; i < a; i++){
			int c = 0;
			for(j = 0; j < b; j++) if(p[i][j] != q[0][j]) c++;
			for(j = 0; j < a; j++){
				for(k = 0; k < b; k++){
					if(p[i][k] != q[0][k]) s[j][k] = p[j][k] ^ 1;
					else s[j][k] = p[j][k];
				}
			}
			int cc = 0;
			for(j = 0; j < a; j++){
				for(k = 0; k < a; k++){
					if(strcmp(q[j], s[k]) == 0){
						cc++;
						break;
					}
				}
			}
			if(cc == a && c < ans) ans = c;
		}
		fprintf(output, "Case #%d: ", tt);
		if(ans == 50) fprintf(output, "NOT POSSIBLE\n");
		else fprintf(output, "%d\n", ans);
		ans = 50;
		for(i = 0; i < a; i++){
			for(j = 0; j < b; j++){
				p[i][j] = 0;
				q[i][j] = 0;
				s[i][j] = 0;
			}
		}
	}
	return 0;
}