#include <iostream>
#include <algorithm>

using namespace std;

int a[200], b[200];
int x[200];
char c[200];

int main() {
	int T;
	scanf("%d", &T);
	for (int i=1; i<=T; i++) {
		int n, l;
		scanf("%d %d", &n, &l);
		for (int j=0; j<n; j++) {
			a[j] = 0;
			scanf("%s", c);
			for (int k=0; k<l; k++)	a[j] = (a[j]<<1) + c[k]-'0';
		}
		for (int j=0; j<n; j++) {
			b[j] = 0;
			scanf("%s", c);
			for (int k=0; k<l; k++)	b[j] = (b[j]<<1) + c[k]-'0';
		}
		sort(b,b+n);
		int out = 99999;
		for (int j=0; j<n; j++) {
	//		cout << "j = " << j << endl;
			for (int k=0; k<n; k++) {
				x[k] = a[j]^a[k]^b[0];
	//			cout << x[k] << endl;
			}
			sort(x, x+n);
			bool boo = true;
			for (int k=0; k<n; k++) {
				if (x[k] != b[k]) {
					boo = false;
					break;
				}
			}
			if (boo) {
				int t = a[j]^b[0], cnt=0;
				while (t>0) {
					cnt += t%2;
					t >>= 1;
				}
				if (cnt < out) out = cnt;
			}
		}
		printf("Case #%d: ", i);
		if (out == 99999) printf("NOT POSSIBLE\n");
		else printf("%d\n", out);
	}
	return 0;
}
