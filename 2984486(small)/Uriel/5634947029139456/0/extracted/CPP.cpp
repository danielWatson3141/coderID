




//#include<math.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//#define N 10010
//#define eps 1e-4
//
//struct point {
//	double x, y, z;
//}p[N];
//
//struct res {
//	double g, val;
//}G[N];
//
//FILE * fp, * fw;
//
//int main() {
//	fp = fopen("trackers97_t001.txt", "r");
//	fw = fopen("res.txt", "w");
//	int i, j, k = 0, n;
//	double r, tp, d1;
//	char s[100];
//	fscanf(fp, "%d", &n);
//	for(i = 0; i < n; ++i) {
//		fscanf(fp, "%s %lf %lf %lf", s, &p[i].x, &p[i].y, &p[i].z);
//		printf("%s %lf %lf %lf", s, p[i].x, p[i].y, p[i].z);
//	}
//	for(r = 1.4; r <= 180; r += 1.0) {
//		G[k].val = r;
//		G[k].g = 0;
//		for(i = 0; i < n; ++i) {
//			for(j = 0; j < n; ++j) {
//				if(i == j) continue;
//				d1 = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) + (p[i].z - p[j].z) * (p[i].z - p[j].z));
//				tp = fabs(r - d1) < eps ? 1 : 0;
//				G[k].g += tp;
//			}
//		}
//		fprintf(fw, "%lf %lf\n", r, G[k].g / (r * r));
//		k++;
//	}
//	fclose(fp);
//	fclose(fw);
//	return 0;
//}



//GCJ Round1A 2014-04-26 A
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct str {
	char s[60];
}p[160], t[160], tp[160];

bool cmp(str a, str b) {
	return strcmp(a.s, b.s) < 0;
}

FILE* fw;

int main() {
//	freopen("in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	fw = fopen("A-s.txt", "w");
	int n, a, cnt, cse, g = 1, i, j, k, min_op, ok, l;
	scanf("%d", &cse);
	while(cse--) {
		scanf("%d %d", &n, &l);
		for(i = 0; i < n; ++i) {
			memset(tp[i].s, 0x00, sizeof(tp[i].s));
			memset(t[i].s, 0x00, sizeof(t[i].s));
			memset(p[i].s, 0x00, sizeof(p[i].s));
		}
		for(i = 0; i < n; ++i) {
			scanf("%s", p[i].s);
		}
		for(i = 0; i < n; ++i) {
			scanf("%s", t[i].s);
		}
		sort(t, t + n, cmp);
		ok = 0;
		min_op = 200;
		for(i = 0; i < (1<<l); ++i) {
//			printf("i=%d\n", 1<<l);
			cnt = 0;
			for(j = 0; j < l; ++j) {
				if(i & (1<<j)) {
					cnt++;
				}
			}
			if(ok && cnt > min_op) continue;
			for(j = 0; j < l; ++j) {
				if(i & (1<<j)) {
					for(k = 0; k < n; ++k) {
						tp[k].s[j] = p[k].s[j] == '1' ? '0' : '1';
					}
				}
				else {
					for(k = 0; k < n; ++k) {
						tp[k].s[j] = p[k].s[j];
					}
				}
			}
			sort(tp, tp + n, cmp);
//			for(j = 0; j < n; ++j) {
//				printf("%s\n", tp[j].s);
//			}
			for(j = 0; j < n; ++j) {
				if(strcmp(t[j].s, tp[j].s)) break;
			}
			if(j == n) {
				ok = 1;
				min_op = cnt;
			}
		}
		if(!ok) fprintf(fw, "Case #%d: NOT POSSIBLE\n", g++);
		else
			fprintf(fw, "Case #%d: %d\n", g++, min_op);
	}
	fclose(fw);
	return 0;
}




