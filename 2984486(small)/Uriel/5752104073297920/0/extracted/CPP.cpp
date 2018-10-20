




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

FILE* fw;

int main() {
//	freopen("in", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
	fw = fopen("C-s.txt", "w");
	int n, a, cnt, cse, g = 1, i;
	scanf("%d", &cse);
	while(cse--) {
		scanf("%d", &n);
		cnt = 0;
		for(i = 0; i < n; ++i) {
			scanf("%d", &a);
			if(a == i) cnt++;
		}
		if(cnt >= n / 2) fprintf(fw, "Case #%d: BAD\n", g++);
		else
			fprintf(fw, "Case #%d: GOOD\n", g++);
	}
	fclose(fw);
	return 0;
}




