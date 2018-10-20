
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char sbuf[200][50], dbuf[200][50];
char *src[200], *dst[200];
int n, l;
int bst;


bool lt(char *a, char *b) {
	return strcmp(a, b) < 0;
}

bool eq(char *a, char *b) {
	return strcmp(a, b) == 0;
}

void dd(int d, int tot) {
	if ( d == l ) {
		if ( tot >= bst ) return;
		sort(src, src + n, lt);
		if ( equal(src, src + n, dst, eq) ) bst = tot;
		return;
	}
	int c0s = 0, c0d = 0;
	for (int i = 0; i < n; ++i) {
		if ( src[i][d] == '0' ) ++c0s;
		if ( dst[i][d] == '0' ) ++c0d;
	}

	if ( c0s == c0d ) {
		dd(d+1, tot);	
	}
	if ( c0s == n - c0d ) {
		for (int i = 0; i < n; ++i) {
			src[i][d] = '1' + '0' - src[i][d];
		}
		dd(d+1, tot+1);
		for (int i = 0; i < n; ++i) {
			src[i][d] = '1' + '0' - src[i][d];
		}
	}
}


void p() {
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; ++i)
		scanf("%s", src[i]);
	for (int i = 0; i < n; ++i)
		scanf("%s", dst[i]);

	sort(dst, dst + n, lt);
	bst = 100;
	dd(0, 0);
	if ( bst == 100 ) {
		printf("NOT POSSIBLE\n");
	} else {
		printf("%d\n", bst);
	}
}

int main() {
	for (int i = 0; i < 200; ++i) {
		src[i] = &sbuf[i][0];
		dst[i] = &dbuf[i][0];
	}
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		p();
	}
	return 0;
}

