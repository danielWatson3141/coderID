#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#define INT64 long long int

FILE *fp, *fout;
bool table[200];
char org[200][50], cng[200][50], goal[200][50], res[200][50];
unsigned int flipCnt;
INT64 caseCnt;		// <-- if I knew it eariler...
int n, l;
char buf[50];

INT64 custompow(int base, int pow) {
	if (pow == 0)
		return 1;
	else
		return 2*custompow(base, pow-1);
}

void process(INT64 ind) {
	// case over!
	if (ind >= caseCnt) return;

	memset(table, 0, 200);
	INT64 p = custompow(2,l-1);
	INT64 o = ind;
	int k;

	// convert int 2 01010
	int nfCnt = 0;
	for (k=0; k<l; k++) {
		if (o >= p) {
			buf[k] = '1';
			o -= p;
			nfCnt ++;
		} else {
			buf[k] = '0';
		}
		p /= 2;
	}
	buf[l] = 0;

	// if light is over then result...
	if (nfCnt >= flipCnt) {
		process(ind+1);
		return;
	}

	// do custom XOR 2 cng
	memcpy(cng, org, 50*200*sizeof(char));
	int i,j;
/*	for (i=0; i<n; i++)
		printf("%s ", cng[i]);
	printf("\n");
*/
	for (i=0; i<n; i++) {
		for (j=0; j<l; j++) {
			if (buf[j] == '1') {
				cng[i][j] = (cng[i][j]=='0')?'1':'0';
			}
		}
	}
	
	// let me see cnged one ....
	/*for (i=0; i<n; i++) {
		printf("%s ", cng[i]);
	}
	printf("\n");
*/
	// cmp with goal!
	int tot = 0;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (table[j]) continue;
			if (strcmp(cng[i], goal[j])==0) {
				table[j] = true;
				tot++;
				break;
			}
		}
	}

	// if all outlet matches
	if (tot == n) {
		//memcpy(res, cng, sizeof(cng));
		flipCnt = nfCnt;
	}
	
	// move to next
	process(ind+1);
}

/*
int conv(char *b, int v) {
	if (*b == 0)
		return v;
	else
		return conv(b+1, ((*b)-'0') + v*2);
}*/

int main() {
	fp = fopen("1.input", "r");
	fout = fopen("1.output", "w");
	int cc;
	fscanf(fp, "%d", &cc);

	for (int i=0; i<cc; i++) {
		fscanf(fp, "%d %d", &n, &l);
		int j;
		for (j=0; j<n; j++) {
			fscanf(fp, "%s", org[j]);
		//	org[j] = conv(buf, 0);
		}
		for (j=0; j<n; j++) {
			fscanf(fp, "%s", goal[j]);
		//	goal[j] = conv(buf, 0);
		}

		// goal should sorted first
		//std::sort(goal, goal+n);
		
		// init
		flipCnt = 0x7fffffff;
		caseCnt = custompow(2,l);
		process(0);

		if (flipCnt == 0x7fffffff) {
			fprintf(fout, "Case #%d: NOT POSSIBLE\n", i);
		} else {
			fprintf(fout, "Case #%d: %d\n", i, flipCnt);
		}
	}
	
	fclose(fp);
	fclose(fout);
	
	return 0;
}
